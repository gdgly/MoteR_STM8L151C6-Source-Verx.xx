/***********************************************************************/
/*  File Name   :Pin_Define.h                                          */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/

//#define __SOFT_Ver1__       //hardware����PCB 3.4.3��   PCB��������
#define __SOFT_Ver2__       //hardware����CY-1601 OP-0401��   PCB�����ݰ壬����I/O�б䶯

//������IO����

#if defined(__SOFT_Ver1__)
/******************������data�Ĵ���************************************/
/* ADF7012 register interface */
#define ADF7021_SCLK            PB_ODR_ODR4     // Output   ʱ����
#define ADF7021_SDATA           PB_ODR_ODR6     // Output   ������
#define ADF7021_SLE             PB_ODR_ODR7     // Output   Ƭѡ
#define ADF7021_SREAD           PB_IDR_IDR5     // Input
#define ADF7021_CE              PD_ODR_ODR4     // Output   ADF7012ʹ�ܽ�
#define ADF7021_MUXOUT          PB_IDR_IDR1    // Input

/* Other ADF7021 connections */
#define ADF7021_DATA_tx         PB_ODR_ODR3     // Output   ����DATA��
#define ADF7021_DATA_rx         PB_IDR_IDR3     // Input   ����DATA��
#define ADF7021_DATA_CLK        PB_IDR_IDR2     // ����   ����ͬ��ʱ����


     /* ���Ż�ʹ�õ�IO*/
#define Receiver_Login          PC_IDR_IDR6    // Input   ���Ż���¼��   �͵�ƽ��Ч
//#define Receiver_Buzzer         PC_ODR_ODR5  // Output   ���Ż�������  �ߵ�ƽ��Ч
//#define Receiver_vent           PC_IDR_IDR5    // Input   ���Ż���������ON/OFF	  
#define PIN_BEEP                PA_ODR_ODR0     // Output   ������
#define Receiver_LED_OUT        PC_ODR_ODR4  // Output   ���Ż��̵����������  �ߵ�ƽ��Ч
//#define Receiver_LED_TX         PC_ODR_ODR1 // Output   ���Ż�����ָʾ  �ߵ�ƽ��Ч
#define Receiver_LED_RX         PC_ODR_ODR0  // Output   ���Ż�����ָʾ  �ߵ�ƽ��Ч
#define Receiver_OUT_OPEN       PD_ODR_ODR3  // Output   ���Ż��̵���OPEN  �ߵ�ƽ��Ч
#define Receiver_OUT_CLOSE      PD_ODR_ODR2  // Output   ���Ż��̵���close  �ߵ�ƽ��Ч
#define Receiver_OUT_STOP       PD_ODR_ODR1  // Output   ���Ż��̵���stop  �ߵ�ƽ��Ч
#define Receiver_OUT_VENT       PD_ODR_ODR0   // Output ���Ż��̵���VENT  �ߵ�ƽ��Ч
//#define Inverters_OUT           PA_IDR_IDR2     // ����   �̵�������źŷ���   �͵�ƽ��Ч

#define MOTOR_left_right_bit0   PA_IDR_IDR4      // Input   �����װλ������ѡ��   �͵�ƽ��Ч
#define MOTOR_left_right_bit1   PA_IDR_IDR5    // Input     �����װλ������ѡ��  �͵�ƽ��Ч
#define KEY_DOWN                PA_IDR_IDR3    // net key4   Input   
#define KEY_UP                  PA_IDR_IDR2    // net key3   ����
#define KEY_MODE                PC_IDR_IDR5    // net key1   Input 

#define KEY_ENT                 PC_IDR_IDR7    // net key2   Input 
#define KEY_BEAM_sensor         PA_IDR_IDR6    // net key5   Input
#define LED_SEL1                PD_ODR_ODR7  // Output
#define LED_SEL2                PD_ODR_ODR6  // Output
#define LED_SEL3                PD_ODR_ODR5  // Output
#define LED_DATA                PE_ODR       // Output

#define  Receiver_test          PB_IDR_IDR0    // Input ���Ż����Խ�  �ߵ�ƽ��Ч

