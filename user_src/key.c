/***********************************************************************/
/*  FILE        :key.c                                                 */
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
#include "LED.h"		// led
#include "Motor_eeprom.h"	// Motor_eeprom
#include "Motor_uart.h"		// Motor_uart


void KEY_MODE_function(void);
void KEY_ENT_function(void);
void KEY_UP_function(void);
void KEY_DOWN_function(void);
void Send_led_display(UINT8 led_PAGE,UINT8 *p0,UINT32 *p1);


void DSW_switch_R_L(void)
{
  UINT8 d_switch=0,d_number[2];
  
    if(MOTOR_left_right_bit0)d_switch |= 1;
    d_switch += d_switch; // left shift 1
    if(MOTOR_left_right_bit1)d_switch |= 1;
    if(DSW_switch_last!=d_switch){
          UART_send_CMD=0x0103;
          d_number[0]=d_switch;
          UART_send_Motor(UART_send_CMD,0x02,0x01,d_number);       
      DSW_switch_last=d_switch;
    }
    if(KEY_MODE_ABC==0)
    {
        if((d_switch==0)||(d_switch==3))
        {
           FLAG_SWITCH_stop_Motor=1;
           LED_display_page("E04",0,0,0,0,0);
        }
        else if(FLAG_SWITCH_stop_Motor==1)
        {
           FLAG_SWITCH_stop_Motor=0;
           LED_display_page("-  ",0,0,0,0,0);
        }
    }
}

void	_SwIn( uchar sw )
{
	m_KeyNew<<= 1 ;
	if	( sw )
	{
		m_KeyNew |= 1 ;
	}
}

void Key_scan(void)
{
  
  if(Motor_FG_10ms==1)
  {
     Motor_FG_10ms=0;
     if(TIME_MODE)--TIME_MODE;

	m_KeyNew = 0xFF ;	
	_SwIn( PIN_KEY_MODE ) ;
	_SwIn( PIN_KEY_ENT ) ;
	_SwIn( PIN_KEY_UP ) ;
	_SwIn( PIN_KEY_DOWN ) ;	
	_SwIn( 1 ) ;	
	_SwIn( 1 ) ;	    
	_SwIn( 1 ) ;	
        _SwIn( 1 ) ;
        
	if	(( m_KeyNew != m_KeyOld )||(m_KeyNew==0xFF))				// Key in
	{								// Different with the last state
		m_KeyOld = m_KeyNew ;
		m_ChatterCount = d_Time50ms ;				// Chatter counter set
		FLAG_KEY_MODE=0;				// Clear key continue state
                FLAG_KEY_ENT=0;
                FLAG_KEY_DOWN=0;
                FLAG_KEY_UP=0;
		return ;
	}
	if	( --m_ChatterCount )						// Chattering ok ?
	{
		return ;
	}
	m_ChatterCount = 1 ;

	switch	( m_KeyNew )    // Jumo to key function
	{
		case 0x7f :       //KEY_MODE
                           KEY_MODE_function();
                           break ;	  
		case 0xbf :       //KEY_ENT
                           if(KEY_MODE_ABC!=0)
                              KEY_ENT_function();
                           break ;	                  
		case 0xdf :       //KEY_UP
                           if(KEY_MODE_ABC!=0)
                              KEY_UP_function();
                           break ;
		case 0xef :       //KEY_DOWN
                           if(KEY_MODE_ABC!=0)
                              KEY_DOWN_function();
                           break ;  
                default:   
                           break ; 
        }
  }
}



