/***********************************************************************/
/*  FILE        :Motor_uart.c                                          */
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
#include "key.h"		// key


void UART_Handler(void)
{
  uni_i uart_x;
  UINT8 i,uart_num,d_num,uart_n[4];
  
  if(FLAG_UART_R!=0){
    if(UART1_DATA[4]==1){         //�˻�mcu���豸addr:1���յ������豸�ĺ���
      if(FLAG_UART_R==1)
      {
        UART_ack(0);   //����������������У��
        uart_x.uc[0]=UART1_DATA[3];       //ָ��
        uart_x.uc[1]=UART1_DATA[2];
        switch(uart_x.ui){             //��������
            case 0x8001:     
                        uart_num=UART1_DATA[8];
                        for(i=0;i<4;i++)uart_n[i]=UART1_DATA[9+i];
                        
                        if(uart_num==1){
                           _ReqBuzzer(20,20,3);
                        }
                        else if((uart_num>1)&&(uart_num<5)){
                           if((uart_num==2)||(uart_num==3))_ReqBuzzer(10,10,2);
                           else if(uart_num==4)_ReqBuzzer(500,1,1);
                           
                           d_num=uart_num-2;
                           UnlockFlash( UNLOCK_EEPROM_TYPE );  
                           for(i=0;i<4;i++)
                           {
                              WriteByteToFLASH( addr_eeprom_sys+addr_eeprom_Origin+d_num*4+i, uart_n[i]);   //save��EEPROM�ľ�����ԭ��
                              Motor_Origin_data[d_num][i]=uart_n[i];
                           }
                           LockFlash( UNLOCK_EEPROM_TYPE );                           
                        }
                        else if(uart_num==5){
                           _ReqBuzzer(10,10,8);
                        }                         
                        break;
            default:
                        break;  
        }
      }
      else if(FLAG_UART_R==2)UART_ack(1);;  //��������У��ʧ��
    }
    else {         //��ʾ�˻�mcu���豸addr:1�����Ÿ������豸��ķ������
      if(FLAG_UART_R==1);  //��ʾ����OK
      else if(FLAG_UART_R==2);  //��ʾ����ʧ�ܣ���Ҫ����
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
  UINT8 i,j,d_number[12];
  
    UART_send_CMD=0x0201;
    UART_send_Motor(UART_send_CMD,0x02,50,Motor_MODE_B_data);    
    
    for(i=0;i<3;i++)
      for(j=0;j<4;j++)
    {
       d_number[i*4+j]=Motor_Origin_data[i][j];
       ClearWDT(); // Service the WDT
    }
    UART_send_CMD=0x0202;
    UART_send_Motor(UART_send_CMD,0x02,12,d_number);    
}

void UART_send_Motor(UINT16 d_COM,UINT8 d_addr,UINT8 d_length,UINT8 *d_data)
{
  UINT16  sum;
  UINT8 i,d_num;
  
	Send_char(0xbb);   //0xbb
        sum=0xbb;
	Send_char(0x00);   //0x00
        d_num=d_COM%256;
        Send_char(d_num);   //������ֽ�
        sum= sum+d_num;
        d_num=d_COM/256;
        Send_char(d_num);  //������ֽ�
        sum= sum+d_num;
        Send_char(d_addr);  //�豸��ַ    
        sum= sum+d_addr;
        Send_char(0x00);             //�����鱨
        d_num=d_length%256;
        Send_char(d_num);           //���ݳ��ȵ��ֽ�
        sum= sum+d_num;
        d_num=d_length/256;
        Send_char(d_num);           //���ݳ��ȸ��ֽ�
        sum= sum+d_num;
        for(i=0;i<d_length;i++)
        {
          d_num=d_data[i];
          Send_char(d_num);   //���� DATA
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
        Send_char(0x01);   //������ֽ�
        sum= sum+0x01;
        Send_char(0x01);  //������ֽ�
        sum= sum+0x01;
        Send_char(0x02);  //�豸��ַ    
        sum= sum+0x02;
        Send_char(0x00);             //�����鱨
        Send_char(0x01);           //���ݳ��ȵ��ֽ�
        sum= sum+0x01;
        Send_char(0x00);           //���ݳ��ȸ��ֽ�
        Send_char(Receiver_OUT_value);   //���� DATA
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
        Send_char(UART1_DATA[2]);   //������ֽ�
        sum= sum+UART1_DATA[2];
        Send_char(UART1_DATA[3]);  //������ֽ�
        sum= sum+UART1_DATA[3];
        Send_char(UART1_DATA[4]);  //�豸��ַ    
        sum= sum+UART1_DATA[4];
        Send_char(ch);             //�����鱨
        sum= sum+ch;
        Send_char(0x00);           //���ݳ��ȵ��ֽ�
        Send_char(0x00);           //���ݳ��ȸ��ֽ�
        Send_char(sum%256);        //sum_L
        Send_char(sum/256);        //sum_H
}