/************************�����Ƿ���Ĵ���*****************************/
/* ADF7012 register interface */
#define ADF7021_SCLK_direc      PB_DDR_DDR4     // Output   ʱ����
#define ADF7021_SDATA_direc     PB_DDR_DDR6     // Output   ������
#define ADF7021_SLE_direc       PB_DDR_DDR7     // Output   Ƭѡ
#define ADF7021_SREAD_direc     PB_DDR_DDR5     // Input
#define ADF7021_CE_direc        PD_DDR_DDR4     // Output   ADF7012ʹ�ܽ�
#define ADF7021_MUXOUT_direc    PB_DDR_DDR1    // Input

/* Other ADF7021 connections */
#define ADF7021_DATA_direc      PB_DDR_DDR3     // Output/Input   ����DATA��
#define ADF7021_DATA_IO         PB_DDR_DDR3     // Output/Input   ����DATA��
#define ADF7021_DATA_CLK_direc  PB_DDR_DDR2     // ����   ����ͬ��ʱ����


     /* ���Ż�ʹ�õ�IO*/
#define HA_L_signal_direc       PA_DDR_DDR4      // Input   HA �����ź�   �͵�ƽ��Ч
#define HA_ERR_signal_direc     PA_DDR_DDR5    // Input   HA �쳣�ź�  �͵�ƽ��Ч
#define HA_Sensor_signal_direc  PA_DDR_DDR3    // Input   HA �������ź�  �͵�ƽ��Ч
#define Receiver_Login_direc    PC_DDR_DDR6    // Input   ���Ż���¼��   �͵�ƽ��Ч
//#define Receiver_Buzzer_direc   PC_DDR_DDR5  // Output   ���Ż�������  �ߵ�ƽ��Ч
#define Receiver_vent_direc     PC_DDR_DDR5  // Input   ���Ż���������ON/OFF
#define PIN_BEEP_direc          PA_DDR_DDR0     // Output   ������
#define Receiver_LED_OUT_direc  PC_DDR_DDR4  // Output   ���Ż��̵����������  �ߵ�ƽ��Ч
//#define Receiver_LED_TX_direc   PC_DDR_DDR1 // Output   ���Ż�����ָʾ  �ߵ�ƽ��Ч
#define Receiver_LED_RX_direc   PC_DDR_DDR0  // Output   ���Ż�����ָʾ  �ߵ�ƽ��Ч
#define Receiver_OUT_OPEN_direc PD_DDR_DDR3  // Output   ���Ż��̵���OPEN  �ߵ�ƽ��Ч
#define Receiver_OUT_CLOSE_direc PD_DDR_DDR2  // Output   ���Ż��̵���close  �ߵ�ƽ��Ч
#define Receiver_OUT_STOP_direc PD_DDR_DDR1  // Output   ���Ż��̵���stop  �ߵ�ƽ��Ч
#define Receiver_OUT_VENT_direc PD_DDR_DDR0   // Output ���Ż��̵���VENT  �ߵ�ƽ��Ч
#define Inverters_OUT_direc     PA_DDR_DDR2     // ����   �̵�������źŷ���   �͵�ƽ��Ч


#define KEY_ENT_direc              PC_DDR_DDR7    // net key2   Input 
#define KEY_BEAM_sensor_direc      PA_DDR_DDR6    // net key5   Input
#define LED_SEL1_direc             PD_DDR_DDR7  // Output
#define LED_SEL2_direc             PD_DDR_DDR6  // Output
#define LED_SEL3_direc             PD_DDR_DDR5  // Output
#define LED_DATA_direc             PE_DDR       // Output


#define Receiver_test_direc     PB_DDR_DDR0    // Input ���Ż����Խ�  �ߵ�ƽ��Ч

/************************�����ǿ��ƼĴ���*****************************/
/* ADF7012 register interface */
#define ADF7021_SCLK_CR1        PB_CR1_C14     // Output   ʱ����
#define ADF7021_SDATA_CR1       PB_CR1_C16     // Output   ������
#define ADF7021_SLE_CR1         PB_CR1_C17     // Output   Ƭѡ
#define ADF7021_SREAD_CR1       PB_CR1_C15     // Input
#define ADF7021_CE_CR1          PD_CR1_C14     // Output   ADF7012ʹ�ܽ�
#define ADF7021_MUXOUT_CR1      PB_CR1_C11    // Input

/* Other ADF7021 connections */
#define ADF7021_DATA_CR1        PB_CR1_C13     // Output/Input   ����DATA��
#define ADF7021_DATA_CLK_CR1    PB_CR1_C12     // ����   ����ͬ��ʱ����


     /* ���Ż�ʹ�õ�IO*/
