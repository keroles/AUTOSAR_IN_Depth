/**
 * @file tasks_s2/task2_instance.c
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

/*Instance of task t2*/

#include "Os.h"

DeclareSpinlock(spin0);
DeclareSpinlock(sync);
DeclareTask(chain);

static void test_t2_instance(void)
{
  StatusType r1, r2, r3;

  SCHEDULING_CHECK_INIT(1);
  r1 = GetSpinlock(spin0);
  SCHEDULING_CHECK_AND_EQUAL_INT(1, E_OK, r1);

  SCHEDULING_CHECK_INIT(2);
  r2 = TerminateTask();
  SCHEDULING_CHECK_AND_EQUAL_INT(2, E_OS_SPINLOCK, r2);

  SCHEDULING_CHECK_INIT(3);
  r3 = ChainTask(chain);
  SCHEDULING_CHECK_AND_EQUAL_INT(3, E_OS_SPINLOCK, r3);

  SyncAllCores(sync);

  while(1); /* Wait for the tp watchdog to kill this task */
}

TestRef t2_instance(void)
{
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture("test_t2_instance",test_t2_instance)
  };
  EMB_UNIT_TESTCALLER(testCall,"mc_taskTermination_s1",NULL,NULL,fixtures);
  return (TestRef)&testCall;
}

/* End of file tasks_s2/task2_instance.c */
