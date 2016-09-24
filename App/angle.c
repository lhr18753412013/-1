#include "common.h"
#include "include.h"
/*
 *  @since      v5.0
 *  @note       山外 S3010舵机 测试实验 ,山外 提供的 电机驱动模块，管脚都加入 MOS 管隔离，信号是反相的。
                例如常规的 高电平 使能
 */
void duojiinit()
{
  ftm_pwm_init(SD5_FTM, SD5_CH,SD5_HZ,7);      //初始化 舵机 PWM
}
void duojicontrol()
{
  
}