#define HA_L_signal_CR1         PA_CR1_C14      // Input   HA �����ź�   �͵�ƽ��Ч
#define HA_ERR_signal_CR1       PA_CR1_C15    // Input   HA �쳣�ź�  �͵�ƽ��Ч
#define HA_Sensor_signal_CR1    PA_CR1_C13    // Input   HA �������ź�  �͵�ƽ��Ч
#define Receiver_Login_CR1      PC_CR1_C16    // Input   ���Ż���¼��   �͵�ƽ��Ч
//#define Receiver_Buzzer_CR1     PC_CR1_C15  // Output   ���Ż�������  �ߵ�ƽ��Ч
#define Receiver_vent_CR1       PC_CR1_C15  // Input   ���Ż���������ON/OFF
#define PIN_BEEP_CR1            PA_CR1_C10     // Output   ������
#define Receiver_LED_OUT_CR1    PC_CR1_C14  // Output   ���Ż��̵����������  �ߵ�ƽ��Ч
//#define Receiver_LED_TX_CR1     PC_CR1_C11 // Output   ���Ż�����ָʾ  �ߵ�ƽ��Ч
#define Receiver_LED_RX_CR1     PC_CR1_C10  // Output   ���Ż�����ָʾ  �ߵ�ƽ��Ч
#define Receiver_OUT_OPEN_CR1   PD_CR1_C13  // Output   ���Ż��̵���OPEN  �ߵ�ƽ��Ч
#define Receiver_OUT_CLOSE_CR1  PD_CR1_C12  // Output   ���Ż��̵���close  �ߵ�ƽ��Ч
#define Receiver_OUT_STOP_CR1   PD_CR1_C11  // Output   ���Ż��̵���stop  �ߵ�ƽ��Ч
#define Receiver_OUT_VENT_CR1   PD_CR1_C10   // Output ���Ż��̵���VENT  �ߵ�ƽ��Ч
#define Inverters_OUT_CR1       PA_CR1_C12     // ����   �̵�������źŷ���   �͵�ƽ��Ч

#define Receiver_test_CR1       PB_CR1_C10    // Input ���Ż����Խ�  �ߵ�ƽ��Ч


#define KEY_ENT_CR1                 PC_CR1_C17    // net key2   Input 
#define KEY_BEAM_sensor_CR1         PA_CR1_C16    // net key5   Input
#define LED_SEL1_CR1                PD_CR1_C17  // Output
#define LED_SEL2_CR1                PD_CR1_C16  // Output
#define LED_SEL3_CR1                PD_CR1_C15  // Output
#define LED_DATA_CR1                PE_CR1       // Output


#define ADF7021_DATA_CLK_CR2    PB_CR2_C22     // ����   ����ͬ��ʱ����

#endif








#if defined(__SOFT_Ver2__)
/******************������data�Ĵ���************************************/
/* ADF7012 register interface */
#define ADF7021_SCLK            PB_ODR_ODR4     // Output   ʱ����
#define ADF7021_SDATA           PB_ODR_ODR6     // Output   ������
#define ADF7021_SLE             PB_ODR_ODR7     // Output   Ƭѡ
#define ADF7021_SREAD           PB_IDR_IDR5     // Input
#define ADF7021_CE              PD_ODR_ODR4     // Output   ADF7012ʹ�ܽ�
#define ADF7021_MUXOUT          PB_IDR_IDR1    // Input

/* Other ADF7021 connections */
#define ADF7021_DATA_tx         PB_ODR_ODR3     // Output   ����DATA��
#define ADF7021_DATA_rx         PB_IDR_IDR3     // Input   ����DATA��
#define ADF7021_DATA_CLK        PB_IDR_IDR2     // ����   ����ͬ��ʱ����


     /* ���Ż�ʹ�õ�IO*/
