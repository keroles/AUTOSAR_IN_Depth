#include "stm32f3xx.h"
#include "mcp23s17.h"
#include "pinAccess.h"
#include "tft.h"

void setupIOExtender()
{
    ioExt.begin();
    //portA => leds.
    for(int i=0; i<8;i++)
        ioExt.pinMode(mcp23s17::PORTA,i,mcp23s17::OUTPUT);
    //portB => push buttons and switches
    for(int i=0; i<8;i++)
        ioExt.pinMode(mcp23s17::PORTB,i,mcp23s17::INPUT_PULLUP);
    ioExt.attachInterrupt(mcp23s17::PORTB,4);
    ioExt.attachInterrupt(mcp23s17::PORTB,5);
    ioExt.attachInterrupt(mcp23s17::PORTB,6);
    ioExt.attachInterrupt(mcp23s17::PORTB,7);
}

#include "stm32f1xx.h"  // Make sure this include path is correct for the STM32F1 HAL or CMSIS headers

void setupTimer()
{
    // Timer TIM6 INIT
    RCC->APB1ENR |= RCC_APB1ENR_TIM6EN; // Enable clock for TIM6
    asm volatile ("nop"); // Insert a NOP for allowing the clock to stabilize
    // Mandatory reset of TIM6 (not strictly necessary for all applications, but good practice to ensure the timer starts from a known state)
    RCC->APB1RSTR |= RCC_APB1RSTR_TIM6RST; // Set the reset bit for TIM6
    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM6RST; // Clear the reset bit for TIM6
    asm volatile ("nop"); // Insert another NOP for good measure after the reset

    TIM6->PSC = 64 - 1; // Prescaler to achieve a 1us tick rate, adjust this value based on your clock settings
    TIM6->EGR |= TIM_EGR_UG; // Generate an update event to reload the prescaler value immediately
    TIM6->CR1 |= TIM_CR1_CEN; // Enable TIM6
}

void resetTimer()
{
    TIM6->CNT = 0;
}

uint32_t getTimerValue()
{
   return TIM6->CNT;
}

void initCoroBoard()
{
//	Tft.setup();
//	setupIOExtender();
	setupTimer();
//	pinMode(GPIOB,0,OUTPUT);	//user led is PB0
}

