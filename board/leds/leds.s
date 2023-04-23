
.global _start  /* 全局标号 */

_start:
	/* 使能所有外设时钟 */
    ldr r0, = 0x020c4068 /*CCGR0的地址*/
    ldr r1, = 0xffffffff /*将0xffffffff读入，准备写入到r0中*/
    str r1, [r0]	/*将0xffffffff写入到CCGR0中*/

    ldr r0, = 0x020c406c /*CCGR1的地址*/
    ldr r1, = 0xffffffff /*将0xffffffff读入，准备写入到r0中*/
    str r1, [r0]	/*将0xffffffff写入到CCGR0中*/

    ldr r0, = 0x020c4070 /*CCGR2的地址*/
    ldr r1, = 0xffffffff /*将0xffffffff读入，准备写入到r0中*/
    str r1, [r0]	/*将0xffffffff写入到CCGR0中*/

    ldr r0, = 0x020c4074 /*CCGR3的地址*/
    ldr r1, = 0xffffffff /*将0xffffffff读入，准备写入到r0中*/
    str r1, [r0]	/*将0xffffffff写入到CCGR0中*/

    ldr r0, = 0x020c4078 /*CCGR4的地址*/
    ldr r1, = 0xffffffff /*将0xffffffff读入，准备写入到r0中*/
    str r1, [r0]	/*将0xffffffff写入到CCGR0中*/

    ldr r0, = 0x020c407c /*CCGR5的地址*/
    ldr r1, = 0xffffffff /*将0xffffffff读入，准备写入到r0中*/
    str r1, [r0]	/*将0xffffffff写入到CCGR0中*/

    ldr r0, = 0x020c4080 /*CCGR6的地址*/
    ldr r1, = 0xffffffff /*将0xffffffff读入，准备写入到r0中*/
    str r1, [r0]	/*将0xffffffff写入到CCGR0中*/

    /*配置GPIO1_IO03 pin的复用为GPIO
    即配置IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 = 5
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03寄存器的地址为0x020e0068
    */

    ldr r0, = 0x020e4068  /* IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03的地址*/
    ldr r1, = 0x00000005  /* 将要写入的数据 */
    str r1, [r0]          /*  将0x5写入r0 */

    /* 配置 GPIO1_IO03 的电气属性，即寄存器
    OMUXC_SW_PAD_CTL_PAD_GPIO1_IO03 的电器属性
    IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03 地址为0x020e02f4
    按参考手册1588页配置寄存器
    bit0:       0 低速率
    bit3-5:     110 驱动能力R0/6
    bit6-7:     10   100MHz速度
    bit11：     0   关闭开路输出
    bit12：     1   使能Pull / Keep
    bit13：     0   keeper
    bit14-15：  00  100k下拉
    bit16：     0   关闭hyst
    用计算器算得需要写入的数字为0x10b0
    */
    
    ldr r0, = 0x020e02f4
    ldr r1, = 0x000010b0
    str r1, [r0]

    /* 配置GPIO 设置GPIO1_GDIR寄存器，设置GPIO1_GPIO03为输出，
    按参考手册1154页配置
    寄存器GPIO1_GDIR地址为0x0209c004，即设置GPIO1_GDIR的bit3位为1
    */

    ldr r0, = 0x0209c004
    ldr r1, = 0x00000008
    str r1, [r0]

    /* 打开LED,即设置GPIO1_IO03为0，输出低电平
    寄存器GPIO1_DR的地址为0x0209c000
    */
    
    ldr r0, = 0x0209c000
    ldr r1, = 0x00000000
    str r1, [r0]


    /* 设置死循环 */
loop:
    b loop
