/***********************************************************************/
/*  FILE        :LED.c                                                 */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/


#include  <iostm8l151c6.h>				// CPU型号 
#include "Pin_define.h"		// 管脚定义
#include "initial.h"		// 初始化  预定义
#include "ram.h"		// RAM定义

const unsigned char char_7segment[];


/*********************************************************************
Function:	void LED_display_INT(void)

PreCondition:	None.
 
Overview:       （1）LED1、LED2、LED3以1ms轮流更新，对应data在LED_data_buf数组缓存
                （2）TIME_SET_twinkling为LED闪烁频率，单位ms
                （3）LED_ON_OFF为闪烁开关   					
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
 
Overview:       （1）char_data为LED1、LED2、LED3显示内容
                （2）led1_glint、led2_glint、led3_glint为闪烁设置
                     bit0----数码管a段闪烁设置，=1为闪烁，=0为不闪烁
                     bit1----数码管b段
                     bit2----数码管c段
                     bit3----数码管d段  
                     bit4----数码管e段
                     bit5----数码管f段
                     bit6----数码管g段
                     bit7----数码管dp段
                     0x00----整个数码管不闪烁
                     0xff----整个数码管闪烁
                （3）set_glint_time  LED闪烁频率，单位ms
                （4）led_point  
                         =1 叠加显示
                         =0 覆盖显示
举例：  LED_display_page("abc",0xff,0,0,200,0);        将abc字符串分别显示在3个数码管，LED1以200ms闪烁
        LED_display_page("  .",0xff,0,0x80,200,1);     将小数点叠加显示在LED3数码管，同时让LED1、LED3的dp点以200ms闪烁
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
//以下是字库
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&//
const unsigned char char_7segment[] ={
/*--  宽度x高度=5x8  --*/   
                          // ASCII码(HEX)  字符
  0xff,       //20      空白
  0xff,       //21       ！
  0xff,       //22       “       空
  0xff,       //23       #        空 
  0xff,       //24      ￥
  0xff,       //25       %        空  
  0xff,       //26       &        空 
  0xfe,       //27       '        用符号'表示_的上横线，即数码管a段显示
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
  0xff,       //3F        ?        空 
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
  0xff,       //5C      符号反斜杠   
  0xff,       //5D        ]
  0xff,       //5E        ^
  0xf7,       //5F        _
  0xff,       //60        '        空   
  
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
  0xff,       //7B       三国 
};

