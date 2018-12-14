/***********************************************************************/
/*  FILE        :LED.h                                                 */
/*  DATE        :Mar, 2014                                             */
/*  Programmer	:xiang 'R                                              */
/*  CPU TYPE    :STM8L151G6     Crystal: 16M HSI                       */
/*  DESCRIPTION :                                                      */
/*  Mark        :ver 1.0                                               */
/***********************************************************************/



void LED_display_INT(void);
void LED_display_page(UINT8 *char_data,UINT8 led1_glint, UINT8 led2_glint,UINT8 led3_glint,UINT16 set_glint_time,UINT8 led_point);
