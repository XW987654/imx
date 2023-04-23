#ifndef __MAIN_H
#define __MAIN_H

/* 定义要使用的寄存器 */
#define CCM_CCGR0               *((volatile unsigned int *)0x020c4068)

#define CCM_CCGR1               *((volatile unsigned int *)0x020c406c)
#define CCM_CCGR2               *((volatile unsigned int *)0x020c4070)
#define CCM_CCGR3               *((volatile unsigned int *)0x020c4074)
#define CCM_CCGR4               *((volatile unsigned int *)0x020c4078)
#define CCM_CCGR5               *((volatile unsigned int *)0x020c407c)
#define CCM_CCGR6               *((volatile unsigned int *)0x020c4080)

/* IOMUX相关寄存器地址 */
#define SW_MUX_SNVS_TAMPER1       *((volatile unsigned int *)0x020e0020)
#define SW_PAD_SNVS_TAMPER1       *((volatile unsigned int *)0x020e02ac)

#define GPIO5_DR                *((volatile unsigned int *)0x020ac000)
#define GPIO5_GDIR              *((volatile unsigned int *)0x020ac004)

#endif
