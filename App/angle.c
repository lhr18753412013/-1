#include "common.h"
#include "include.h"
/*
 *  @since      v5.0
 *  @note       ɽ�� S3010��� ����ʵ�� ,ɽ�� �ṩ�� �������ģ�飬�ܽŶ����� MOS �ܸ��룬�ź��Ƿ���ġ�
                ���糣��� �ߵ�ƽ ʹ��
 */
void duojiinit()
{
  ftm_pwm_init(SD5_FTM, SD5_CH,SD5_HZ,7);      //��ʼ�� ��� PWM
}
void duojicontrol()
{
  
}
