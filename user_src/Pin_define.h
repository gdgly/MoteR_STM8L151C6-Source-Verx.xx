/***********************************************************************/
/*  File Name   :Pin_Define.h                                          */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/

//#define __SOFT_Ver1__       //hardware：（PCB 3.4.3）   PCB初次作成
//#define __SOFT_Ver2__       //hardware：（CY-1601 OP-0401）   PCB重新垒板，部分I/O有变动
#define __SOFT_Ver3__       //hardware：（CY-1601 OP Ver1.1 CQ:2017.07.18）   PCB重新垒板，部分I/O有变动

//以下是IO定义

#if defined(__SOFT_Ver1__)
/******************以下是data寄存器************************************/
/* ADF7012 register interface */
#define ADF7021_SCLK            PB_ODR_ODR4     // Output   时钟线
#define ADF7021_SDATA           PB_ODR_ODR6     // Output   数据线
#define ADF7021_SLE             PB_ODR_ODR7     // Output   片选
#define ADF7021_SREAD           PB_IDR_IDR5     // Input
#define ADF7021_CE              PD_ODR_ODR4     // Output   ADF7012使能脚
#define ADF7021_MUXOUT          PB_IDR_IDR1    // Input

/* Other ADF7021 connections */
#define ADF7021_DATA_tx         PB_ODR_ODR3     // Output   调制DATA线
#define ADF7021_DATA_rx         PB_IDR_IDR3     // Input   调制DATA线
#define ADF7021_DATA_CLK        PB_IDR_IDR2     // 输入   调制同步时钟线


     /* 受信机使用的IO*/
#define Receiver_Login          PC_IDR_IDR6    // Input   受信机登录键   低电平有效
//#define Receiver_Buzzer         PC_ODR_ODR5  // Output   受信机蜂鸣器  高电平有效
//#define Receiver_vent           PC_IDR_IDR5    // Input   受信机换气联动ON/OFF	  
#define PIN_BEEP                PA_ODR_ODR0     // Output   蜂鸣器
#define Receiver_LED_OUT        PC_ODR_ODR4  // Output   受信机继电器动作输出  高电平有效
//#define Receiver_LED_TX         PC_ODR_ODR1 // Output   受信机送信指示  高电平有效
#define Receiver_LED_RX         PC_ODR_ODR0  // Output   受信机受信指示  高电平有效
#define Receiver_OUT_OPEN       PD_ODR_ODR3  // Output   受信机继电器OPEN  高电平有效
#define Receiver_OUT_CLOSE      PD_ODR_ODR2  // Output   受信机继电器close  高电平有效
#define Receiver_OUT_STOP       PD_ODR_ODR1  // Output   受信机继电器stop  高电平有效
#define Receiver_OUT_VENT       PD_ODR_ODR0   // Output 受信机继电器VENT  高电平有效
//#define Inverters_OUT           PA_IDR_IDR2     // 输入   继电器输出信号反向   低电平有效

#define MOTOR_left_right_bit0   PA_IDR_IDR4      // Input   电机安装位置左右选择   低电平有效
#define MOTOR_left_right_bit1   PA_IDR_IDR5    // Input     电机安装位置左右选择  低电平有效
#define KEY_DOWN                PA_IDR_IDR3    // net key4   Input   
#define KEY_UP                  PA_IDR_IDR2    // net key3   输入
#define KEY_MODE                PC_IDR_IDR5    // net key1   Input 

#define KEY_ENT                 PC_IDR_IDR7    // net key2   Input 
#define KEY_BEAM_sensor         PA_IDR_IDR6    // net key5   Input
#define LED_SEL1                PD_ODR_ODR7  // Output
#define LED_SEL2                PD_ODR_ODR6  // Output
#define LED_SEL3                PD_ODR_ODR5  // Output
#define LED_DATA                PE_ODR       // Output

#define  Receiver_test          PB_IDR_IDR0    // Input 受信机测试脚  高电平有效

/************************以下是方向寄存器*****************************/
/* ADF7012 register interface */
#define ADF7021_SCLK_direc      PB_DDR_DDR4     // Output   时钟线
#define ADF7021_SDATA_direc     PB_DDR_DDR6     // Output   数据线
#define ADF7021_SLE_direc       PB_DDR_DDR7     // Output   片选
#define ADF7021_SREAD_direc     PB_DDR_DDR5     // Input
#define ADF7021_CE_direc        PD_DDR_DDR4     // Output   ADF7012使能脚
#define ADF7021_MUXOUT_direc    PB_DDR_DDR1    // Input

