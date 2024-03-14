/**
 * @file com_internal_s1_non/comerror_instance1.c
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

/*Instance 1 of com error*/

#include "tpl_os.h"
#include "tpl_com_error.h" /*for COMErrorGetServiceId()*/

DeclareMessage(sm);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_comerror_instance1(void)
{
	StatusType result_inst_1, result_inst_2;
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_1 = COMErrorGetServiceId();
	SCHEDULING_CHECK_AND_EQUAL_INT(2,COMServiceId_GetMessageStatus , result_inst_1);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_2 = COMError_GetMessageStatus_Message();
	SCHEDULING_CHECK_AND_EQUAL_INT(3,sm , result_inst_2);
	
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq1_comerror_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_comerror_instance1",test_comerror_instance1)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}

/* End of file com_internal_s1_non/comerror_instance1.c */
