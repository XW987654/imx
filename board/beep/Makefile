objs = start.o main.o

beep.bin : $(objs)
	arm-linux-gnueabihf-ld -Ttext 0x87800000 $^ -o beep.elf
	arm-linux-gnueabihf-objcopy -O binary -S beep.elf $@
	arm-linux-gnueabihf-objdump -D -m arm beep.elf > beep.dis

%.o : %.c
	arm-linux-gnueabihf-gcc -Wall -nostdlib -c -o $@ $<

%.o : %.S
	arm-linux-gnueabihf-gcc -Wall -nostdlib -c -o $@ $<

clean:
	rm -rf *.o beep.bin beep.elf beep.dis
