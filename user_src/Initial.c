/***********************************************************************/
/*  FILE        :initial.c                                             */
/*  DATE        :Mar, 2013                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/
#include  <iostm8l151c6.h>
//#include        "stm8l15x.h"
#include "Pin_define.h"		// �ܽŶ���
#include "initial.h"		// ��ʼ��  Ԥ����
#include "ram.h"		// RAM����
#include "adf7021.h"		// ��ʼ��ADF7021
#include "uart.h"		// uart
#include "LED.h"		// led

void RAM_clean(void){						// ���RAM 
	asm("ldw X,#0");
	asm("clear_ram:");
	asm("clr (X)");
	asm("incw X");
	asm("cpw X,#0x6ff");	
	asm("jrule clear_ram");
        
        LED_data_buf[0]=0x00;
        LED_data_buf[1]=0x00;
        LED_data_buf[2]=0x00;
}  
void WDT_init(void)
{
  IWDG_KR=0xCC;
  IWDG_KR=0x55;
  IWDG_PR=3;
  IWDG_KR=0xAA;  
}
void ClearWDT(void)
{
  IWDG_KR=0xAA;
}
//========================GPIO˵��===============================================================
//  GPIO_Mode_In_FL_No_IT      = (uint8_t)0x00,   /*!< Input floating, no external interrupt */
//  GPIO_Mode_In_PU_No_IT      = (uint8_t)0x40,   /*!< Input pull-up, no external interrupt */
//  GPIO_Mode_In_FL_IT         = (uint8_t)0x20,   /*!< Input floating, external interrupt */
//  GPIO_Mode_In_PU_IT         = (uint8_t)0x60,   /*!< Input pull-up, external interrupt */
//  GPIO_Mode_Out_OD_Low_Fast  = (uint8_t)0xA0,   /*!< Output open-drain, low level, 10MHz */
//  GPIO_Mode_Out_PP_Low_Fast  = (uint8_t)0xE0,   /*!< Output push-pull, low level, 10MHz */
//  GPIO_Mode_Out_OD_Low_Slow  = (uint8_t)0x80,   /*!< Output open-drain, low level, 2MHz */
//  GPIO_Mode_Out_PP_Low_Slow  = (uint8_t)0xC0,   /*!< Output push-pull, low level, 2MHz */
//  GPIO_Mode_Out_OD_HiZ_Fast  = (uint8_t)0xB0,   /*!< Output open-drain, high-impedance level, 10MHz */
//  GPIO_Mode_Out_PP_High_Fast = (uint8_t)0xF0,   /*!< Output push-pull, high level, 10MHz */
//  GPIO_Mode_Out_OD_HiZ_Slow  = (uint8_t)0x90,   /*!< Output open-drain, high-impedance level, 2MHz */
//  GPIO_Mode_Out_PP_High_Slow = (uint8_t)0xD0    /*!< Output push-pull, high level, 2MHz */
//===���͹���˵������I/Oû�ã�������Input pull-up    ��I/O��Χ��IC����û�ã�������Input floating=====

