/***********************************************************************/
/*  FILE        :Uart.c                                                */
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

#define	TXD1_enable	(USART1_CR2 = 0x08)		// 允许发送	
#define RXD1_enable	(USART1_CR2 = 0x24)		// 允许接收及其中断	
//********************************************
void UART1_INIT(void){						// 
	USART1_CR1 = 0;							// 1个起始位,8个数据位 
	USART1_CR3 = 0;							// 1个停止位 
	USART1_CR4 = 0;
	USART1_CR5 = 0x00;//0x08;						// 半双工模式
	USART1_BRR2 = 0x03;						// 设置波特率9600
	USART1_BRR1 = 0x68;						// 3.6864M/9600 = 0x180
	                                                                //16.00M/9600 = 0x683
	//USART1_CR2 = 0x08;	// 允许发送
        USART1_CR2 = 0x24;

} 
void UART1_end(void){		// 
        //SYSCFG_RMPCR1_USART1TR_REMAP=0;
	USART1_CR1 = 0;							// 1个起始位,8个数据位 
	USART1_CR3 = 0;							// 1个停止位 
	USART1_CR4 = 0;
	USART1_CR5 = 0x00;						// 半双工模式
	USART1_BRR2 = 0x00;						// 设置波特率9600
	USART1_BRR1 = 0x00;						// 3.6864M/9600 = 0x180
	                                                                //16.00M/9600 = 0x683
        USART1_CR2 = 0x00;    //禁止串口
} 
//--------------------------------------------
void UART1_RX_RXNE(void){		// RXD中断服务程序 
	unsigned char dat,UART_DATA_j;
        UINT16 UART_RX_current_SUM;
	dat = USART1_DR;							// 接收数据
	
        if(UART_pact_select==1){
	   if (dat=='(')  SIO_cnt = 0;
	   SIO_buff[SIO_cnt] = dat;
	   SIO_cnt = (SIO_cnt + 1) & 0x1F;
	   if (dat==')'){
		for (dat=0;dat<SIO_cnt;dat++) {
			SIO_DATA[dat] = SIO_buff[dat];
		}
		BIT_SIO = 1;						// 标志
		//SIO_TOT = 20;	
	    }
        }
        
        
        else {
           UART_RX_RT[UART_RX_idx++]=dat;  // Check preamble 
           UART_RX_check_SUM=UART_RX_check_SUM+dat;
           if(UART_RX_idx==2){
             if((UART_RX_RT[0]!=0xbb)||(UART_RX_RT[1]!=0x00)){
                  UART_RX_RT[0]=UART_RX_RT[1];
                  UART_RX_idx=1;
             }
             else UART_RX_check_SUM=0xbb+0x00;
           }
           else if(UART_RX_idx==8){
             UART_RX_Size=UART_RX_RT[7]<<8;
             UART_RX_Size=UART_RX_Size+ UART_RX_RT[6]+10;
           }
           else if(UART_RX_idx>9){
             if(UART_RX_idx==UART_RX_Size){
               UART_RX_check_SUM=UART_RX_check_SUM - UART_RX_RT[UART_RX_idx-1]- UART_RX_RT[UART_RX_idx-2];
               UART_RX_current_SUM=UART_RX_RT[UART_RX_idx-1]<<8;
               UART_RX_current_SUM=UART_RX_current_SUM+UART_RX_RT[UART_RX_idx-2];
                 if(UART_RX_current_SUM==UART_RX_check_SUM){
                     for(UART_DATA_j=0;UART_DATA_j<UART_RX_Size;UART_DATA_j++)UART1_DATA[UART_DATA_j]=UART_RX_RT[UART_DATA_j];
                     FLAG_UART_R=1;
                 }
                 else FLAG_UART_R=2;
               UART_RX_check_SUM=0;
               UART_RX_idx=0;
             }
           }
             
        }
	
        
        
} 

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
  if(Receiver_OUT_OPEN==1)Receiver_OUT_value=Receiver_OUT_value|0x01;
  else Receiver_OUT_value=Receiver_OUT_value&0xfe;
  if(Receiver_OUT_STOP==1)Receiver_OUT_value=Receiver_OUT_value|0x02;
  else Receiver_OUT_value=Receiver_OUT_value&0xfd;  
  if(Receiver_OUT_CLOSE==1)Receiver_OUT_value=Receiver_OUT_value|0x04;
  else Receiver_OUT_value=Receiver_OUT_value&0xfb;  
  if(Receiver_OUT_VENT==1)Receiver_OUT_value=Receiver_OUT_value|0x08;
  else Receiver_OUT_value=Receiver_OUT_value&0xf7;   
  if(Receiver_OUT_value_last!=Receiver_OUT_value){
    Receiver_OUT_value_last=Receiver_OUT_value;
    UART_send_Receiver_OUT();
  }
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

