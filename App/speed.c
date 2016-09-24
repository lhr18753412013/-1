#include "common.h"
#include "include.h"
void speedinit() //电机正转
{
	printf("\n*****FTM 电机测试 测试*****\n");

    ftm_pwm_init(MOTOR_FTM, MOTOR1_PWM,MOTOR_HZ,50);      //初始化 电机 PWM
    ftm_pwm_init(MOTOR_FTM, MOTOR2_PWM,MOTOR_HZ,100);      //初始化 电机 PWM
   // ftm_pwm_init(MOTOR_FTM, MOTOR3_PWM,MOTOR_HZ,100);      //初始化 电机 PWM
  //  ftm_pwm_init(MOTOR_FTM, MOTOR4_PWM,MOTOR_HZ,100);      //初始化 电机 PWM
}
void speedcontrol() //局部变量在运行完一次后会释放，即变为0
{

}
void speedoutput()
{
      
        ftm_pwm_duty(MOTOR_FTM, MOTOR1_PWM,0);
        ftm_pwm_duty(MOTOR_FTM, MOTOR2_PWM,20);
}
