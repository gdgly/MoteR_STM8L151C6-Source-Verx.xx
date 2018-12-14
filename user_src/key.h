/***********************************************************************/
/*  FILE        :key.H                                                */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/


void Key_scan(void);
void DSW_switch_R_L(void);
void _ReqBuzzer(UINT16 d_BEEP_on,UINT8 d_BEEP_off,UINT8 d_BEEP_freq);