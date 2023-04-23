
.global _start

_start:
    /* 设置处理器进入SVC模式，即设置0-4位为10011 */
    mrs r0, cpsr        //读取cpsr到r0
    bic r0, r0, #0x1f   //清除bit0-4位
    orr r0, r0, #0x13   //进入SVC模式
    msr cpsr, r0        //将r0写入cpsr

    /* 设置SP指针 */
    ldr sp, = 0x80200000  // 设置sp指针
    b main                // 跳转到C程序main函数

