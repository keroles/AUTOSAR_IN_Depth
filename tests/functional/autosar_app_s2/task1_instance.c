/**
 * @file autosar_app_s2/task1_instance.c
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

/*Instance of task t1*/

#include "Os.h"

DeclareApplication(INVALID_OSAPPLICATION);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	ApplicationType result_app_1;
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(1);
	result_app_1 = GetApplicationID(); 
	SCHEDULING_CHECK_AND_EQUAL_INT(1, INVALID_OSAPPLICATION, result_app_1);
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_1 = TerminateApplication(NO_RESTART);
	SCHEDULING_CHECK_AND_EQUAL_INT(2, E_OS_CALLEVEL, result_inst_1);
	
}

/*create the test suite with all the test cases*/
TestRef AutosarAPPTest_seq2_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarAPPTest,"AutosarAPPTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarAPPTest;
}

/* End of file autosar_app_s2/task1_instance.c */
