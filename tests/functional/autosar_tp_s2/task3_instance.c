/**
 * @file autosar_tp_s2/task3_instance.c
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


/*Instance of task t3*/

#include "Os.h"

DeclareEvent(t3_event1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t3_instance(void)
{
	StatusType result_inst_1, result_inst_2;
  
  SCHEDULING_CHECK_INIT(1);
	result_inst_1 = WaitEvent(t3_event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK, result_inst_1);
  
  SCHEDULING_CHECK_INIT(12);
	result_inst_2 = ClearEvent(t3_event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OK, result_inst_2);
  
  while(1); /* --> ProtectionHook */
	
}

/*create the test suite with all the test cases*/
TestRef AutosarTPTest_seq2_t3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t3_instance",test_t3_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarTPTest,"AutosarTPTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTPTest;
}


/* End of file autosar_tp_s2/task3_instance.c */