#define Receiver_Login          PA_IDR_IDR6    // Input   ���Ż���¼��   �͵�ƽ��Ч
//#define Receiver_Buzzer         PC_ODR_ODR5  // Output   ���Ż�������  �ߵ�ƽ��Ч
//#define Receiver_vent           PC_IDR_IDR5    // Input   ���Ż���������ON/OFF	  
#define PIN_BEEP                PA_ODR_ODR0     // Output   ������
#define Receiver_LED_OUT        PC_ODR_ODR4  // Output   ���Ż��̵����������  �ߵ�ƽ��Ч
//#define Receiver_LED_TX         PC_ODR_ODR1 // Output   ���Ż�����ָʾ  �ߵ�ƽ��Ч
#define Receiver_LED_RX         PC_ODR_ODR0  // Output   ���Ż�����ָʾ  �ߵ�ƽ��Ч
#define Receiver_OUT_OPEN       PD_ODR_ODR3  // Output   ���Ż��̵���OPEN  �ߵ�ƽ��Ч
#define Receiver_OUT_CLOSE      PD_ODR_ODR2  // Output   ���Ż��̵���close  �ߵ�ƽ��Ч
#define Receiver_OUT_STOP       PD_ODR_ODR1  // Output   ���Ż��̵���stop  �ߵ�ƽ��Ч
#define Receiver_OUT_VENT       PD_ODR_ODR0   // Output ���Ż��̵���VENT  �ߵ�ƽ��Ч
//#define Inverters_OUT           PA_IDR_IDR2     // ����   �̵�������źŷ���   �͵�ƽ��Ч

#define MOTOR_left_right_bit0   PA_IDR_IDR4      // Input   �����װλ������ѡ��   �͵�ƽ��Ч
#define MOTOR_left_right_bit1   PA_IDR_IDR5    // Input     �����װλ������ѡ��  �͵�ƽ��Ч
#define KEY_DOWN                PA_IDR_IDR7    // net key2   Input   
#define KEY_UP                  PA_IDR_IDR3    // net key4   ����
#define KEY_MODE                PD_IDR_IDR6    // net key3   Input 

#define KEY_ENT                 PD_IDR_IDR5    // net key1   Input 
#define KEY_BEAM_sensor         PA_IDR_IDR2    // net key5   Input
#define LED_SEL1                PD_ODR_ODR7  // Output
#define LED_SEL2                PC_ODR_ODR5  // Output
#define LED_SEL3                PC_ODR_ODR7  // Output
#define LED_DATA                PE_ODR       // Output

#define  Receiver_test          PB_IDR_IDR0    // Input ���Ż����Խ�  �ߵ�ƽ��Ч

/************************�����Ƿ���Ĵ���*****************************/
/* ADF7012 register interface */
#define ADF7021_SCLK_direc      PB_DDR_DDR4     // Output   ʱ����
#define ADF7021_SDATA_direc     PB_DDR_DDR6     // Output   ������
#define ADF7021_SLE_direc       PB_DDR_DDR7     // Output   Ƭѡ
#define ADF7021_SREAD_direc     PB_DDR_DDR5     // Input
#define ADF7021_CE_direc        PD_DDR_DDR4     // Output   ADF7012ʹ�ܽ�
#define ADF7021_MUXOUT_direc    PB_DDR_DDR1    // Input

/* Other ADF7021 connections */
#define ADF7021_DATA_direc      PB_DDR_DDR3     // Output/Input   ����DATA��
#define ADF7021_DATA_IO         PB_DDR_DDR3     // Output/Input   ����DATA��
#define ADF7021_DATA_CLK_direc  PB_DDR_DDR2     // ����   ����ͬ��ʱ����


     /* ���Ż�ʹ�õ�IO*/
#define HA_L_signal_direc       PA_DDR_DDR4      // Input   HA �����ź�   �͵�ƽ��Ч
#define HA_ERR_signal_direc     PA_DDR_DDR5    // Input   HA �쳣�ź�  �͵�ƽ��Ч
#define Receiver_Login_direc    PA_DDR_DDR6    // Input   ���Ż���¼��   �͵�ƽ��Ч
#define PIN_BEEP_direc          PA_DDR_DDR0     // Output   ������
#define Receiver_LED_OUT_direc  PC_DDR_DDR4  // Output   ���Ż��̵����������  �ߵ�ƽ��Ч
#define Receiver_LED_RX_direc   PC_DDR_DDR0  // Output   ���Ż�����ָʾ  �ߵ�ƽ��Ч
#define Receiver_OUT_OPEN_direc PD_DDR_DDR3  // Output   ���Ż��̵���OPEN  �ߵ�ƽ��Ч
#define Receiver_OUT_CLOSE_direc PD_DDR_DDR2  // Output   ���Ż��̵���close  �ߵ�ƽ��Ч
#define Receiver_OUT_STOP_direc PD_DDR_DDR1  // Output   ���Ż��̵���stop  �ߵ�ƽ��Ч
#define Receiver_OUT_VENT_direc PD_DDR_DDR0   // Output ���Ż��̵���VENT  �ߵ�ƽ��Ч


