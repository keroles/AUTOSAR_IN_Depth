/**
 * @file com_internal_s3/comcallback_instance.c
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

/*Instance of comcallback routine*/

#include "tpl_os.h"

DeclareMessage(rm_comcallback);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_comcallback_instance(void)
{
	StatusType result_inst_1;
	StatusType received_char;
	
	/*not allowed !!! Should be E_OS_CALLEVEL*/
	SCHEDULING_CHECK_INIT(10);
	result_inst_1 = ReceiveMessage(rm_comcallback, &received_char); 
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(10,E_OK, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,(int)('3'), (int)received_char);
	
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq3_comcallback_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_comcallback_instance",test_comcallback_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}

/* End of file com_internal_s3/comcallback_instance.c */
