/**
 * @file ioc_s3/task1_instance.c
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

#include "ioc_types.h"
/*#include "test_hal.h"*/
#include "tpl_os.h"

DeclareTask(t2);
DeclareTask(INVALID_TASK);

#define TEST_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
char strTestFixtureName[]="test_t1_instance";
char strTestCallerName[]="TaskManagementTest_sequence3";
#define TEST_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define APP_Task_t1_START_SEC_CODE
#include "tpl_memmap.h"

static void test_t1_instance(void)
{
  Std_ReturnType  result_inst_1, result_inst_2, result_inst_3, result_inst_5, result_inst_6, result_inst_7, result_inst_8,
                  result_inst_10, result_inst_11, result_inst_12;
  StatusType result_inst_4, result_inst_9, result_inst_13;

  TestType1 data1 = 0x01;
  TestType2 data2;
  data2.a=0x01;
  data2.b=0x02;

  /* test SendGroup */
  SCHEDULING_CHECK_INIT(1);
  result_inst_1 = IocSendGroup_ioc1(data1, &data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(1,IOC_E_OK, result_inst_1);

  SCHEDULING_CHECK_INIT(2);
  data1=0x02;
  data2.a=0x03;
  data2.b=0x04;
  result_inst_2 = IocSendGroup_ioc1(data1, &data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(2,IOC_E_OK, result_inst_2);

  SCHEDULING_CHECK_INIT(3);
  data1=0x03;
  data2.a=0x05;
  data2.b=0x06;
  result_inst_3 = IocSendGroup_ioc1(data1, &data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(3,IOC_E_OK, result_inst_3);

  SCHEDULING_CHECK_INIT(4);
  result_inst_4 = ActivateTask(t2);
  SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_4);

  /* test SendGroup overflow */
  SCHEDULING_CHECK_INIT(10);
  data1=0x01;
  data2.a=0x01;
  data2.b=0x02;
  result_inst_5 = IocSendGroup_ioc1(data1, &data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(10,IOC_E_OK, result_inst_5);

  SCHEDULING_CHECK_INIT(11);
  data1=0x02;
  data2.a=0x03;
  data2.b=0x04;
  result_inst_6 = IocSendGroup_ioc1(data1, &data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(11,IOC_E_OK, result_inst_6);

  SCHEDULING_CHECK_INIT(12);
  data1=0x03;
  data2.a=0x05;
  data2.b=0x06;
  result_inst_7 = IocSendGroup_ioc1(data1, &data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(12,IOC_E_OK, result_inst_7);

  SCHEDULING_CHECK_INIT(13);
  data1=0x04;
  data2.a=0x07;
  data2.b=0x08;
  result_inst_8 = IocSendGroup_ioc1(data1, &data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(13,IOC_E_LIMIT, result_inst_8);

  SCHEDULING_CHECK_INIT(14);
  result_inst_9 = ActivateTask(t2);
  SCHEDULING_CHECK_AND_EQUAL_INT(17,E_OK, result_inst_9);

  SCHEDULING_CHECK_INIT(18);
  result_inst_10 = IocEmptyQueue_ioc1();
  SCHEDULING_CHECK_AND_EQUAL_INT(18,IOC_E_OK, result_inst_10);

  SCHEDULING_CHECK_INIT(19);
  data1=0x01;
  data2.a=0x01;
  data2.b=0x02;
  result_inst_11 = IocSendGroup_ioc1(data1, &data2);
  SCHEDULING_CHECK_AND_EQUAL_INT(19,IOC_E_OK, result_inst_11);

  SCHEDULING_CHECK_INIT(20);
  result_inst_12 = IocEmptyQueue_ioc1();
  SCHEDULING_CHECK_AND_EQUAL_INT(20,IOC_E_OK, result_inst_12);

  SCHEDULING_CHECK_INIT(21);
  result_inst_13 = ActivateTask(t2);
  SCHEDULING_CHECK_AND_EQUAL_INT(23,E_OK, result_inst_13);






  SCHEDULING_CHECK_STEP(24);

}

#define APP_Task_t1_STOP_SEC_CODE
#include "tpl_memmap.h"


#define TEST_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture(strTestFixtureName,test_t1_instance)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest,strTestCallerName,NULL,NULL,fixtures);
#define TEST_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define APP_Task_t1_START_SEC_CODE
#include "tpl_memmap.h"

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq3_t1_instance(void)
{
/*
  EMB_UNIT_TESTFIXTURES(fixtures) {
    new_TestFixture(strTestFixtureName,test_t1_instance)
  };
  EMB_UNIT_TESTCALLER(TaskManagementTest,strTestCallerName,NULL,NULL,fixtures);
*/
  return (TestRef)&TaskManagementTest;
}

#define APP_Task_t1_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file ioc_s3/task1_instance.c */
