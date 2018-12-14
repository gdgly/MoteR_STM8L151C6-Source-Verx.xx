/***********************************************************************/
/*  FILE        :Motor_eeprom.c                                        */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/

#include  <iostm8l151c6.h>			// CPU型号 
#include "Pin_define.h"		// 管脚定义
#include "initial.h"		// 初始化  预定义
#include "ram.h"		// RAM定义
#include "adf7021.h"		// 初始化ADF7021
#include "eeprom.h"		// eeprom
#include "uart.h"		// uart
#include "Motor_uart.h"		// Motor_uart
#include "LED.h"		// led



void Motor_eeprom_load(void)
{
  UINT8 i,j,xm;
  
    for(i=0;i<def_MODE_B;i++)
    {
       xm = ReadByteEEPROM( addr_eeprom_sys+addr_eeprom_MOTOR+i );
       if((xm==0)||(xm==0xff))Motor_MODE_B_data[i] = Motor_MODE_B_data_def[i];
       else Motor_MODE_B_data[i] = xm-1;              //save在EEPROM的Motor data比实际的要大1
       ClearWDT(); // Service the WDT
    }
    
    for(i=0;i<3;i++)
      for(j=0;j<4;j++)
    {
       xm = ReadByteEEPROM( addr_eeprom_sys+addr_eeprom_Origin+i*4+j );
       Motor_Origin_data[i][j]=xm;
       ClearWDT(); // Service the WDT
    }
}
