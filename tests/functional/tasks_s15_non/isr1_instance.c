/**
 * @file tasks_s15_non/isr1_instance.c
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

/*Instance of isr1*/

#include "tpl_os.h"

DeclareTask(t1);
DeclareTask(t2);
DeclareTask(t3);
DeclareTask(t4);
DeclareTask(t5);
DeclareTask(t6);
DeclareTask(t7);
DeclareTask(t8);
DeclareTask(INVALID_TASK);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_isr1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_15, result_inst_17, result_inst_19;
	TaskStateType result_inst_14, result_inst_16;
	TaskType result_inst_18;
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_1 = ActivateTask(INVALID_TASK);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OS_ID, result_inst_1);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_2 = ActivateTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK , result_inst_2); 
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_3 = ActivateTask(t3);
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OK , result_inst_3); 
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_4 = ActivateTask(t4);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK , result_inst_4); 
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_5 = ActivateTask(t5);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK , result_inst_5); 
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_6 = ActivateTask(t6);
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OK , result_inst_6); 
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_7 = ActivateTask(t7);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK , result_inst_7); 
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_8 = ActivateTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK , result_inst_8); 
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_9 = ActivateTask(t3);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OK , result_inst_9); 
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_10 = ActivateTask(t4);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK , result_inst_10); 
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_11 = ActivateTask(t1);
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OS_LIMIT , result_inst_11); 
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_12 = ActivateTask(t5);
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OS_LIMIT , result_inst_12); 
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_13 = ActivateTask(t8);
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OS_LIMIT , result_inst_13); 
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_15 = GetTaskState(INVALID_TASK, &result_inst_14);
	SCHEDULING_CHECK_AND_EQUAL_INT(15,E_OS_ID , result_inst_15);
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_17 = GetTaskState(t8, &result_inst_16);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(16,WAITING , result_inst_16); 
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OK , result_inst_17);
	
	SCHEDULING_CHECK_INIT(17);
	result_inst_19 = GetTaskID(&result_inst_18);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(17,INVALID_TASK , result_inst_18);
	SCHEDULING_CHECK_AND_EQUAL_INT(17,E_OK , result_inst_19); 
	
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq16_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence16",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}

/* End of file tasks_s15_non/isr1_instance.c */