/* Other ADF7021 connections */
#define ADF7021_DATA_direc      PB_DDR_DDR3     // Output/Input   调制DATA线
#define ADF7021_DATA_IO         PB_DDR_DDR3     // Output/Input   调制DATA线
#define ADF7021_DATA_CLK_direc  PB_DDR_DDR2     // 输入   调制同步时钟线


     /* 受信机使用的IO*/
#define HA_L_signal_direc       PA_DDR_DDR4      // Input   HA 下限信号   低电平有效
#define HA_ERR_signal_direc     PA_DDR_DDR5    // Input   HA 异常信号  低电平有效
#define HA_Sensor_signal_direc  PA_DDR_DDR3    // Input   HA 传感器信号  低电平有效
#define Receiver_Login_direc    PC_DDR_DDR6    // Input   受信机登录键   低电平有效
//#define Receiver_Buzzer_direc   PC_DDR_DDR5  // Output   受信机蜂鸣器  高电平有效
#define Receiver_vent_direc     PC_DDR_DDR5  // Input   受信机换气联动ON/OFF
#define PIN_BEEP_direc          PA_DDR_DDR0     // Output   蜂鸣器
#define Receiver_LED_OUT_direc  PC_DDR_DDR4  // Output   受信机继电器动作输出  高电平有效
//#define Receiver_LED_TX_direc   PC_DDR_DDR1 // Output   受信机送信指示  高电平有效
#define Receiver_LED_RX_direc   PC_DDR_DDR0  // Output   受信机受信指示  高电平有效
#define Receiver_OUT_OPEN_direc PD_DDR_DDR3  // Output   受信机继电器OPEN  高电平有效
#define Receiver_OUT_CLOSE_direc PD_DDR_DDR2  // Output   受信机继电器close  高电平有效
#define Receiver_OUT_STOP_direc PD_DDR_DDR1  // Output   受信机继电器stop  高电平有效
#define Receiver_OUT_VENT_direc PD_DDR_DDR0   // Output 受信机继电器VENT  高电平有效
#define Inverters_OUT_direc     PA_DDR_DDR2     // 输入   继电器输出信号反向   低电平有效


#define KEY_ENT_direc              PC_DDR_DDR7    // net key2   Input 
#define KEY_BEAM_sensor_direc      PA_DDR_DDR6    // net key5   Input
#define LED_SEL1_direc             PD_DDR_DDR7  // Output
#define LED_SEL2_direc             PD_DDR_DDR6  // Output
#define LED_SEL3_direc             PD_DDR_DDR5  // Output
#define LED_DATA_direc             PE_DDR       // Output


#define Receiver_test_direc     PB_DDR_DDR0    // Input 受信机测试脚  高电平有效

/************************以下是控制寄存器*****************************/
/* ADF7012 register interface */
#define ADF7021_SCLK_CR1        PB_CR1_C14     // Output   时钟线
#define ADF7021_SDATA_CR1       PB_CR1_C16     // Output   数据线
#define ADF7021_SLE_CR1         PB_CR1_C17     // Output   片选
#define ADF7021_SREAD_CR1       PB_CR1_C15     // Input
#define ADF7021_CE_CR1          PD_CR1_C14     // Output   ADF7012使能脚
#define ADF7021_MUXOUT_CR1      PB_CR1_C11    // Input

/* Other ADF7021 connections */
#define ADF7021_DATA_CR1        PB_CR1_C13     // Output/Input   调制DATA线
#define ADF7021_DATA_CLK_CR1    PB_CR1_C12     // 输入   调制同步时钟线


     /* 受信机使用的IO*/