#define HA_Sensor_signal_direc  PA_DDR_DDR7    // Input   HA �������ź�  �͵�ƽ��Ч
#define Inverters_OUT_direc     PA_DDR_DDR3     // ����   �̵�������źŷ���   �͵�ƽ��Ч
#define Receiver_vent_direc     PD_DDR_DDR6  // Input   ���Ż���������ON/OFF

#define KEY_ENT_direc              PD_DDR_DDR5    // net key2   Input 
#define KEY_BEAM_sensor_direc      PA_DDR_DDR2    // net key5   Input
#define LED_SEL1_direc             PD_DDR_DDR7  // Output
#define LED_SEL2_direc             PC_DDR_DDR5  // Output
#define LED_SEL3_direc             PC_DDR_DDR7  // Output
#define LED_DATA_direc             PE_DDR       // Output


#define Receiver_test_direc     PB_DDR_DDR0    // Input ���Ż����Խ�  �ߵ�ƽ��Ч

/************************�����ǿ��ƼĴ���*****************************/
/* ADF7012 register interface */
#define ADF7021_SCLK_CR1        PB_CR1_C14     // Output   ʱ����
#define ADF7021_SDATA_CR1       PB_CR1_C16     // Output   ������
#define ADF7021_SLE_CR1         PB_CR1_C17     // Output   Ƭѡ
#define ADF7021_SREAD_CR1       PB_CR1_C15     // Input
#define ADF7021_CE_CR1          PD_CR1_C14     // Output   ADF7012ʹ�ܽ�
#define ADF7021_MUXOUT_CR1      PB_CR1_C11    // Input

/* Other ADF7021 connections */
#define ADF7021_DATA_CR1        PB_CR1_C13     // Output/Input   ����DATA��
#define ADF7021_DATA_CLK_CR1    PB_CR1_C12     // ����   ����ͬ��ʱ����


     /* ���Ż�ʹ�õ�IO*/
#define HA_L_signal_CR1         PA_CR1_C14      // Input   HA �����ź�   �͵�ƽ��Ч
#define HA_ERR_signal_CR1       PA_CR1_C15    // Input   HA �쳣�ź�  �͵�ƽ��Ч
#define Receiver_Login_CR1      PA_CR1_C16    // Input   ���Ż���¼��   �͵�ƽ��Ч
#define PIN_BEEP_CR1            PA_CR1_C10     // Output   ������
#define Receiver_LED_OUT_CR1    PC_CR1_C14  // Output   ���Ż��̵����������  �ߵ�ƽ��Ч
#define Receiver_LED_RX_CR1     PC_CR1_C10  // Output   ���Ż�����ָʾ  �ߵ�ƽ��Ч
#define Receiver_OUT_OPEN_CR1   PD_CR1_C13  // Output   ���Ż��̵���OPEN  �ߵ�ƽ��Ч
#define Receiver_OUT_CLOSE_CR1  PD_CR1_C12  // Output   ���Ż��̵���close  �ߵ�ƽ��Ч
#define Receiver_OUT_STOP_CR1   PD_CR1_C11  // Output   ���Ż��̵���stop  �ߵ�ƽ��Ч
#define Receiver_OUT_VENT_CR1   PD_CR1_C10   // Output ���Ż��̵���VENT  �ߵ�ƽ��Ч


#define Receiver_test_CR1       PB_CR1_C10    // Input ���Ż����Խ�  �ߵ�ƽ��Ч


#define Inverters_OUT_CR1       PA_CR1_C13     // ����   �̵�������źŷ���   �͵�ƽ��Ч
#define Receiver_vent_CR1       PD_CR1_C16  // Input   ���Ż���������ON/OFF
#define HA_Sensor_signal_CR1    PA_CR1_C17    // Input   HA �������ź�  �͵�ƽ��Ч

#define KEY_ENT_CR1                 PD_CR1_C15    // net key2   Input 
#define KEY_BEAM_sensor_CR1         PA_CR1_C12    // net key5   Input
#define LED_SEL1_CR1                PD_CR1_C17  // Output
#define LED_SEL2_CR1                PC_CR1_C15  // Output
#define LED_SEL3_CR1                PC_CR1_C17  // Output
#define LED_DATA_CR1                PE_CR1       // Output


#define ADF7021_DATA_CLK_CR2    PB_CR2_C22     // ����   ����ͬ��ʱ����

#endif