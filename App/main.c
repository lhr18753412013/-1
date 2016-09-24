/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       main.c
 * @brief      ɽ��K60 ƽ̨������
 * @author     ɽ��Ƽ�
 * @version    v5.0
 * @date       2013-08-28
 */

#include "common.h"
#include "include.h"

uint8 imgbuff[CAMERA_SIZE];                             //����洢����ͼ�������
uint8 img[CAMERA_W*CAMERA_H];

//��������
void PORTB_IRQHandler();
void DMA0_IRQHandler();



/*!
 *  @brief      main����
 *  @since      v5.3
 *  @note       ɽ������ͷ LCD ����ʵ��
 */
void  main(void)
{
    uart_init(UART4,115200);
    Site_t site     = {0, 0};                           //��ʾͼ�����Ͻ�λ��
    Size_t imgsize  = {CAMERA_W, CAMERA_H};             //ͼ���С
    Size_t size;                   //��ʾ����ͼ���С
    uint8 img_buf[CAMERA_H][CAMERA_W];

    LCD_init();
    LCD_str            (site,"Cam init ing",FCOLOUR,BCOLOUR);

    size.H = LCD_H;
    size.W = LCD_W;

    camera_init(imgbuff);

    LCD_str            (site,"Cam init OK!",FCOLOUR,BCOLOUR);
    //�����жϷ�����
    set_vector_handler(PORTB_VECTORn , PORTB_IRQHandler);   //����LPTMR���жϷ�����Ϊ PORTA_IRQHandler
    set_vector_handler(DMA0_VECTORn , DMA0_IRQHandler);     //����LPTMR���жϷ�����Ϊ PORTA_IRQHandler
    speedinit();                                            //�ٶȳ�ʼ��
    duojiinit();                                            //�����ʼ��
    while(1)
    {
        camera_get_img();                                   //����ͷ��ȡͼ��
        img_extract((uint8 *)img_buf,(uint8 *) imgbuff, CAMERA_H*CAMERA_W/8);

        //�ڰ�����ͷ
       LCD_Img_Binary_Z(site, size, imgbuff, imgsize);//�Ҷ�


        vcan_sendimg(imgbuff,CAMERA_SIZE);
       //img_extract(img, imgbuff, CAMERA_SIZE);          //��ѹΪ�Ҷ�ͼ�񣬷��㷢�͵���λ����
       // vcan_sendimg(img, sizeof(img));
       duojicontrol();                                  //������ƽǶ�
       speedcontrol();                                  // �������
       speedoutput();

    }
}


/*!
 *  @brief      PORTA�жϷ�����
 *  @since      v5.0
 */
void PORTB_IRQHandler()
{
    uint8  n;    //���ź�
    uint32 flag;

    while(!PORTB_ISFR);
    flag = PORTB_ISFR;
    PORTB_ISFR  = ~0;                                   //���жϱ�־λ

    n = 21;                                             //���ж�
    if(flag & (1 << n))                                 //PTB21�����ж�
    {
        camera_vsync();
    }
#if ( CAMERA_USE_HREF == 1 )                            //ʹ�����ж�
    n = 23;
    if(flag & (1 << n))                                 //PTB23�����ж�
    {
        camera_href();
    }
#endif
    
    
}

/*!
 *  @brief      DMA0�жϷ�����
 *  @since      v5.0
 */
void DMA0_IRQHandler()
{
    camera_dma();
}