#define HA_L_signal_CR1         PA_CR1_C14      // Input   HA 下限信号   低电平有效
#define HA_ERR_signal_CR1       PA_CR1_C15    // Input   HA 异常信号  低电平有效
#define HA_Sensor_signal_CR1    PA_CR1_C13    // Input   HA 传感器信号  低电平有效
#define Receiver_Login_CR1      PC_CR1_C16    // Input   受信机登录键   低电平有效
//#define Receiver_Buzzer_CR1     PC_CR1_C15  // Output   受信机蜂鸣器  高电平有效
#define Receiver_vent_CR1       PC_CR1_C15  // Input   受信机换气联动ON/OFF
#define PIN_BEEP_CR1            PA_CR1_C10     // Output   蜂鸣器
#define Receiver_LED_OUT_CR1    PC_CR1_C14  // Output   受信机继电器动作输出  高电平有效
//#define Receiver_LED_TX_CR1     PC_CR1_C11 // Output   受信机送信指示  高电平有效
#define Receiver_LED_RX_CR1     PC_CR1_C10  // Output   受信机受信指示  高电平有效
#define Receiver_OUT_OPEN_CR1   PD_CR1_C13  // Output   受信机继电器OPEN  高电平有效
#define Receiver_OUT_CLOSE_CR1  PD_CR1_C12  // Output   受信机继电器close  高电平有效
#define Receiver_OUT_STOP_CR1   PD_CR1_C11  // Output   受信机继电器stop  高电平有效
#define Receiver_OUT_VENT_CR1   PD_CR1_C10   // Output 受信机继电器VENT  高电平有效
#define Inverters_OUT_CR1       PA_CR1_C12     // 输入   继电器输出信号反向   低电平有效

#define Receiver_test_CR1       PB_CR1_C10    // Input 受信机测试脚  高电平有效


#define KEY_ENT_CR1                 PC_CR1_C17    // net key2   Input 
#define KEY_BEAM_sensor_CR1         PA_CR1_C16    // net key5   Input
#define LED_SEL1_CR1                PD_CR1_C17  // Output
#define LED_SEL2_CR1                PD_CR1_C16  // Output
#define LED_SEL3_CR1                PD_CR1_C15  // Output
#define LED_DATA_CR1                PE_CR1       // Output


#define ADF7021_DATA_CLK_CR2    PB_CR2_C22     // 输入   调制同步时钟线

#endif








#if defined(__SOFT_Ver2__)
/******************以下是data寄存器************************************/
/* ADF7012 register interface */
#define ADF7021_SCLK            PB_ODR_ODR4     // Output   时钟线
#define ADF7021_SDATA           PB_ODR_ODR6     // Output   数据线
#define ADF7021_SLE             PB_ODR_ODR7     // Output   片选
#define ADF7021_SREAD           PB_IDR_IDR5     // Input
#define ADF7021_CE              PD_ODR_ODR4     // Output   ADF7012使能脚
#define ADF7021_MUXOUT          PB_IDR_IDR1    // Input

/* Other ADF7021 connections */
#define ADF7021_DATA_tx         PB_ODR_ODR3     // Output   调制DATA线
#define ADF7021_DATA_rx         PB_IDR_IDR3     // Input   调制DATA线
#define ADF7021_DATA_CLK        PB_IDR_IDR2     // 输入   调制同步时钟线


     /* 受信机使用的IO*/
#define Receiver_Login          PA_IDR_IDR6    // Input   受信机登录键   低电平有效
//#define Receiver_Buzzer         PC_ODR_ODR5  // Output   受信机蜂鸣器  高电平有效
//#define Receiver_vent           PC_IDR_IDR5    // Input   受信机换气联动ON/OFF	  
#define PIN_BEEP                PA_ODR_ODR0     // Output   蜂鸣器
#define Receiver_LED_OUT        PC_ODR_ODR4  // Output   受信机继电器动作输出  高电平有效
//#define Receiver_LED_TX         PC_ODR_ODR1 // Output   受信机送信指示  高电平有效
#define Receiver_LED_RX         PC_ODR_ODR0  // Output   受信机受信指示  高电平有效
#define Receiver_OUT_OPEN       PD_ODR_ODR3  // Output   受信机继电器OPEN  高电平有效
#define Receiver_OUT_CLOSE      PD_ODR_ODR2  // Output   受信机继电器close  高电平有效
#define Receiver_OUT_STOP       PD_ODR_ODR1  // Output   受信机继电器stop  高电平有效
#define Receiver_OUT_VENT       PD_ODR_ODR0   // Output 受信机继电器VENT  高电平有效
//#define Inverters_OUT           PA_IDR_IDR2     // 输入   继电器输出信号反向   低电平有效

