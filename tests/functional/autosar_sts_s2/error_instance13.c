/**
 * @file autosar_sts_s2/error_instance13.c
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

/*Instance 13 of error*/

#include "Os.h"

DeclareScheduleTable(sched_implicit);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_error_instance13(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(28);
	result_inst_1 = OSErrorGetServiceId();
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(28,sched_implicit, OSError_StartScheduleTableRel_ScheduleTableID());
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(28,1 , OSError_StartScheduleTableRel_offset());
	SCHEDULING_CHECK_AND_EQUAL_INT(28,OSServiceId_StartScheduleTableRel, result_inst_1);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarSTSTest_seq2_error_instance13(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance13",test_error_instance13)
	};
	EMB_UNIT_TESTCALLER(AutosarSTSTest,"AutosarSTSTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTSTest;
}

/* End of file autosar_sts_s2/error_instance13.c */
