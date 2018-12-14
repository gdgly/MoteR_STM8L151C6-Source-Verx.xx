/************************************************/
/*  FILE        :eeprom.h                       */
/*  DATE        :June, 2011                     */
/*  DESCRIPTION :routine for VHF2011            */
/*  CPU TYPE    :STM8S207C8                     */
/*  Programmer	:Gong Dong Sheng                */
/*  Mark        :0x4000~0x47FF                  */
/************************************************/
void InitialFlashReg(void);
void UnlockFlash(unsigned char Type);			// ����flash
void LockFlash(unsigned char Type );			// �����洢��

unsigned char ReadByteEEPROM( unsigned long Addr );				// ��ȡ1�ֽ�
void WriteByteToFLASH(unsigned long Addr, unsigned char Dat);	// д��һ�ֽ�
void EraseByteFLASH( unsigned int Addr);						// ����eeprom

void eeprom_save(void);
void eeprom_sys_load(void);


void ALL_ID_EEPROM_Erase(void);
void ID_EEPROM_write(void);
void ID_EEPROM_write_0x00(void);
void ID_Login_EXIT_Initial(void);
void ID_learn(void);
/************************************************/

#define UNLOCK_FLASH_TYPE   ((unsigned char)0x00 )
#define UNLOCK_EEPROM_TYPE  ((unsigned char)0x01 )


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%                  EEPROM MAP                  %
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#define addr_eeprom_sys			0x1000		// SYS=0x4000~0x400F

//��������addr_eeprom_sys����֮�ϵ�ƫ��
#define addr_eeprom_ADF7021	        0x310
#define addr_eeprom_ID_PCS_L	        0x330
#define addr_eeprom_ID_PCS_H	        0x331

                                                     //ר�����ڵ�������Ĵ洢���ܿ���192��������
#define addr_eeprom_MOTOR	        0x340        //���ڵ��������mode B���ݣ�50pcs
#define addr_eeprom_Origin	        0x380        //���ھ����ŵ�ԭ�㡢���ޡ����ޣ�3*4pcs
#define addr_eeprom_Place               0x390        //���ھ����ŵĶϵ�ʱλ�ô洢





