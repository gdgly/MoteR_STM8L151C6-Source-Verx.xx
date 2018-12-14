/***********************************************************************/
/*  FILE        :ram.h                                                 */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/



extern volatile union{
	unsigned char BYTE;	
	struct { 
		unsigned char	Bit0:	1;
		unsigned char	Bit1:	1;
		unsigned char	Bit2:	1;
		unsigned char	Bit3:	1;
		unsigned char	Bit4:	1;
		unsigned char	Bit5:	1;
		unsigned char	Bit6:	1;
		unsigned char	Bit7:	1;
	}BIT; 	
}FLAG0;
	//************************************************
	#define 	FLAG0_BYTE		FLAG0.BYTE	 
	//------------------------------------------------
        #define		FLAG_Receiver_IDCheck	FLAG0.BIT.Bit0
        #define		FLAG_Signal_DATA_OK	FLAG0.BIT.Bit1
        #define		FLAG_APP_RX		FLAG0.BIT.Bit2
        #define		FLAG_IDCheck_OK		FLAG0.BIT.Bit3
        #define		FLAG_ID_Erase_Login	FLAG0.BIT.Bit4
        #define		FLAG_ID_Erase_Login_PCS	FLAG0.BIT.Bit5
        #define		FLAG_ID_Login	        FLAG0.BIT.Bit6
        #define		FLAG_ID_Login_OK	FLAG0.BIT.Bit7
	//************************************************

extern volatile union{
	unsigned char BYTE;	
	struct { 
		unsigned char	Bit0:	1;
		unsigned char	Bit1:	1;
		unsigned char	Bit2:	1;
		unsigned char	Bit3:	1;
		unsigned char	Bit4:	1;
		unsigned char	Bit5:	1;
		unsigned char	Bit6:	1;
		unsigned char	Bit7:	1;
	}BIT; 	
}FLAG1;
	//************************************************
	#define 	FLAG1_BYTE		FLAG1.BYTE	 
	//------------------------------------------------
        #define		FLAG_Receiver_BEEP	FLAG1.BIT.Bit0
        #define		FLAG_ID_Login_EXIT	FLAG1.BIT.Bit1
        #define		FLAG_ID_Login_OK_bank	FLAG1.BIT.Bit2
        #define		FG_beep_on		FLAG1.BIT.Bit3            
        #define		FG_beep_off	        FLAG1.BIT.Bit4           
        #define		FG_allow_out	        FLAG1.BIT.Bit5
        #define		FG_NOT_allow_out	FLAG1.BIT.Bit6
        #define		FG_10ms		        FLAG1.BIT.Bit7
	//************************************************

extern volatile union{
	unsigned char BYTE;	
	struct { 
		unsigned char	Bit0:	1;
		unsigned char	Bit1:	1;
		unsigned char	Bit2:	1;
		unsigned char	Bit3:	1;
		unsigned char	Bit4:	1;
		unsigned char	Bit5:	1;
		unsigned char	Bit6:	1;
		unsigned char	Bit7:	1;
	}BIT; 	
}FLAG_test;
	//************************************************
	#define 	FLAG_test_BYTE		FLAG_test.BYTE	 
	//------------------------------------------------
        #define		FLAG_Receiver_Scanning	FLAG_test.BIT.Bit0
        #define		FG_test_tx_1010	        FLAG_test.BIT.Bit1
        #define		X_HIS	                FLAG_test.BIT.Bit2    //历史记录   误码率测试用
        #define		FG_test_tx_on		FLAG_test.BIT.Bit3          
        #define		FG_test_tx_off	        FLAG_test.BIT.Bit4          
        #define		FG_test_mode	        FLAG_test.BIT.Bit5
        #define		FG_test1	        FLAG_test.BIT.Bit6
        #define		FG_test_rx		FLAG_test.BIT.Bit7
	//************************************************

