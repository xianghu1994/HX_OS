#include "console.h"

int kern_entry()
{
	console_clear();

	console_write_color("Hello, World!\n",rc_black, rc_green);
	
	printk("aoaoao\n");
	return 0;
}
