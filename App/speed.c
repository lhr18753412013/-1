#include "common.h"
#include "include.h"
void speedinit() //�����ת
{
	printf("\n*****FTM ������� ����*****\n");

    ftm_pwm_init(MOTOR_FTM, MOTOR1_PWM,MOTOR_HZ,50);      //��ʼ�� ��� PWM
    ftm_pwm_init(MOTOR_FTM, MOTOR2_PWM,MOTOR_HZ,100);      //��ʼ�� ��� PWM
   // ftm_pwm_init(MOTOR_FTM, MOTOR3_PWM,MOTOR_HZ,100);      //��ʼ�� ��� PWM
  //  ftm_pwm_init(MOTOR_FTM, MOTOR4_PWM,MOTOR_HZ,100);      //��ʼ�� ��� PWM
}
void speedcontrol() //�ֲ�������������һ�κ���ͷţ�����Ϊ0
{

}
void speedoutput()
{
      
        ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM,0);
        ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM,20);
}