void VHF_GPIO_INIT(void){					// CPU�˿�����
/****************�˿�����˵��***************************
CR1�Ĵ���  ��� Output��1=���졢0=OC��
           ���� Input��1=������0=������
***************end************************************/  
  
       Receiver_vent=1;    //���Ż���������ON/OFF
       Inverters_OUT=1;    //�̵�������ź��Ƿ���  
  
       ADF7021_SCLK_direc = Output;
       ADF7021_SCLK_CR1 = 1;
       ADF7021_SCLK=0;
       
       ADF7021_SDATA_direc = Output;
       ADF7021_SDATA_CR1=1;
       ADF7021_SDATA=0;
       
       ADF7021_SLE_direc = Output;
       ADF7021_SLE_CR1=1;
       ADF7021_SLE=0;
       
       ADF7021_SREAD_direc = Input;
       ADF7021_SREAD_CR1=1;
       
       ADF7021_CE_direc = Output;
       ADF7021_CE_CR1=1;
       ADF7021_CE=0;
       
       ADF7021_MUXOUT_direc = Input;
       ADF7021_MUXOUT_CR1=1;
       
       ADF7021_DATA_CLK_direc = Input;
       ADF7021_DATA_CLK_CR1=1;
       
       ADF7021_DATA_direc = Input;
       ADF7021_DATA_CR1=1;
       
//      HA_L_signal_direc = Input; // Input   HA �����ź�   �͵�ƽ��Ч
//      HA_L_signal_CR1=1;
//      
//      HA_ERR_signal_direc = Input;// Input   HA �쳣�ź�  �͵�ƽ��Ч
//      HA_ERR_signal_CR1=1;
//      
//      HA_Sensor_signal_direc = Input;// Input   HA �������ź�  �͵�ƽ��Ч
//      HA_Sensor_signal_CR1=1;
//        
////      Receiver_Buzzer_direc = Output;// Output   ���Ż�������  �ߵ�ƽ��Ч
////      Receiver_Buzzer_CR1=1;
////      Receiver_Buzzer=0;
//      Receiver_vent_direc = Input;// Input   ���Ż���������ON/OFF
//      Receiver_vent_CR1=1;     
//
//      Inverters_OUT_direc=Input;    // ����   �̵�������źŷ���   �͵�ƽ��Ч
//      Inverters_OUT_CR1=1; 
      if(Inverters_OUT==1){FG_allow_out=1;FG_NOT_allow_out=0;}
      else {FG_allow_out=0;FG_NOT_allow_out=1;}     
//      
//      Receiver_LED_TX_direc = Output;// Output   ���Ż�����ָʾ  �ߵ�ƽ��Ч
//      Receiver_LED_TX_CR1=1;
//      Receiver_LED_TX=0;   
//
//      Receiver_LED_OUT_direc = Output;// Output   ���Ż��̵����������  �ߵ�ƽ��Ч
//      Receiver_LED_OUT_CR1=1;
//      Receiver_LED_OUT=1;
//            
//      Receiver_LED_RX_direc = Output;// Output   ���Ż�����ָʾ  �ߵ�ƽ��Ч
//      Receiver_LED_RX_CR1=1;
//      Receiver_LED_RX=0;       
       
      Receiver_Login_direc = Input;// Input   ���Ż���¼��   �͵�ƽ��Ч
      Receiver_Login_CR1=1;       
      
      PIN_BEEP_direc = Output;    // Output   ������
      PIN_BEEP_CR1 = 1;
      PIN_BEEP=0;      
            
      Receiver_OUT_OPEN_direc = Output;  // Output   ���Ż��̵���OPEN  �ߵ�ƽ��Ч
      Receiver_OUT_OPEN_CR1=1;
      Receiver_OUT_OPEN=FG_NOT_allow_out;
      
      Receiver_OUT_CLOSE_direc = Output;  // Output   ���Ż��̵���CLOSE  �ߵ�ƽ��Ч
      Receiver_OUT_CLOSE_CR1=1;
      Receiver_OUT_CLOSE=FG_NOT_allow_out;
      
      Receiver_OUT_STOP_direc = Output;  // Output   ���Ż��̵���STOP  �ߵ�ƽ��Ч
      Receiver_OUT_STOP_CR1=1;
      Receiver_OUT_STOP=FG_NOT_allow_out;
      
      Receiver_OUT_VENT_direc = Output;
      Receiver_OUT_VENT_CR1=1;
      Receiver_OUT_VENT=FG_NOT_allow_out;
      
      Receiver_test_direc=Input;    // ����     test��
      Receiver_test_CR1=1;
      
      
      
      
      MOTOR_left_right_bit0_direc=Input;   // Input   �����װλ������ѡ��   �͵�ƽ��Ч
      MOTOR_left_right_bit0_CR1=1;
      MOTOR_left_right_bit1_direc=Input;   // Input     �����װλ������ѡ��  �͵�ƽ��Ч
      MOTOR_left_right_bit1_CR1=1;
      PIN_KEY_DOWN_direc=Input;   // net key2   Input   
      PIN_KEY_DOWN_CR1=1;
      PIN_KEY_UP_direc=Input;   // net key4   ����
      PIN_KEY_UP_CR1=1;
      PIN_KEY_MODE_direc=Input;    // net key3   Input  
      PIN_KEY_MODE_CR1=1;
      
      KEY_ENT_direc=Input;       // net key2   Input 
      KEY_ENT_CR1=1;
      
      KEY_BEAM_sensor_direc=Input;       // net key5   Input 
      KEY_BEAM_sensor_CR1=1;

      LED_SEL1_direc = Output;
      LED_SEL1_CR1=1;
      LED_SEL1=1; 
      LED_SEL2_direc = Output;
      LED_SEL2_CR1=1;
      LED_SEL2=1;       
      LED_SEL3_direc = Output;
      LED_SEL3_CR1=1;
      LED_SEL3=1;  
      
      LED_DATA_direc = 0xff;
      LED_DATA_CR1=0xff;
      LED_DATA=0xff;          
}
//============================================================================================
void SysClock_Init( void ){ 				// ϵͳʱ�ӣ��ⲿʱ�ӣ�
//    /* Infinite loop */
//    CLK_DeInit();                                         //ʱ�ӻָ�Ĭ��
//    CLK_HSICmd(ENABLE);
//    while(CLK_GetFlagStatus(CLK_FLAG_HSIRDY)==RESET);//�ȴ�ֱ��LSI�ȶ� 
////    CLK_HSEConfig(CLK_HSE_ON);
////    CLK_HSEConfig(CLK_HSE_ON);
////    while(CLK_GetFlagStatus(CLK_FLAG_HSERDY)==RESET);//�ȴ�ֱ��HSE�ȶ� 
//    CLK_SYSCLKSourceSwitchCmd(ENABLE);
////    CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSE);
//    CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSI);
//    CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);
//    CLK_SYSCLKSourceSwitchCmd(DISABLE);
////    CLK_LSICmd(ENABLE);
////    while(CLK_GetFlagStatus(CLK_FLAG_LSIRDY)==RESET);//�ȴ�ֱ��LSI�ȶ� 
////    CLK_HSEConfig(CLK_HSE_OFF);
////    CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_LSI);
////    CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);
////    CLK_SYSCLKSourceSwitchCmd(DISABLE);    
//    
//    //CLK_LSICmd(ENABLE);   //ʹ��LSIʱ�Ӹ����Ź���
//    //while(CLK_GetFlagStatus(CLK_FLAG_LSIRDY)==RESET);//�ȴ�ֱ��LSI�ȶ� 
  
  
	CLK_ICKCR_HSION = 1;				// ʹ���ڲ�RC OSC��16.00MHz��
	while(( CLK_ICKCR & 0x02 ) == 0 );		// ����ڲ����� 
	CLK_SWR = 0x01;					// ָ��HSIΪ��ʱ�� 
//	while(( CLK_SWCR & 0x08 ) == 0 );		// �ȴ�HSI�л� 
	CLK_SWCR_SWEN = 1;						// ִ���л�
	CLK_CKDIVR = 0x00;		// ����ʱ�ӷ�Ƶ  f HSI= f HSI RC���/1    f CPU= f MASTER
	//---------------------------------------- ����  
	//CLK_PCKENR1 = 0x84;						// T1,UART1
	CLK_PCKENR1 = 0x64;						// T4,UART1,beep
	CLK_PCKENR2 = 0x03;						// ADC,T1	
	
	CLK_ICKCR_LSION = 1;				// ʹ���ڲ�LSI OSC��38KHz��
	while(CLK_ICKCR_LSIRDY == 0 );		// ����ڲ�LSI OSC 	
}


