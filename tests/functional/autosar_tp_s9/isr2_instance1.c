/**
 * @file autosar_tp_s9/isr2_instance1.c
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


/*Instance 1 of ISR2 isr2*/

#include "Os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_isr2_instance1(void)
{
  SCHEDULING_CHECK_STEP(10);
  
}

/*create the test suite with all the test cases*/
TestRef AutosarTPTest_seq9_isr2_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr2_instance1",test_isr2_instance1)
	};
	EMB_UNIT_TESTCALLER(AutosarTPTest,"AutosarTPTest_sequence9",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTPTest;
}


/* End of file autosar_tp_s9/isr2_instance1.c */
