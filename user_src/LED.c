/***********************************************************************/
/*  FILE        :LED.c                                                 */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/


#include  <iostm8l151c6.h>				// CPU�ͺ� 
#include "Pin_define.h"		// �ܽŶ���
#include "initial.h"		// ��ʼ��  Ԥ����
#include "ram.h"		// RAM����

const unsigned char char_7segment[];


/*********************************************************************
Function:	void LED_display_INT(void)

PreCondition:	None.
 
Overview:       ��1��LED1��LED2��LED3��1ms�������£���Ӧdata��LED_data_buf���黺��
                ��2��TIME_SET_twinklingΪLED��˸Ƶ�ʣ���λms
                ��3��LED_ON_OFFΪ��˸����   					
********************************************************************/
void LED_display_INT(void)
{
    LED_DATA=0xff;
    LED_DP++;    
    if(LED_DP>2)LED_DP=0;
    switch(LED_DP){
        case 0:  
          LED_SEL1=0;
          LED_SEL3=1;
          break;
        case 1:
          LED_SEL2=0;
          LED_SEL1=1;
          break;
        case 2:  
          LED_SEL3=0;
          LED_SEL2=1;
          break;
        default : 
          break;
    }
    
    TIME_twinkling_count++;
    if(TIME_SET_twinkling==0)LED_ON_OFF=0;
    else if(TIME_twinkling_count>=TIME_SET_twinkling){TIME_twinkling_count=0;LED_ON_OFF++;}
    
    if(LED_ON_OFF&0x01)LED_DATA=LED_data_buf[LED_DP]|LED_data_twinkling[LED_DP];
    else LED_DATA=LED_data_buf[LED_DP];
}


/*********************************************************************
Function:	void LED_display_page(UINT8 *char_data,UINT8 led1_glint, UINT8 led2_glint,UINT8 led3_glint,UINT16 set_glint_time,UINT8 led_point)

PreCondition:	None.
 
Overview:       ��1��char_dataΪLED1��LED2��LED3��ʾ����
                ��2��led1_glint��led2_glint��led3_glintΪ��˸����
                     bit0----�����a����˸���ã�=1Ϊ��˸��=0Ϊ����˸
                     bit1----�����b��
                     bit2----�����c��
                     bit3----�����d��  
                     bit4----�����e��
                     bit5----�����f��
                     bit6----�����g��
                     bit7----�����dp��
                     0x00----��������ܲ���˸
                     0xff----�����������˸
                ��3��set_glint_time  LED��˸Ƶ�ʣ���λms
                ��4��led_point  
                         =1 ������ʾ
                         =0 ������ʾ
������  LED_display_page("abc",0xff,0,0,200,0);        ��abc�ַ����ֱ���ʾ��3������ܣ�LED1��200ms��˸
        LED_display_page("  .",0xff,0,0x80,200,1);     ��С���������ʾ��LED3����ܣ�ͬʱ��LED1��LED3��dp����200ms��˸
********************************************************************/
void LED_display_page(UINT8 *char_data,UINT8 led1_glint, UINT8 led2_glint,UINT8 led3_glint,UINT16 set_glint_time,UINT8 led_point)
{
     
     if(led_point==0){
        LED_data_buf[0]=char_7segment[char_data[0]-0x20];
        LED_data_buf[1]=char_7segment[char_data[1]-0x20];
        LED_data_buf[2]=char_7segment[char_data[2]-0x20];
     } 
     else if(led_point==1){
        LED_data_buf[0]=char_7segment[char_data[0]-0x20]&LED_data_buf[0];
        LED_data_buf[1]=char_7segment[char_data[1]-0x20]&LED_data_buf[1];
        LED_data_buf[2]=char_7segment[char_data[2]-0x20]&LED_data_buf[2];
     }
     else if(led_point==2){
        LED_data_buf[0]=~char_7segment[char_data[0]-0x20]|LED_data_buf[0];
        LED_data_buf[1]=~char_7segment[char_data[1]-0x20]|LED_data_buf[1];
        LED_data_buf[2]=~char_7segment[char_data[2]-0x20]|LED_data_buf[2];       
     }
     LED_data_twinkling[0]=led1_glint;
     LED_data_twinkling[1]=led2_glint;
     LED_data_twinkling[2]=led3_glint;
     TIME_SET_twinkling=set_glint_time;       
}



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&//
//�������ֿ�
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&//
const unsigned char char_7segment[] ={
/*--  ���x�߶�=5x8  --*/   
                          // ASCII��(HEX)  �ַ�
  0xff,       //20      �հ�
  0xff,       //21       ��
  0xff,       //22       ��       ��
  0xff,       //23       #        �� 
  0xff,       //24      ��
  0xff,       //25       %        ��  
  0xff,       //26       &        �� 
  0xfe,       //27       '        �÷���'��ʾ_���Ϻ��ߣ��������a����ʾ
  0xff,       //28       (
  0xff,       //29       )
  0xff,       //2A       *
  0xff,       //2B       +
  0xff,       //2C       '
  0xfc,       //2D       -   
  0x7f,       //2E       .
  0xff,       //2F       /
    
  0xc0,       //30        0    
  0xf9,       //31        1
  0xa4,       //32        2
  0xb0,       //33        3
  0x99,       //34        4
  0x92,       //35        5
  0x82,       //36        6 
  0xf8,       //37        7
  0x80,       //38        8
  0x90,       //39        9 

  0xff,       //3A        :
  0xff,       //3B        ;
  0xff,       //3C        <
  0xff,       //3D        =
  0xff,       //3E        >
  0xff,       //3F        ?        �� 
  0xff,       //40        @
  
  0x88,       //41        A  
  0x83,       //42        B
  0xc6,       //43        C
  0xa1,       //44        D
  0x86,       //45        E
  0x8e,       //46        F
  0x43,       //47        G
  0x89,       //48        H
  0xdf,       //49        I
  0x8f,       //4A        J
  0xf1,       //4B        K
  0xc7,       //4C        L
  0x55,       //4D        M
  0xab,       //4E        N
  0xa3,       //4F        O
  0x8c,       //50        P
  0x98,       //51        Q
  0xaf,       //52        R
  0x49,       //53        S
  0x87,       //54        T
  0xc1,       //55        U
  0xc7,       //56        V
  0x47,       //57        W
  0xd7,       //58        X
  0x91,       //59        Y
  0xed,       //5A        Z
  
  0xff,       //5B        [
  0xff,       //5C      ���ŷ�б��   
  0xff,       //5D        ]
  0xff,       //5E        ^
  0xf7,       //5F        _
  0xff,       //60        '        ��   
  
  0x88,       //61       a
  0x83,       //62       b
  0xc6,       //63       c
  0xa1,       //64       d
  0x86,       //65       e
  0x8e,       //66       f
  0x43,       //67       g
  0x89,       //68       h
  0xdf,       //69       i
  0x8f,       //6A       j
  0xf1,       //6B       k
  0xc7,       //6C       l
  0x55,       //6D       m
  0xab,       //6E       n
  0xa3,       //6F       o
  0x8c,       //70       p
  0x98,       //71       q
  0xaf,       //72       r
  0x49,       //73       s
  0x87,       //74       t
  0xc1,       //75       u
  0xc7,       //76       v
  0x47,       //77       w
  0xd7,       //78       x
  0x91,       //79       y
  0xed,       //7A       z 
  0xff,       //7B       ���� 
};

