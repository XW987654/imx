#include "main.h"

/* 使能时钟 */
void clk_enable(void)
{
    CCM_CCGR1 = 0xffffffff;
    CCM_CCGR2 = 0xffffffff;
    CCM_CCGR3 = 0xffffffff;
    CCM_CCGR4 = 0xffffffff;
    CCM_CCGR5 = 0xffffffff;
    CCM_CCGR6 = 0xffffffff;
}

/* 初始化LED */
void led_init(void)
{
    SW_MUX_GPIO1_IO03 = 0x00000005; //复用为GPIO1-IO03
    SW_PAD_GPIO1_IO03 = 0x000010b0; //配置GPIO1-IO03电气属性

    /* GPIO初始化 */
    GPIO1_GDIR = 0x00000008;        //设置bit3方向为1(输出)
    GPIO1_DR = 0x00000000;          //输出低电平0,打开LED灯
}

/* 短延时 */
void delay_short(volatile unsigned int n)
{
    while(--n){}
}

/* 延时  循环一次大约1ms, 在主频396MHz时
 * n：延时ms数
 * */

void delay(volatile unsigned int n)
{
    while(--n){
        delay_short(0x7ff);
    }
}

/* 打开LED灯 */
void led_on(int pin)
{
    GPIO1_DR &= ~(1 << pin);  //bit3置0，即输出低电平，打开led灯            
}

void led_off(void)
{
    GPIO1_DR |= (1 << 3);   //bit3置1，即输出高电平，关闭led灯
}

int main(void)
{
    clk_enable();       //使能时钟
    led_init();         //初始化LED

    /* 初始化LED */
    while(1) {
        led_on(3);
        delay(500);
        led_off();
        delay(500);
    }
    return 0; 
}


