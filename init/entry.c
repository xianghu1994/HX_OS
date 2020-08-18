#include "console.h"
#include "debug.h"
#include "gdt.h"

int kern_entry()
{
	init_debug();
	init_gdt();

	console_clear();
	printk("Hello World\n");

	panic("test");

	return 0;
}
