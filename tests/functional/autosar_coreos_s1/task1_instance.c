/**
 * @file autosar_coreos_s1/task1_instance.c
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

DeclareAlarm(Alarm_ActivateTask);
DeclareAlarm(Alarm_SetEvent_suspendedtask);
DeclareAlarm(Alarm_IncrementCounter);
DeclareCounter(Software_Counter);
DeclareCounter(Software_Counter_By_Alarm);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13;
	TickType TickType_inst_1, TickType_inst_2, TickType_inst_3;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = GetCounterValue(Software_Counter, &TickType_inst_1);	
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(1,E_OK, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,0, TickType_inst_1);

	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = SetRelAlarm(Alarm_ActivateTask, 2, 0);	
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK, result_inst_2);	
		
	SCHEDULING_CHECK_INIT(3);
	result_inst_3 = IncrementCounter(Software_Counter);	
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_3);

	SCHEDULING_CHECK_INIT(4);
	result_inst_4 = IncrementCounter(Software_Counter);	
	/* alarm expiration */
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_4);
	/* force scheduling */
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_5 = SetRelAlarm(Alarm_SetEvent_suspendedtask, 2, 0);	
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK, result_inst_5);	
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_6 = IncrementCounter(Software_Counter);	
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OK, result_inst_6);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_7 = IncrementCounter(Software_Counter);
	/*alarm expires*/
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_7);
	
	/*force rescheduling*/
	
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_8 = GetCounterValue(Software_Counter_By_Alarm, &TickType_inst_2);	
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(10,E_OK, result_inst_8);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,0, TickType_inst_2);
		
	SCHEDULING_CHECK_INIT(11);
	result_inst_9 = SetRelAlarm(Alarm_IncrementCounter, 2, 0);	
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK, result_inst_9);	
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_10 = IncrementCounter(Software_Counter);	
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OK, result_inst_10);
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_11 = IncrementCounter(Software_Counter);
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OK, result_inst_11);
		
	SCHEDULING_CHECK_INIT(14);
	result_inst_12 = GetCounterValue(Software_Counter_By_Alarm, &TickType_inst_3);	
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(14,E_OK, result_inst_12);
	SCHEDULING_CHECK_AND_EQUAL_INT(14,1, TickType_inst_3);
	
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_13 = SetRelAlarm(Alarm_ActivateTask, 0, 0);	
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OS_VALUE, result_inst_13);	
	
	
}

/*create the test suite with all the test cases*/
TestRef AutosarCOREOSTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarCOREOSTest,"AutosarCOREOSTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarCOREOSTest;
}

/* End of file autosar_coreos_s1/task1_instance.c */