#define MOTOR_left_right_bit0   PA_IDR_IDR4      // Input   电机安装位置左右选择   低电平有效
#define MOTOR_left_right_bit1   PA_IDR_IDR5    // Input     电机安装位置左右选择  低电平有效
#define PIN_KEY_DOWN                PA_IDR_IDR7    // net key2   Input   
#define PIN_KEY_UP                  PA_IDR_IDR3    // net key4   输入
#define PIN_KEY_MODE                PD_IDR_IDR6    // net key3   Input 

#define PIN_KEY_ENT                 PD_IDR_IDR5    // net key1   Input 
#define KEY_BEAM_sensor         PA_IDR_IDR2    // net key5   Input
#define LED_SEL1                PD_ODR_ODR7  // Output
#define LED_SEL2                PC_ODR_ODR5  // Output
#define LED_SEL3                PC_ODR_ODR7  // Output
#define LED_DATA                PE_ODR       // Output

#define  Receiver_test          PB_IDR_IDR0    // Input 受信机测试脚  高电平有效

/************************以下是方向寄存器*****************************/
/* ADF7012 register interface */
#define ADF7021_SCLK_direc      PB_DDR_DDR4     // Output   时钟线
#define ADF7021_SDATA_direc     PB_DDR_DDR6     // Output   数据线
#define ADF7021_SLE_direc       PB_DDR_DDR7     // Output   片选
#define ADF7021_SREAD_direc     PB_DDR_DDR5     // Input
#define ADF7021_CE_direc        PD_DDR_DDR4     // Output   ADF7012使能脚
#define ADF7021_MUXOUT_direc    PB_DDR_DDR1    // Input

/* Other ADF7021 connections */
#define ADF7021_DATA_direc      PB_DDR_DDR3     // Output/Input   调制DATA线
#define ADF7021_DATA_IO         PB_DDR_DDR3     // Output/Input   调制DATA线
#define ADF7021_DATA_CLK_direc  PB_DDR_DDR2     // 输入   调制同步时钟线


     /* 受信机使用的IO*/
#define HA_L_signal_direc       PA_DDR_DDR4      // Input   HA 下限信号   低电平有效
#define HA_ERR_signal_direc     PA_DDR_DDR5    // Input   HA 异常信号  低电平有效
#define Receiver_Login_direc    PA_DDR_DDR6    // Input   受信机登录键   低电平有效
#define PIN_BEEP_direc          PA_DDR_DDR0     // Output   蜂鸣器
#define Receiver_LED_OUT_direc  PC_DDR_DDR4  // Output   受信机继电器动作输出  高电平有效
#define Receiver_LED_RX_direc   PC_DDR_DDR0  // Output   受信机受信指示  高电平有效
#define Receiver_OUT_OPEN_direc PD_DDR_DDR3  // Output   受信机继电器OPEN  高电平有效
#define Receiver_OUT_CLOSE_direc PD_DDR_DDR2  // Output   受信机继电器close  高电平有效
#define Receiver_OUT_STOP_direc PD_DDR_DDR1  // Output   受信机继电器stop  高电平有效
#define Receiver_OUT_VENT_direc PD_DDR_DDR0   // Output 受信机继电器VENT  高电平有效


#define HA_Sensor_signal_direc  PA_DDR_DDR7    // Input   HA 传感器信号  低电平有效
#define Inverters_OUT_direc     PA_DDR_DDR3     // 输入   继电器输出信号反向   低电平有效
#define Receiver_vent_direc     PD_DDR_DDR6  // Input   受信机换气联动ON/OFF

#define KEY_ENT_direc              PD_DDR_DDR5    // net key2   Input 
#define KEY_BEAM_sensor_direc      PA_DDR_DDR2    // net key5   Input
#define LED_SEL1_direc             PD_DDR_DDR7  // Output
#define LED_SEL2_direc             PC_DDR_DDR5  // Output
#define LED_SEL3_direc             PC_DDR_DDR7  // Output
#define LED_DATA_direc             PE_DDR       // Output


#define Receiver_test_direc     PB_DDR_DDR0    // Input 受信机测试脚  高电平有效

/************************以下是控制寄存器*****************************/
/* ADF7012 register interface */
#define ADF7021_SCLK_CR1        PB_CR1_C14     // Output   时钟线
#define ADF7021_SDATA_CR1       PB_CR1_C16     // Output   数据线
#define ADF7021_SLE_CR1         PB_CR1_C17     // Output   片选
#define ADF7021_SREAD_CR1       PB_CR1_C15     // Input
#define ADF7021_CE_CR1          PD_CR1_C14     // Output   ADF7012使能脚
#define ADF7021_MUXOUT_CR1      PB_CR1_C11    // Input