void beep_init( void )
{ 	
     //BEEP_CSR=0x4E; 
  BEEP_CSR2=0;
  BEEP_CSR2_BEEPDIV=3;
  BEEP_CSR2_BEEPSEL=1; 
  CLK_CBEEPR_CLKBEEPSEL0=1;
  CLK_CBEEPR_CLKBEEPSEL1=0;
}

//===================Delayus()��ʱ===============//    Crystal: 16M HSI
void Delayus(unsigned char timer)
{
unsigned char x;                   //��ʱT=((timer-1)*0.313+2 us
 for(x=0;x<timer;x++)
     __asm("nop");
}


void RF_test_mode(void )
{
  //UINT8 uart_data,Boot_i;
   UINT8 uart_data;

  BEEP_CSR2_BEEPEN=0;
  Receiver_LED_OUT=0;
  UART_pact_select=0;
  
  
   
    while(Receiver_test==0){
        UART_pact_select=1;
        ClearWDT(); // Service the WDT	
        //if(HA_ERR_signal==0){      //test ADF7021 TX 
	if(MOTOR_left_right_bit1==0){
	  if(MOTOR_left_right_bit0==0)Tx_Rx_mode=0;
	  else Tx_Rx_mode=1;
	}
	else{
	  if(MOTOR_left_right_bit0==0)Tx_Rx_mode=2;
	  else Tx_Rx_mode=3;
	}
	if((Tx_Rx_mode==0)||(Tx_Rx_mode==1)){ 
	  FG_test_rx=0;
	  Receiver_LED_RX=0;
	  FG_test_tx_off=0;
	  //if(HA_L_signal==0){    //���ز����޵����ź�
	  if(Tx_Rx_mode==0){
	    Receiver_LED_OUT=1;
	    FG_test_mode=0;
	    FG_test_tx_1010=0;
	    if(FG_test_tx_on==0){FG_test_tx_on=1;ADF7021_DATA_direc=Input;dd_set_TX_mode_carrier();}
	  }   
	  else {    //���ز����е����ź�
	    if(TIMER1s==0){
	      TIMER1s=500;
	      Receiver_LED_OUT=!Receiver_LED_OUT;
	    }
	    FG_test_mode=1;
	    FG_test_tx_on=0;
	    if(FG_test_tx_1010==0){FG_test_tx_1010=1;ADF7021_DATA_direc=Output;dd_set_TX_mode_1010pattern();}
	  }
	}
        //else  {           //test ADF7021 RX
	if((Tx_Rx_mode==2)||(Tx_Rx_mode==3)){
	  FG_test_rx=1;
	  Receiver_LED_OUT=0;
	  FG_test_mode=0;
	  FG_test_tx_on=0;
	  FG_test_tx_1010=0;
	  if(FG_test_tx_off==0){FG_test_tx_off=1;
                                dd_set_RX_mode_test();
                                ADF7021_DATA_direc=Input;
                               }
	  //if(HA_L_signal==0){
	  if(Tx_Rx_mode==2)	    
	    if(TIMER1s==0){
	      TIMER1s=500;
	      Receiver_LED_RX=!Receiver_LED_RX;
              LED_display_page("  .",0,0,0x80,500,1);
	    }
	  if(Tx_Rx_mode==3){    
            if(X_COUNT >= 1200){
              X_COUNT = 0;    
	      if(X_ERR>=60){Receiver_LED_RX=0;LED_display_page("   ",0,0,0,0,0);}
	      else {Receiver_LED_RX=1;LED_display_page("  .",0,0,0,0,0);}
              uart_data = (X_ERR/1000) + 48;//48;//��X_ERR/1000) + 48;
	      Send_char(uart_data);
              X_ERR = X_ERR%1000;
              uart_data = (X_ERR/100) + 48;//X_ERR/256;
	      Send_char(uart_data);
              X_ERR = X_ERR%100;
              uart_data =(X_ERR/10) + 48;
	      Send_char(uart_data);
              X_ERR = X_ERR%10;
              uart_data = X_ERR +48;
	      Send_char(uart_data);
              uart_data = 13;//|�ַ�
	      Send_char(uart_data);
              X_ERR = 0;
            }	    
	  }
	}
	PC_PRG();	       // PC���� 
        
    }
    UART1_end();
    UART_pact_select=0;

    
    
  Receiver_LED_OUT=1;
  FG_beep_on=0;
  FG_beep_off=0;
  BEEP_CSR2_BEEPEN=1;
  
//  for(Boot_i=0;Boot_i<2;Boot_i++){    
//      for(time_3sec=0;time_3sec<6000;time_3sec++){
//         Delayus(250);   //80us
//         ClearWDT(); // Service the WDT
//      }
//      Receiver_LED_OUT=!Receiver_LED_OUT;    
//  }
  
    
  for(time_3sec=0;time_3sec<4000;time_3sec++){
     Delayus(250);   //80us
     ClearWDT(); // Service the WDT
  }
  
  BEEP_CSR2_BEEPEN=0;
  Receiver_LED_OUT=0;
  
  UART1_INIT();
    
    FG_test_rx=0;
    TIMER1s=0;
    //Receiver_LED_TX=0;
    Receiver_LED_RX=0;
    FG_Receiver_LED_RX=0;
    Receiver_LED_OUT=0;  
    
    FLAG_APP_RX=1;
    dd_set_RX_mode();
    TIME_Fine_Calibration=9000;
    TIME_EMC=10;    
}

