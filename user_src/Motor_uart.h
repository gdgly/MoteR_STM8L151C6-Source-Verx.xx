/***********************************************************************/
/*  FILE        :Motor_uart.h                                          */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/

void UART_Handler(void);
void Receiver_OUT_change_UART(void);
void UART_send_Receiver_OUT(void);
void UART_ack(unsigned char ch);
void UART_send_Motor(UINT16 d_COM,UINT8 d_addr,UINT8 d_length,UINT8 *d_data);
void UART_Power_ON_send(void);