/* Other ADF7021 connections */
#define ADF7021_DATA_CR1        PB_CR1_C13     // Output/Input   调制DATA线
#define ADF7021_DATA_CLK_CR1    PB_CR1_C12     // 输入   调制同步时钟线


     /* 受信机使用的IO*/
#define HA_L_signal_CR1         PA_CR1_C14      // Input   HA 下限信号   低电平有效
#define HA_ERR_signal_CR1       PA_CR1_C15    // Input   HA 异常信号  低电平有效
#define Receiver_Login_CR1      PA_CR1_C16    // Input   受信机登录键   低电平有效
#define PIN_BEEP_CR1            PA_CR1_C10     // Output   蜂鸣器
#define Receiver_LED_OUT_CR1    PC_CR1_C14  // Output   受信机继电器动作输出  高电平有效
#define Receiver_LED_RX_CR1     PC_CR1_C10  // Output   受信机受信指示  高电平有效
#define Receiver_OUT_OPEN_CR1   PD_CR1_C13  // Output   受信机继电器OPEN  高电平有效
#define Receiver_OUT_CLOSE_CR1  PD_CR1_C12  // Output   受信机继电器close  高电平有效
#define Receiver_OUT_STOP_CR1   PD_CR1_C11  // Output   受信机继电器stop  高电平有效
#define Receiver_OUT_VENT_CR1   PD_CR1_C10   // Output 受信机继电器VENT  高电平有效


#define Receiver_test_CR1       PB_CR1_C10    // Input 受信机测试脚  高电平有效


#define Inverters_OUT_CR1       PA_CR1_C13     // 输入   继电器输出信号反向   低电平有效
#define Receiver_vent_CR1       PD_CR1_C16  // Input   受信机换气联动ON/OFF
#define HA_Sensor_signal_CR1    PA_CR1_C17    // Input   HA 传感器信号  低电平有效

#define KEY_ENT_CR1                 PD_CR1_C15    // net key2   Input 
#define KEY_BEAM_sensor_CR1         PA_CR1_C12    // net key5   Input
#define LED_SEL1_CR1                PD_CR1_C17  // Output
#define LED_SEL2_CR1                PC_CR1_C15  // Output
#define LED_SEL3_CR1                PC_CR1_C17  // Output
#define LED_DATA_CR1                PE_CR1       // Output


#define ADF7021_DATA_CLK_CR2    PB_CR2_C22     // 输入   调制同步时钟线

#endif








#if defined(__SOFT_Ver3__)
/******************以下是data寄存器************************************/
/* ADF7012 register interface */
#define ADF7021_SCLK            PB_ODR_ODR4     // Output   时钟线
#define ADF7021_SDATA           PB_ODR_ODR6     // Output   数据线
#define ADF7021_SLE             PB_ODR_ODR7     // Output   片选
#define ADF7021_SREAD           PB_IDR_IDR5     // Input
#define ADF7021_CE              PD_ODR_ODR4     // Output   ADF7012使能脚
#define ADF7021_MUXOUT          PB_IDR_IDR1    // Input

/* Other ADF7021 connections */
#define ADF7021_DATA_tx         PB_ODR_ODR3     // Output   调制DATA线
#define ADF7021_DATA_rx         PB_IDR_IDR3     // Input   调制DATA线
#define ADF7021_DATA_CLK        PB_IDR_IDR2     // 输入   调制同步时钟线


     /* 受信机使用的IO*/
#define Receiver_Login          PA_IDR_IDR3    // Input   受信机登录键   低电平有效  
#define PIN_BEEP                PA_ODR_ODR0     // Output   蜂鸣器
#define Receiver_LED_OUT        PA_ODR_ODR1  // Output   受信机继电器动作输出  高电平有效
#define Receiver_LED_RX         PA_ODR_ODR1  // Output   受信机受信指示  高电平有效
#define Receiver_OUT_OPEN       PD_ODR_ODR3  // Output   受信机继电器OPEN  高电平有效
#define Receiver_OUT_CLOSE      PD_ODR_ODR2  // Output   受信机继电器close  高电平有效
#define Receiver_OUT_STOP       PD_ODR_ODR1  // Output   受信机继电器stop  高电平有效
#define Receiver_OUT_VENT       PD_ODR_ODR0   // Output 受信机继电器VENT  高电平有效

