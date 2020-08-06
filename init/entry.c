#include "console.h"
#include "debug.h"

int kern_entry()
{
	init_debug();

	console_clear();
	int i = 0;
	printk("test:%d",i);
	printk("Hello World\n");
	printk("Hello World2\n");

	panic("test");

	return 0;
}