extern volatile union{
	unsigned char BYTE;	
	struct { 
		unsigned char	Bit0:	1;
		unsigned char	Bit1:	1;
		unsigned char	Bit2:	1;
		unsigned char	Bit3:	1;
		unsigned char	Bit4:	1;
		unsigned char	Bit5:	1;
		unsigned char	Bit6:	1;
		unsigned char	Bit7:	1;
	}BIT; 	
}FLAG_test1;
	//************************************************
	#define 	FLAG_test1_BYTE		FLAG_test1.BYTE	 
	//------------------------------------------------
        #define		BIT_SIO          	FLAG_test1.BIT.Bit0
        #define		FG_auto_out	        FLAG_test1.BIT.Bit1
        #define		FG_OUT_OPEN_CLOSE	FLAG_test1.BIT.Bit2    //历史记录   误码率测试用
        //#define		LED_SEL3_out		FLAG_test1.BIT.Bit3          
        #define		FG_auto_open_time	        FLAG_test1.BIT.Bit4          
        #define		FG_auto_manual_mode	        FLAG_test1.BIT.Bit5      //1=auto,0=manual
        #define		FG_Receiver_LED_RX	FLAG_test1.BIT.Bit6
        #define		FG_First_auto		FLAG_test1.BIT.Bit7
	//************************************************



extern UINT16 X_COUNT;
extern UINT16 X_ERR;//记录错误的个数
extern unsigned int rssi;

extern UINT8 SIO_cnt;
extern UINT8 SIO_buff[16];
extern UINT8 SIO_DATA[16];
extern UINT8 Tx_Rx_mode;
extern ADF70XX_REG_T ROM_adf7012_value[16];
extern const ADF70XX_REG_T Default_adf7012_value[16];


extern UINT8  TIME_10ms;
extern UINT16  TIMER1s;
extern UINT16  TIMER300ms;
extern UINT16  TIMER18ms;
extern UINT8   TIMER250ms_STOP;
extern UINT16  TIME_auto_out;
extern UINT16  TIME_auto_close;
extern UINT16 time_3sec;
extern UINT32 ID_Receiver_DATA[256];//写入EEPROM ID的数据
extern UINT16 ID_DATA_PCS;
extern UINT8 rxphase;
extern UINT32 DATA_Packet_Syn;     //A部
extern UINT16 DATA_Packet_Head;    //B部
extern UINT32 DATA_Packet_Code[6];   //C部
extern UINT8  DATA_Packet_Code_g;
extern UINT8  DATA_Packet_Code_i;
extern UINT32 DATA_Packet_ID;
extern UINT8  DATA_Packet_Control;
extern UINT8  DATA_Packet_Contro_buf;   //2015.3.24修正
extern UINT32 ID_Receiver_Login;
extern UINT8 TIME_EMC;   //静电测试

extern UINT16 INquiry;
extern UINT16 TIME_Receiver_Login_restrict;
extern UINT8  COUNT_Receiver_Login;
extern UINT16 TIME_Receiver_Login;
extern UINT16 TIME_Login_EXIT_rest;
extern UINT16 TIME_Receiver_Login_led;

extern UINT8 TIME_OUT_OPEN_CLOSE;
extern UINT16 TIME_Receiver_LED_OUT;
extern UINT16 TIME_Login_EXIT_Button;

extern UINT16 Manual_override_TIMER;

extern UINT16 RAM_rssi_SUM;
extern UINT8 RAM_rssi_CNT;
extern UINT8 RAM_rssi_AVG;

extern UINT16 time_Login_exit_256;

extern UINT16 TIME_Fine_Calibration;   //窄带下中频滤波器100KHz精校

extern ADF70XX_REG_T RSSI_value_buf;  //RSSI 测试
extern UINT8 UART_pact_select;









  typedef union {
        UINT16	ui ;
	UINT8	uc[2] ;
  }uni_i;

extern volatile union{
	unsigned char BYTE;	
	struct { 
		unsigned char	Bit0:	1;
		unsigned char	Bit1:	1;
		unsigned char	Bit2:	1;
		unsigned char	Bit3:	1;
		unsigned char	Bit4:	1;
		unsigned char	Bit5:	1;
		unsigned char	Bit6:	1;
		unsigned char	Bit7:	1;
	}BIT; 	
}Motor_FLAG0;
	//************************************************
	#define 	Motor_FLAG0_BYTE		Motor_FLAG0.BYTE	 
	//------------------------------------------------
        #define		Motor_FG_10ms	                Motor_FLAG0.BIT.Bit0
        #define		FLAG_KEY_MODE	                Motor_FLAG0.BIT.Bit1
        #define		FLAG_KEY_ENT		        Motor_FLAG0.BIT.Bit2
        #define		FLAG_KEY_DOWN		        Motor_FLAG0.BIT.Bit3
        #define		FLAG_KEY_UP	                Motor_FLAG0.BIT.Bit4
        #define		FLAG_KEY         	        Motor_FLAG0.BIT.Bit5
        #define		FLAG_SET_stop_Motor	        Motor_FLAG0.BIT.Bit6
        #define		FLAG_SWITCH_stop_Motor  	Motor_FLAG0.BIT.Bit7
	//************************************************