//#define Receiver_vent           PC_IDR_IDR5    // Input   受信机换气联动ON/OFF	
//#define Inverters_OUT           PA_IDR_IDR2     // 输入   继电器输出信号反向   低电平有效

#define MOTOR_left_right_bit0   PC_IDR_IDR0      // Input   电机安装位置左右选择   低电平有效
#define MOTOR_left_right_bit1   PF_IDR_IDR0    // Input     电机安装位置左右选择  低电平有效
#define PIN_KEY_DOWN                PA_IDR_IDR6    // net key2   Input   
#define PIN_KEY_UP                  PA_IDR_IDR7    // net key4   输入
#define PIN_KEY_MODE                PA_IDR_IDR4    // net key3   Input 
#define PIN_KEY_ENT                 PA_IDR_IDR5    // net key1   Input 
#define KEY_BEAM_sensor         PA_IDR_IDR2    // net key5   Input
#define LED_SEL1                PD_ODR_ODR5  // Output
#define LED_SEL2                PD_ODR_ODR6  // Output
#define LED_SEL3                PD_ODR_ODR7  // Output
#define LED_DATA                PE_ODR       // Output

#define  Receiver_test          PB_IDR_IDR0    // Input 受信机测试脚  高电平有效

/************************以下是方向寄存器*****************************/
/* ADF7012 register interface */
#define ADF7021_SCLK_direc      PB_DDR_DDR4     // Output   时钟线
#define ADF7021_SDATA_direc     PB_DDR_DDR6     // Output   数据线
#define ADF7021_SLE_direc       PB_DDR_DDR7     // Output   片选
#define ADF7021_SREAD_direc     PB_DDR_DDR5     // Input
#define ADF7021_CE_direc        PD_DDR_DDR4     // Output   ADF7012使能脚
#define ADF7021_MUXOUT_direc    PB_DDR_DDR1    // Input

/* Other ADF7021 connections */
#define ADF7021_DATA_direc      PB_DDR_DDR3     // Output/Input   调制DATA线
#define ADF7021_DATA_IO         PB_DDR_DDR3     // Output/Input   调制DATA线
#define ADF7021_DATA_CLK_direc  PB_DDR_DDR2     // 输入   调制同步时钟线


     /* 受信机使用的IO*/
#define Receiver_Login_direc    PA_DDR_DDR3    // Input   受信机登录键   低电平有效
#define PIN_BEEP_direc          PA_DDR_DDR0     // Output   蜂鸣器
#define Receiver_LED_OUT_direc  PA_DDR_DDR1  // Output   受信机继电器动作输出  高电平有效
#define Receiver_LED_RX_direc   PA_DDR_DDR1  // Output   受信机受信指示  高电平有效
#define Receiver_OUT_OPEN_direc PD_DDR_DDR3  // Output   受信机继电器OPEN  高电平有效
#define Receiver_OUT_CLOSE_direc PD_DDR_DDR2  // Output   受信机继电器close  高电平有效
#define Receiver_OUT_STOP_direc PD_DDR_DDR1  // Output   受信机继电器stop  高电平有效
#define Receiver_OUT_VENT_direc PD_DDR_DDR0   // Output 受信机继电器VENT  高电平有效

//#define HA_L_signal_direc       PA_DDR_DDR4      // Input   HA 下限信号   低电平有效
//#define HA_ERR_signal_direc     PA_DDR_DDR5    // Input   HA 异常信号  低电平有效
//#define HA_Sensor_signal_direc  PA_DDR_DDR7    // Input   HA 传感器信号  低电平有效
//#define Inverters_OUT_direc     PA_DDR_DDR3     // 输入   继电器输出信号反向   低电平有效
//#define Receiver_vent_direc     PD_DDR_DDR6  // Input   受信机换气联动ON/OFF

