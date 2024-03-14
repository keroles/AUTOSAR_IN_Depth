/**
 * @file interrupts_s5/interrupts_s5.c
 *
 * @section desc File description
 *
 * @section copyright Copyright
 *
 * Trampoline Test Suite
 *
 * Trampoline Test Suite is copyright (c) IRCCyN 2005-2007
 * Trampoline Test Suite is protected by the French intellectual property law.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os.h"

TestRef InterruptProcessingTest_seq5_t1_instance(void);
TestRef InterruptProcessingTest_seq5_t2_instance(void);
TestRef InterruptProcessingTest_seq5_isr1_instance1(void);
TestRef InterruptProcessingTest_seq5_isr1_instance2(void);
TestRef InterruptProcessingTest_seq5_isr1_instance3(void);

StatusType instance_isr1 = 0;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(InterruptProcessingTest_seq5_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	addFailure("instance error", __LINE__, __FILE__);
	TestRunner_runTest(InterruptProcessingTest_seq5_t2_instance());
}

ISR(softwareInterruptHandler0)
{	
	instance_isr1++;
	switch (instance_isr1)
	{
		case 1:
		{
			TestRunner_runTest(InterruptProcessingTest_seq5_isr1_instance1());	
			break;
		}
		case 2:
		{
			TestRunner_runTest(InterruptProcessingTest_seq5_isr1_instance2());	
			break;
		}
		case 3:
		{
			TestRunner_runTest(InterruptProcessingTest_seq5_isr1_instance3());	
			break;
		}
		default:
		{
			addFailure("instance error", __LINE__, __FILE__);
			break;
		}
	}
	
}
UNUSED_ISR(softwareInterruptHandler1)
UNUSED_ISR(softwareInterruptHandler2)

/* End of file interrupts_s5/interrupts_s5.c */
