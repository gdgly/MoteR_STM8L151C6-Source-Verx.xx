/***********************************************************************/
/*  FILE        :Uart.H                                                */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/

void UART1_INIT(void);
void UART1_RX_RXNE(void);
void Send_char(unsigned char ch);
void UART1_end(void);
void PC_PRG(void);
void UART_Handler(void);
void Receiver_OUT_change_UART(void);
void UART_send_Receiver_OUT(void);
void UART_ack(unsigned char ch);