void KEY_MODE_function(void)
{
  UINT8 data_num,d_number[2];
  
  if((FLAG_KEY_MODE==0)||((FLAG_KEY_MODE==1)&&(TIME_MODE==0)))
  {
     FLAG_KEY_MODE=1;
     TIME_MODE=30;
     TIME_MODE_B_save=5;
     BEEP_CSR2_BEEPEN=1;
     
     if(KEY_Layer==0)   //page layer
     {
        KEY_MODE_ABC++;        
        if(KEY_MODE_ABC>=3)KEY_MODE_ABC=0;
        
        if((KEY_MODE_ABC==1)&&(FLAG_SET_stop_Motor==0)){
          FLAG_SET_stop_Motor=1;
          UART_send_CMD=0x0102;
          d_number[0]=Receiver_OUT_value;
          UART_send_Motor(UART_send_CMD,0x02,0x01,d_number);          
        }
        if(KEY_MODE_ABC==0)FLAG_SET_stop_Motor=0;        
        
        KEY_PAGE=1;
     }
     else if(KEY_Layer==1)  //data layer
     {
       KEY_Layer=0;
       if(KEY_MODE_ABC==1){
          data_num= ReadByteEEPROM( addr_eeprom_sys+addr_eeprom_MOTOR+KEY_PAGE );    //如果更改数据后没有确认save，重新调取以前保存的数据
          Motor_MODE_B_data[KEY_PAGE]= data_num-1;    //save在EEPROM的Motor data比实际的要大1
       }
     }
     Send_led_display(KEY_PAGE,Motor_MODE_B_data,Motor_MODE_C_data);
     
     while(TIME_MODE_B_save)ClearWDT(); // Service the WDT
     BEEP_CSR2_BEEPEN=0;
  }
}

void KEY_ENT_function(void)
{
  UINT8 i;
  
  if(FLAG_KEY_ENT==0)
  {
    FLAG_KEY_ENT=1;
    KEY_Layer++;
    if(KEY_Layer>=2){
      if(KEY_MODE_ABC==1){
         TIME_MODE_B_save=50;
                             
         UnlockFlash( UNLOCK_EEPROM_TYPE );  //需要添加保存设置程序
         WriteByteToFLASH( addr_eeprom_sys+addr_eeprom_MOTOR+KEY_PAGE, Motor_MODE_B_data[KEY_PAGE]+1);   //save在EEPROM的Motor data比实际的要大1
         LockFlash( UNLOCK_EEPROM_TYPE );
         
         UART_send_CMD=0x0201;                                         //将更改的数据Uart到马达驱动MCU
         UART_send_Motor(UART_send_CMD,0x02,50,Motor_MODE_B_data);
         
         for(i=0;i<5;i++)
         {
             while(TIME_MODE_B_save)ClearWDT(); // Service the WDT
             if((i%2)==0)KEY_Layer=0; 
             else KEY_Layer=1; 
             Send_led_display(KEY_PAGE,Motor_MODE_B_data,Motor_MODE_C_data);
             TIME_MODE_B_save=50;
         }
         TIME_MODE_B_save=0;    
         KEY_Layer=0;
      }
      
      else if(KEY_MODE_ABC==2){
        KEY_Layer=1; Send_led_display(KEY_PAGE,Motor_MODE_B_data,Motor_MODE_C_data);
      }
      else KEY_Layer=0;
    }
    
    else Send_led_display(KEY_PAGE,Motor_MODE_B_data,Motor_MODE_C_data);
  }
}

void KEY_UP_function(void)
{
  if(FLAG_KEY_UP==0)
  {
    FLAG_KEY_UP=1;
    if(KEY_Layer==0)
    {
      KEY_PAGE++;
      if(KEY_MODE_ABC==1){
        if(KEY_PAGE>=def_MODE_B)KEY_PAGE=1;
	switch	( KEY_PAGE )   
	{
		case 8 :       //P08 ～ P09无
                           KEY_PAGE=KEY_PAGE+2;  
                           break ;	                  
		case 12 :       //P12 ～ P15无
                           KEY_PAGE=KEY_PAGE+4;  
                           break ;
		case 20 :       //P20 无
                           KEY_PAGE++;  
                           break ; 
		case 33 :       //P33～ P39无
                           KEY_PAGE=KEY_PAGE+7;                          
                           break ; 
		case 43 :       //P93～ P98无
                           KEY_PAGE=KEY_PAGE+6;                          
                           break ;                           
                default:   
                           break ; 
        }        
      }
      else if(KEY_MODE_ABC==2){
        if(KEY_PAGE>=def_MODE_C)KEY_PAGE=1;
      }
    }
    else {
      if(KEY_MODE_ABC==1){
        Motor_MODE_B_data[KEY_PAGE]++;
        if(Motor_MODE_B_data[KEY_PAGE] > Motor_MODE_B_data_H[KEY_PAGE])Motor_MODE_B_data[KEY_PAGE] =  Motor_MODE_B_data_L[KEY_PAGE];  
        if((KEY_PAGE==1)&&(Motor_MODE_B_data[1]==5))Motor_MODE_B_data[1]=8;   //这个数据比较特殊，取值范围是1、2、3、4、8
      }
    }
    Send_led_display(KEY_PAGE,Motor_MODE_B_data,Motor_MODE_C_data);
    
  }
}

