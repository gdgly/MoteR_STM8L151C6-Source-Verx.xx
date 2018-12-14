/***********************************************************************/
/*  FILE        :Motor_eeprom.c                                        */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/

#include  <iostm8l151c6.h>			// CPU�ͺ� 
#include "Pin_define.h"		// �ܽŶ���
#include "initial.h"		// ��ʼ��  Ԥ����
#include "ram.h"		// RAM����
#include "adf7021.h"		// ��ʼ��ADF7021
#include "eeprom.h"		// eeprom
#include "uart.h"		// uart
#include "Motor_uart.h"		// Motor_uart
#include "LED.h"		// led



void Motor_eeprom_load(void)
{
  UINT8 i,xm;
  
    for(i=0;i<def_MODE_B;i++)
    {
       xm = ReadByteEEPROM( addr_eeprom_sys+addr_eeprom_MOTOR+i );
       if((xm==0)||(xm==0xff))Motor_MODE_B_data[i] = Motor_MODE_B_data_def[i];
       else Motor_MODE_B_data[i] = xm-1;              //save��EEPROM��Motor data��ʵ�ʵ�Ҫ��1
       ClearWDT(); // Service the WDT
    }
    
}