extern volatile union{
	unsigned char BYTE;	
	struct { 
		unsigned char	Bit0:	1;
		unsigned char	Bit1:	1;
		unsigned char	Bit2:	1;
		unsigned char	Bit3:	1;
		unsigned char	Bit4:	1;
		unsigned char	Bit5:	1;
		unsigned char	Bit6:	1;
		unsigned char	Bit7:	1;
	}BIT; 	
}Motor_FLAG1;
	//************************************************
	#define 	Motor_FLAG1_BYTE		Motor_FLAG1.BYTE	 
	//------------------------------------------------
        #define		FG_beep_on_Motor	                Motor_FLAG1.BIT.Bit0
        #define		FG_beep_off_Motor	                Motor_FLAG1.BIT.Bit1
//        #define		FLAG_KEY_ENT		        Motor_FLAG1.BIT.Bit2
//        #define		FLAG_KEY_DOWN		        Motor_FLAG1.BIT.Bit3
//        #define		FLAG_KEY_UP	                Motor_FLAG1.BIT.Bit4
//        #define		FLAG_KEY         	        Motor_FLAG1.BIT.Bit5
//        #define		FLAG_SET_stop_Motor	        Motor_FLAG1.BIT.Bit6
//        #define		FLAG_SWITCH_stop_Motor  	Motor_FLAG1.BIT.Bit7
	//************************************************

extern UINT8  Receiver_vent;    //受信机换气联动ON/OFF
extern UINT8  Inverters_OUT;    //继电器输出信号是否反向
extern UINT16 TIME_SET_twinkling;
extern UINT16 TIME_twinkling_count;
extern UINT8  LED_ON_OFF;
extern UINT8  LED_DP;
extern UINT8  LED_data_buf[3];
extern UINT8  LED_data_twinkling[3];

extern UINT8 UART_RX_RT[50];
extern UINT8 UART1_DATA[50];
extern UINT8 UART_RX_idx;
extern UINT8 UART_RX_Size;
extern UINT8 FLAG_UART_R;
extern UINT16 UART_RX_check_SUM;

extern UINT8 Receiver_OUT_value;
extern UINT8 Receiver_OUT_value_last;

#define d_Time50ms  3
extern UINT8 Motor_10ms;
extern UINT8 TIME_KEY;
extern UINT8 m_KeyNew;
extern UINT8 m_KeyOld;
extern UINT8 m_ChatterCount;
extern UINT8 KEY_Layer;
extern UINT8 KEY_MODE_ABC;
extern UINT8 KEY_PAGE;
#define def_MODE_B  50    //这个数字需要注意，在ram.c里面也有预定义
#define def_MODE_C  22    //这个数字需要注意，在ram.c里面也有预定义
extern const UINT8 Motor_MODE_B_data_def[def_MODE_B];
extern const UINT8 Motor_MODE_B_data_L[def_MODE_B];
extern const UINT8 Motor_MODE_B_data_H[def_MODE_B];
extern UINT8 Motor_MODE_B_data[def_MODE_B];
extern UINT32 Motor_MODE_C_data[def_MODE_C];
extern UINT8 TIME_MODE_B_save;
extern UINT8 TIME_MODE;

extern UINT8 DSW_switch_last;
extern UINT8 Motor_Origin_data[3][4];

extern UINT16 UART_send_CMD;

extern UINT16 TIME_BEEP_on;
extern UINT8 TIME_BEEP_off;
extern UINT16 BASE_TIME_BEEP_on;
extern UINT8 BASE_TIME_BEEP_off;
extern UINT8 TIME_BEEP_freq;