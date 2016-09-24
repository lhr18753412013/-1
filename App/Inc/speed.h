#ifndef _SPEED_H_
#define _SPEED_H_

#define MOTOR1_IO   PTD5
#define MOTOR2_IO   PTD7
//#define MOTOR3_IO   PTA5
//#define MOTOR4_IO   PTA24

#define MOTOR_FTM   FTM0
#define MOTOR1_PWM  FTM_CH5
#define MOTOR2_PWM  FTM_CH7
//#define MOTOR3_PWM  FTM_CH5
//#define MOTOR4_PWM  FTM_CH6

#define MOTOR1_PWM_IO  FTM0_CH5
#define MOTOR2_PWM_IO  FTM0_CH7
//#define MOTOR3_PWM_IO  FTM0_CH5
//#define MOTOR4_PWM_IO  FTM0_CH6

#define MOTOR_HZ    (1*1000)
#define MOTOR_DUTY  80

/*---------------------------------变量声明区--------------------------------*/

/*------------------------------函数声明区------------------------------*/
extern void speedinit();
extern void speedcontrol();
extern void speedoutput();



/*----------------------------------------------------------------------*/




#endif