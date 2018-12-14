/***********************************************************************/
/*  FILE        :Motor_uart.c                                          */
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



void UART_Handler(void)
{
  if(FLAG_UART_R!=0){
    if(UART1_DATA[4]==1){         //人机mcu（设备addr:1）收到其它设备的呼叫
      if(FLAG_UART_R==1)UART_ack(0);   //接收数据完整，并校验
      else if(FLAG_UART_R==2)UART_ack(1);;  //接收数据校验失败
    }
    else {         //表示人机mcu（设备addr:1）送信给其它设备后的反馈情况
      if(FLAG_UART_R==1);  //表示送信OK
      else if(FLAG_UART_R==2);  //表示送信失败，需要处理
    }
    FLAG_UART_R=0;  
  }
    
}

void Receiver_OUT_change_UART(void)
{
  UINT8 d_number[2];
  
  if(Receiver_OUT_OPEN==1)Receiver_OUT_value=Receiver_OUT_value|0x01;
  else Receiver_OUT_value=Receiver_OUT_value&0xfe;
  if(Receiver_OUT_STOP==1)Receiver_OUT_value=Receiver_OUT_value|0x02;
  else Receiver_OUT_value=Receiver_OUT_value&0xfd;  
  if(Receiver_OUT_CLOSE==1)Receiver_OUT_value=Receiver_OUT_value|0x04;
  else Receiver_OUT_value=Receiver_OUT_value&0xfb;  
  if(Receiver_OUT_VENT==1)Receiver_OUT_value=Receiver_OUT_value|0x08;
  else Receiver_OUT_value=Receiver_OUT_value&0xf7;   
  if((Receiver_OUT_value_last!=Receiver_OUT_value)&&(FLAG_SET_stop_Motor==0)&&(FLAG_SWITCH_stop_Motor==0)){
    Receiver_OUT_value_last=Receiver_OUT_value;
    
    //UART_send_Receiver_OUT();
    UART_send_CMD=0x0101;
    d_number[0]=Receiver_OUT_value;
    UART_send_Motor(UART_send_CMD,0x02,0x01,d_number);
    
    if(Receiver_OUT_value==0x01)LED_display_page("'  ",0,0,0,0,0);
    else if(Receiver_OUT_value==0x02)LED_display_page("-  ",0,0,0,0,0);
    else if(Receiver_OUT_value==0x04)LED_display_page("_  ",0,0,0,0,0);
  }
}


void UART_Power_ON_send(void)
{
    UART_send_CMD=0x0201;
    UART_send_Motor(UART_send_CMD,0x02,50,Motor_MODE_B_data);    
}

void UART_send_Motor(UINT16 d_COM,UINT8 d_addr,UINT8 d_length,UINT8 *d_data)
{
  UINT16  sum;
  UINT8 i,d_num;
  
	Send_char(0xbb);   //0xbb
        sum=0xbb;
	Send_char(0x00);   //0x00
        d_num=d_COM%256;
        Send_char(d_num);   //命令低字节
        sum= sum+d_num;
        d_num=d_COM/256;
        Send_char(d_num);  //命令高字节
        sum= sum+d_num;
        Send_char(d_addr);  //设备地址    
        sum= sum+d_addr;
        Send_char(0x00);             //返信情报
        d_num=d_length%256;
        Send_char(d_num);           //数据长度低字节
        sum= sum+d_num;
        d_num=d_length/256;
        Send_char(d_num);           //数据长度高字节
        sum= sum+d_num;
        for(i=0;i<d_length;i++)
        {
          d_num=d_data[i];
          Send_char(d_num);   //数据 DATA
          sum= sum+d_num;
          ClearWDT(); // Service the WDT
        }
        Send_char(sum%256);        //sum_L
        Send_char(sum/256);        //sum_H  
}


void UART_send_Receiver_OUT(void)
{
  UINT16  sum;
  
	Send_char(0xbb);   //0xbb
        sum=0xbb;
	Send_char(0x00);   //0x00
        Send_char(0x01);   //命令低字节
        sum= sum+0x01;
        Send_char(0x01);  //命令高字节
        sum= sum+0x01;
        Send_char(0x02);  //设备地址    
        sum= sum+0x02;
        Send_char(0x00);             //返信情报
        Send_char(0x01);           //数据长度低字节
        sum= sum+0x01;
        Send_char(0x00);           //数据长度高字节
        Send_char(Receiver_OUT_value);   //数据 DATA
        sum= sum+Receiver_OUT_value;
        Send_char(sum%256);        //sum_L
        Send_char(sum/256);        //sum_H  
}


void UART_ack(unsigned char ch)
{
  UINT16  sum;
  
	Send_char(UART1_DATA[0]);   //0xbb
        sum=UART1_DATA[0];
	Send_char(UART1_DATA[1]);   //0x00
        Send_char(UART1_DATA[2]);   //命令低字节
        sum= sum+UART1_DATA[2];
        Send_char(UART1_DATA[3]);  //命令高字节
        sum= sum+UART1_DATA[3];
        Send_char(UART1_DATA[4]);  //设备地址    
        sum= sum+UART1_DATA[4];
        Send_char(ch);             //返信情报
        sum= sum+ch;
        Send_char(0x00);           //数据长度低字节
        Send_char(0x00);           //数据长度高字节
        Send_char(sum%256);        //sum_L
        Send_char(sum/256);        //sum_H
}