void KEY_DOWN_function(void)
{
  if(FLAG_KEY_DOWN==0)
  {
    FLAG_KEY_DOWN=1;
    if(KEY_Layer==0)
    {
      KEY_PAGE--;
      if(KEY_MODE_ABC==1){
        if(KEY_PAGE==0)
          KEY_PAGE=def_MODE_B-1;
	switch	( KEY_PAGE )   
	{  
		case 9 :        //P08 ～ P09无
                           KEY_PAGE=KEY_PAGE-2;
                           break ;	                  
		case 15 :       //P12 ～ P15无
                           KEY_PAGE=KEY_PAGE-4;  
                           break ;
		case 20 :       //P20 无
                           KEY_PAGE--;  
                           break ; 
		case 39 :       //P33～ P39无
                           KEY_PAGE=KEY_PAGE-7;                          
                           break ; 
		case 48 :       //P93～ P98无
                           KEY_PAGE=KEY_PAGE-6;                          
                           break ;                           
                default:   
                           break ; 
        }         
      }
      else if(KEY_MODE_ABC==2){
        if(KEY_PAGE==0)KEY_PAGE=def_MODE_C-1;
      }
    }
    else {
      if(KEY_MODE_ABC==1){
        if(Motor_MODE_B_data[KEY_PAGE]==0) Motor_MODE_B_data[KEY_PAGE] =  Motor_MODE_B_data_H[KEY_PAGE] + 1;
        Motor_MODE_B_data[KEY_PAGE]--;
        if(Motor_MODE_B_data[KEY_PAGE] < Motor_MODE_B_data_L[KEY_PAGE])Motor_MODE_B_data[KEY_PAGE] =  Motor_MODE_B_data_H[KEY_PAGE];     
        if((KEY_PAGE==1)&&(Motor_MODE_B_data[1]==7))Motor_MODE_B_data[1]=4;   //这个数据比较特殊，取值范围是1、2、3、4、8
      }
    }
    Send_led_display(KEY_PAGE,Motor_MODE_B_data,Motor_MODE_C_data);
    
  }  
}

void Send_led_display(UINT8 led_PAGE,UINT8 *p0,UINT32 *p1)
{
  UINT8 num,char_num[3];

  if(KEY_Layer==0)
  {
    	switch	( KEY_MODE_ABC )    
	{
		case 0 :       
                           LED_display_page("   ",0,0,0,0,0); 
                           break ;	  
		case 1 :   
                           char_num[0]='P';
                           if(led_PAGE>=40)led_PAGE=led_PAGE+50;
                           goto case_2;
		case 2 :   
                           char_num[0]='H';
                           if(led_PAGE>=21)led_PAGE=99;
                           
                case_2:    num=led_PAGE/10+0x30;
                           char_num[1]=num;
                           num=led_PAGE%10+0x30;
                           char_num[2]=num;
                           LED_display_page(char_num,0,0,0,0,0); 
                           break ; 
                default:   
                           break ; 
        }
  }
  else if(KEY_Layer==1)
  {
     if(KEY_MODE_ABC==1)
     {
       char_num[0]=' ';
       num=p0[led_PAGE]/10+0x30;
       char_num[1]=num;
       num=p0[led_PAGE]%10+0x30;
       char_num[2]=num;         
       LED_display_page(char_num,0,0,0,0,0);
     }
     else if(KEY_MODE_ABC==2) LED_display_page("000",0,0,0,0,0);
     
  }
}