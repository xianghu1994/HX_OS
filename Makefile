#!Makefile


C_SOURCES = $(shell find . -name "*.c")
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))
S_SOURCES = $(shell find . -name "*.s")
S_OBJECTS = $(patsubst %.s, %.o, $(S_SOURCES))

LD = ld
CC = gcc
ASM = nasm

C_FLAGS = -c -Wall -m32 -ggdb -gstabs+ -nostdinc -fno-builtin -fno-stack-protector -I include
LD_FLAGS = -T scripts/kernel.ld -m elf_i386 -nostdlib
ASM_FLAGS = -f elf -g -F stabs

all:$(S_OBJECTS) $(C_OBJECTS) link update_image

.c.o:
	@echo build C file $< ...
	$(CC) $(C_FLAGS) $< -o $@

.s.o:
	@echo build S file $< ...
	$(ASM) $(ASM_FLAGS) $<

link:
	@echo link kernel
	$(LD) $(LD_FLAGS) $(S_OBJECTS) $(C_OBJECTS) -o lzy_kernel

.PHONY:clean
clean:
	$(RM) $(S_OBJECTS) $(C_OBJECTS) lzy_kernel


.PHONY:update_image
update_image:
	sudo mount floppy.img /mnt/kernel
	sudo cp lzy_kernel /mnt/kernel/lzy_kernel
	sleep 1
	sudo umount /mnt/kernel

qemu:
	qemu -fda floppy.img -boot a


