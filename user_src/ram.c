/***********************************************************************/
/*  FILE        :ram.c                                                 */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/
#include  <iostm8l151c6.h>				// CPU型号
//#include "stm8l15x.h"
#include "Pin_define.h"		// 管脚定义
#include "initial.h"		// 初始化  预定义


volatile union{
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

volatile union{
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

volatile union{
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

volatile union{
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



UINT16 X_COUNT = 0;
UINT16 X_ERR  = 0 ;//记录错误的个数
unsigned int rssi;

UINT8 SIO_cnt;
UINT8 SIO_buff[16];
UINT8 SIO_DATA[16];
UINT8 Tx_Rx_mode=0;
ADF70XX_REG_T ROM_adf7012_value[16];
const ADF70XX_REG_T Default_adf7012_value[16]={0x00000000,0x031B5011,0x00000000,0x00000000,
                                               0x00000000,0x00000000,0x00000000,0x00000000,
                                               0x00000000,0x00000000,0x00000000,0x00000000,
                                               0x00000000,0x00000000,0x00000000,0x00000000,
                                               };

UINT8  TIME_10ms=0;
UINT16  TIMER1s=0;
UINT16  TIMER300ms=0;
UINT16  TIMER18ms=0;
UINT8   TIMER250ms_STOP=0;
UINT16  TIME_auto_out=0;
UINT16  TIME_auto_close=0;
UINT16 time_3sec=0;
UINT32 ID_Receiver_DATA[256] = {0};//写入EEPROM ID的数据
UINT16 ID_DATA_PCS=0;
UINT8 rxphase=0;
UINT32 DATA_Packet_Syn=0;     //A部
UINT16 DATA_Packet_Head=0;    //B部
UINT32 DATA_Packet_Code[6]={0};   //C部
UINT8  DATA_Packet_Code_g=0;
UINT8  DATA_Packet_Code_i=0;
UINT32 DATA_Packet_ID=0;
UINT8  DATA_Packet_Control=0;
UINT8  DATA_Packet_Contro_buf=0;   //2015.3.24修正
UINT32 ID_Receiver_Login=0;
UINT8 TIME_EMC=0;   //静电测试

UINT16 INquiry=0;
UINT16 TIME_Receiver_Login_restrict=0;
UINT8  COUNT_Receiver_Login=0;
UINT16 TIME_Receiver_Login=0;
UINT16 TIME_Login_EXIT_rest=0;
UINT16 TIME_Receiver_Login_led=0;

UINT8 TIME_OUT_OPEN_CLOSE=0;
UINT16 TIME_Receiver_LED_OUT=0;
UINT16 TIME_Login_EXIT_Button=0;

UINT16 Manual_override_TIMER=0;

UINT16 RAM_rssi_SUM=0;
UINT8 RAM_rssi_CNT=0;
UINT8 RAM_rssi_AVG=0;

UINT16 time_Login_exit_256=0;

UINT16 TIME_Fine_Calibration=0;   //窄带下中频滤波器100KHz精校

ADF70XX_REG_T RSSI_value_buf;  //RSSI 测试
UINT8 UART_pact_select;









volatile union{
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

volatile union{
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

UINT8  Receiver_vent;    //受信机换气联动ON/OFF
UINT8  Inverters_OUT;    //继电器输出信号是否反向
UINT16 TIME_SET_twinkling;
UINT16 TIME_twinkling_count;
UINT8  LED_ON_OFF;
UINT8  LED_DP;
UINT8  LED_data_buf[3];
UINT8  LED_data_twinkling[3];

UINT8 UART_RX_RT[50];
UINT8 UART1_DATA[50];
UINT8 UART_RX_idx;
UINT8 UART_RX_Size;
UINT8 FLAG_UART_R;
UINT16 UART_RX_check_SUM;

UINT8 Receiver_OUT_value;
UINT8 Receiver_OUT_value_last;

UINT8 Motor_10ms;
UINT8 TIME_KEY;
UINT8 m_KeyNew;
UINT8 m_KeyOld;
UINT8 m_ChatterCount;
UINT8 KEY_Layer;
UINT8 KEY_MODE_ABC;
UINT8 KEY_PAGE;
#define def_MODE_B  50    //这个数字需要注意，在ram.c里面也有预定义
#define def_MODE_C  22   //这个数字需要注意，在ram.c里面也有预定义
const UINT8 Motor_MODE_B_data_def[def_MODE_B]={0,    1,    1,    5,    1,    3,    0,    4,   255,  255, 
                                                  //P01   P02   P03   P04   P05   P06   P07   P08   P09
                                             0,    0,   255,  255,  255,  255,   0,    0,    0,    0, 
                                          //P10   P11   P12   P13   P14   P15   P16   P17   P18   P19 
                                             255,  2,    5,    5,    5,    1,    3,    2,    2,    10, 
                                          //P20   P21   P22   P23   P24   P25   P26   P27   P28   P29
                                             10,   5,    5,   255,  255,  255,  255,  255,  255,  255, 
                                          //P30   P31   P32   P33   P34   P35   P36   P37   P38   P39
                                             1,    1,    1,   255,  255,  255,  255,  255,  255,   0, 
                                          //P90   P91   P92   P93   P94   P95   P96   P97   P98   P99
                                      };   
const UINT8 Motor_MODE_B_data_L[def_MODE_B]={0,    1,    1,    0,    1,    0,    0,    0,   255,  255,
                                                //P01   P02   P03   P04   P05   P06   P07   P08   P09
                                             0,    0,   255,  255,  255,  255,   0,    0,    0,    0, 
                                          //P10   P11   P12   P13   P14   P15   P16   P17   P18   P19
                                            255,   1,    0,    0,    0,    1,    1,    1,    1,    1, 
                                          //P20   P21   P22   P23   P24   P25   P26   P27   P28   P29
                                             1,    1,    1,   255,  255,  255,  255,  255,  255,  255, 
                                          //P30   P31   P32   P33   P34   P35   P36   P37   P38   P39
                                             0,    0,    0,   255,  255,  255,  255,  255,  255,   0, 
                                          //P90   P91   P92   P93   P94   P95   P96   P97   P98   P99
                                      };
const UINT8 Motor_MODE_B_data_H[def_MODE_B]={0,    8,    4,    10,   2,    3,    15,   16,  255,  255,
                                                //P01   P02   P03   P04   P05   P06   P07   P08   P09
                                            15,   15,   255,  255,  255,  255,   6,    6,    6,    6,
                                          //P10   P11   P12   P13   P14   P15   P16   P17   P18   P19
                                            255,   2,   10,    10,   15,   3,    5,    3,    3,   10,
                                          //P20   P21   P22   P23   P24   P25   P26   P27   P28   P29
                                            10,   10,   10,   255,  255,  255,  255,  255,  255,  255, 
                                          //P30   P31   P32   P33   P34   P35   P36   P37   P38   P39
                                            1,     1,    1,   255,  255,  255,  255,  255,  255,   1, 
                                          //P90   P91   P92   P93   P94   P95   P96   P97   P98   P99
                                      };
UINT8 Motor_MODE_B_data[def_MODE_B];
UINT32 Motor_MODE_C_data[def_MODE_C];
UINT8 TIME_MODE_B_save;
UINT8 TIME_MODE;

UINT8 DSW_switch_last;

UINT16 UART_send_CMD;