#define MOTOR_left_right_bit0_direc   PC_DDR_DDR0      // Input   电机安装位置左右选择   低电平有效
#define MOTOR_left_right_bit1_direc   PF_DDR_DDR0    // Input     电机安装位置左右选择  低电平有效
#define PIN_KEY_DOWN_direc                PA_DDR_DDR6    // net key2   Input   
#define PIN_KEY_UP_direc                  PA_DDR_DDR7    // net key4   输入
#define PIN_KEY_MODE_direc                PA_DDR_DDR4    // net key3   Input 
#define KEY_ENT_direc              PA_DDR_DDR5    // net key2   Input 
#define KEY_BEAM_sensor_direc      PA_DDR_DDR2    // net key5   Input
#define LED_SEL1_direc             PD_DDR_DDR5  // Output
#define LED_SEL2_direc             PD_DDR_DDR6  // Output
#define LED_SEL3_direc             PD_DDR_DDR7  // Output
#define LED_DATA_direc             PE_DDR       // Output


#define Receiver_test_direc     PB_DDR_DDR0    // Input 受信机测试脚  高电平有效

/************************以下是控制寄存器*****************************/
/* ADF7012 register interface */
#define ADF7021_SCLK_CR1        PB_CR1_C14     // Output   时钟线
#define ADF7021_SDATA_CR1       PB_CR1_C16     // Output   数据线
#define ADF7021_SLE_CR1         PB_CR1_C17     // Output   片选
#define ADF7021_SREAD_CR1       PB_CR1_C15     // Input
#define ADF7021_CE_CR1          PD_CR1_C14     // Output   ADF7012使能脚
#define ADF7021_MUXOUT_CR1      PB_CR1_C11    // Input

/* Other ADF7021 connections */
#define ADF7021_DATA_CR1        PB_CR1_C13     // Output/Input   调制DATA线
#define ADF7021_DATA_CLK_CR1    PB_CR1_C12     // 输入   调制同步时钟线


     /* 受信机使用的IO*/
#define Receiver_Login_CR1      PA_CR1_C13    // Input   受信机登录键   低电平有效
#define PIN_BEEP_CR1            PA_CR1_C10     // Output   蜂鸣器
#define Receiver_LED_OUT_CR1    PA_CR1_C11  // Output   受信机继电器动作输出  高电平有效
#define Receiver_LED_RX_CR1     PA_CR1_C11  // Output   受信机受信指示  高电平有效
#define Receiver_OUT_OPEN_CR1   PD_CR1_C13  // Output   受信机继电器OPEN  高电平有效
#define Receiver_OUT_CLOSE_CR1  PD_CR1_C12  // Output   受信机继电器close  高电平有效
#define Receiver_OUT_STOP_CR1   PD_CR1_C11  // Output   受信机继电器stop  高电平有效
#define Receiver_OUT_VENT_CR1   PD_CR1_C10   // Output 受信机继电器VENT  高电平有效

//#define HA_L_signal_CR1         PA_CR1_C14      // Input   HA 下限信号   低电平有效
//#define HA_ERR_signal_CR1       PA_CR1_C15    // Input   HA 异常信号  低电平有效
//#define Inverters_OUT_CR1       PA_CR1_C13     // 输入   继电器输出信号反向   低电平有效
//#define Receiver_vent_CR1       PD_CR1_C16  // Input   受信机换气联动ON/OFF
//#define HA_Sensor_signal_CR1    PA_CR1_C17    // Input   HA 传感器信号  低电平有效

#define MOTOR_left_right_bit0_CR1   PC_CR1_C10      // Input   电机安装位置左右选择   低电平有效
#define MOTOR_left_right_bit1_CR1   PF_CR1_C10    // Input     电机安装位置左右选择  低电平有效
#define PIN_KEY_DOWN_CR1                PA_CR1_C16    // net key2   Input   
#define PIN_KEY_UP_CR1                  PA_CR1_C17    // net key4   输入
#define PIN_KEY_MODE_CR1                PA_CR1_C14    // net key3   Input 
#define KEY_ENT_CR1                 PA_CR1_C15    // net key2   Input 
#define KEY_BEAM_sensor_CR1         PA_CR1_C12    // net key5   Input
#define LED_SEL1_CR1                PD_CR1_C15  // Output
#define LED_SEL2_CR1                PD_CR1_C16  // Output
#define LED_SEL3_CR1                PD_CR1_C17  // Output
#define LED_DATA_CR1                PE_CR1       // Output

#define Receiver_test_CR1       PB_CR1_C10    // Input 受信机测试脚  高电平有效
#define ADF7021_DATA_CLK_CR2    PB_CR2_C22     // 输入   调制同步时钟线

#endif