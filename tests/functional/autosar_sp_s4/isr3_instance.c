/**
 * @file autosar_sp_s4/isr3_instance.c
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
 * as published by the Free Softwarisr3e Foundation; version 2
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


/*Instance of task isr1*/

#include "Os.h"
#include "tpl_as_isr.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_isr3_instance(void)
{
	SCHEDULING_CHECK_STEP(4);
}

/*create the test suite with all the test cases*/
TestRef AutosarSPTest_seq4_isr3_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr3_instance",test_isr3_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSPTest,"AutosarSPTest_sequence4",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSPTest;
}

/* End of file autosar_sp_s4/isr3_instance.c */