//--------------------------------------------
void Send_char(unsigned char ch){			// 发送字符
	TXD1_enable;							// 允许发送	
	while(!USART1_SR_TXE);
	USART1_DR = ch;							// 发送
	while(!USART1_SR_TC);					// 等待完成发送
	RXD1_enable;							// 允许接收及其中断	
}
//--------------------------------------------
void Send_String(unsigned char *string){	// 发送字符串
	unsigned char i=0;
	TXD1_enable;							// 允许发送	
	while (string[i]){
		while(!USART1_SR_TXE);				// 检查发送OK
		USART1_DR = string[i];				// 发送
		i++;
	}
	while(!USART1_SR_TC);					// 等待完成发送
	RXD1_enable;							// 允许接收及其中断	
//	BIT_SIO = 0;							// 标志	
}


/***********************************************************************/
unsigned char asc_hex(unsigned char asc)	// HEX
{
	unsigned char i;
	if (asc < 0x3A) i = asc & 0x0F; 
	else i = asc - 0x37;
	return i;
}

unsigned char hex_asc(unsigned char hex)
{
	unsigned char i;
	hex = hex & 0x0F;
	if (hex < 0x0A) i = hex | 0x30;
	else i = hex + 0x37;
	return i;
}

unsigned char asc_hex_2(unsigned char asc1,unsigned char asc0)
{                                    
	unsigned char i; 
	i = (asc_hex(asc1) << 4) + (asc_hex(asc0) & 0x0F);
	return i;
} 




//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void PC_PRG(void)								// 串口命令
{
	unsigned int  i,j;
	unsigned char  d3,d2,d1,d0;
	
	if (BIT_SIO){
		BIT_SIO = 0;
		//SIO_TOT = 20;
		switch (SIO_DATA[1]){
		//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		//%                 写操作               %
		//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		case 'W': 	  
			//==================================== ADF7012
			if (SIO_DATA[2]=='I')				// (WIxd0d1d2d3) 
			{
			        i = asc_hex_2(0x30,SIO_buff[3]);
				d0 = asc_hex_2(SIO_buff[4],SIO_buff[5]);
				d1 = asc_hex_2(SIO_buff[6],SIO_buff[7]);
				d2 = asc_hex_2(SIO_buff[8],SIO_buff[9]);
				d3 = asc_hex_2(SIO_buff[10],SIO_buff[11]);
				
	                        //write Rx
                                ROM_adf7012_value[i].byte[0] = d0;
				ROM_adf7012_value[i].byte[1] = d1;
				ROM_adf7012_value[i].byte[2] = d2;
				ROM_adf7012_value[i].byte[3] = d3;
                                dd_write_7021_reg(&ROM_adf7012_value[i].byte[0]);
                                Delayus(122);		//delay 40us
									
				//-------------------------------- 保存
				if(i==1){
				     j=addr_eeprom_ADF7021+i*4;
				     UnlockFlash( UNLOCK_EEPROM_TYPE );
				     WriteByteToFLASH(addr_eeprom_sys+j,d0);
				     WriteByteToFLASH(addr_eeprom_sys+j+1,d1);
				     WriteByteToFLASH(addr_eeprom_sys+j+2,d2);
				     WriteByteToFLASH(addr_eeprom_sys+j+3,d3);
				     LockFlash( UNLOCK_EEPROM_TYPE );
				
				     ClearWDT(); // Service the WDT
				}
				//-------------------------------返回  (WHx)
				d1 = '(';
				d2 = 'W';
				Send_char(d1);
				Send_char(d2);		
				d1 = 'I';
				d2 = ')';
				Send_char(d1);
				Send_char(d2);		
				Send_char(SIO_buff[3]);
				
			}	
			
			//==================================== ADF7012 TX/RX调试
			if (SIO_DATA[2]=='J')				// (WJx) 
			{
			        Tx_Rx_mode = asc_hex_2(0x30,SIO_buff[3]);
				//-------------------------------返回  (WHx)
				d1 = '(';
				d2 = 'W';
				Send_char(d1);
				Send_char(d2);		
				d1 = 'J';
				d2 = ')';
				Send_char(d1);
				Send_char(d2);		
				Send_char(SIO_buff[3]);
				
			}				
		        break;
		//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		//%                 读操作               %
		//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		case 'R':   	  
			//==================================== ADF7012   //(RIx)
			if (SIO_DATA[2]=='I')				// (RI)d0d1d2d3 
			{
			        i = asc_hex_2(0x30,SIO_buff[3]);
			  	d1 = '(';
				d2 = 'R';
				Send_char(d1);
				Send_char(d2);		
				d1 = 'I';
				d2 = ')';
				Send_char(d1);
				Send_char(d2);	
				for (j=0;j<4;j++){
			  	   d1 = hex_asc(ROM_adf7012_value[i].byte[j] / 16);
				   d2 = hex_asc(ROM_adf7012_value[i].byte[j] % 16);
				   Send_char(d1);
				   Send_char(d2);					   
				}
                        }			  
		        break;	
		default:
			break;
                        
		}
	}
}