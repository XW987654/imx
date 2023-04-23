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

/* 初始化蜂鸣器 */
void beep_init(void)
{
    SW_MUX_SNVS_TAMPER1 = 0x00000005; //复用为GPIO5-IO01
    SW_PAD_SNVS_TAMPER1 = 0x000010b0; //配置GPIO5-IO01电气属性

    /* GPIO初始化 */
    GPIO5_GDIR = 0x00000002;        //设置bit1方向为1(输出)
    GPIO5_DR = 0x00000000;          //输出低电平0,打开蜂鸣器
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

/* 打开蜂鸣器 */
void beep_on(void)
{
    GPIO5_DR &= ~(1 << 1);  //bit1置0，即输出低电平，打开蜂鸣器            
}

void beep_off(void)
{
    GPIO5_DR |= (1 << 1);   //bit1置1，即输出高电平，关闭蜂鸣器
}

int main(void)
{
    clk_enable();       //使能时钟
    beep_init();         //初始化蜂鸣器

    /* 初始化beep */
    while(1) {
        beep_on();
        delay(500);
        beep_off();
        delay(500);
    }
    return 0; 
}


