/**
 * @file tasks_s2/tasks_s2.c
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
/* ----------------------------------------------------------------------------
 * Verification tags
 * ----------------------------------------------------------------------------
 * {...}      : Verified by tests numbers (...)
 * NoTimeout  : Verified if the execution did not timeout
 * NoErr      : If a failure has not been reached
 * Internal   : Cannot be tested here. Need to look at the code directly
 * Trivial    : No need to be tested
 * Goil       : Tested by Goil's Checks section
 * TODO       : Test not written
 */
/* --------------------------------------------------------------------------
 *  Requirement  | Short description                  | Verification
 * --------------------------------------------------------------------------
 * SWS_Os_00648  | OS Provides a Spinlock mechanisme  | Trivial
 * SWS_Os_00649  | GetSpinlock service                | {9,19,20}
 * SWS_Os_00650  | GetSpinlock callable from Tasks    | {1}
 * SWS_Os_00651  | GetSpinlock callable from ISRS2    | {14}
 * SWS_Os_00652  | TryToGetSpinlock service           | {7,8,11,12}
 * SWS_Os_00653  | TTGS callable from Tasks           | {7,8}
 * SWS_Os_00654  | TTGS callable from ISRS2           | {17,18}
 * SWS_Os_00655  | ReleaseSpinlock service            | {4,14}
 * SWS_Os_00656  | ReleaseSpinlock callable from Tasks| {4,14}
 * SWS_Os_00657  | ReleaseSpinlock callable from ISRS2| {16,17,18}
 * SWS_Os_00658  | Error if trying to get a spinlock  | {1,2}
 *               | that already belongs to the calling|
 *               | core from a task                   |
 * SWS_Os_00659  | Error if trying to get a spinlock  | {14,15}
 *               | that already belongs to the calling|
 *               | core from an isrs2                 |
 * SWS_Os_00660  | Define an unique order in which a  | Goil
 *               | core can take spinlocks            |
 * SWS_Os_00661  | Error if trying to get a spinlock  | {3,4}
 *               | that is not the successor of a     |
 *               | spinlock the core already occupies |
 */

#include "tpl_os.h"

TestRef t1_instance(void);
TestRef t2_instance(void);
TestRef isr_instance(void);

int main(void)
{
#if NUMBER_OF_CORES > 1
  StatusType rv;

  switch(GetCoreID())
  {
    case OS_CORE_ID_MASTER :
      TestRunner_start();
      SyncAllCores_Init();
      StartCore(OS_CORE_ID_1, &rv);
      if(rv == E_OK)
        StartOS(OSDEFAULTAPPMODE);
      break;
    case OS_CORE_ID_1 :
      StartOS(OSDEFAULTAPPMODE);
      break;
    default :
      /* Should not happen */
      break;
  }
#else
# error "This is a multicore example. NUMBER_OF_CORES should be > 1"
#endif
  return 0;
}

FUNC(ProtectionReturnType, OS_CODE) ProtectionHook(
  VAR(StatusType, AUTOMATIC) FatalError)
{
  sendSoftwareIt(1, SOFT_IRQ0); /* Call the core1's ISR0 */
  return PRO_TERMINATETASKISR;
}

void ShutdownHook(StatusType error)
{
  switch(GetCoreID())
  {
    case OS_CORE_ID_MASTER :
      TestRunner_end();
      break;
    default :
      while(1); /* Slave cores wait here */
      break;
  }
}

ISR(softwareInterruptHandler0_Core1)
{
  TestRunner_runTest(isr_instance());
}

UNUSED_ISR(softwareInterruptHandler0_Core0)
UNUSED_ISR(softwareInterruptHandler1_Core0)
UNUSED_ISR(softwareInterruptHandler1_Core1)
UNUSED_ISR(softwareInterruptHandler2_Core0)
UNUSED_ISR(softwareInterruptHandler2_Core1)

TASK(t1)
{
  TestRunner_runTest(t1_instance());
  ShutdownOS(E_OK);
}

TASK(t2)
{
  TestRunner_runTest(t2_instance());
  ShutdownOS(E_OK);
}

/* End of file tasks_s2/tasks_s2.c */
