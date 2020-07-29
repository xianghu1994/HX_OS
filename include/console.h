#ifndef INCLUDE_CONSOLE_H_
#define INCLUDE_CONSOLE_H_

#include "types.h"
typedef enum real_color {
	rc_black = 0,
	rc_blue = 1,
	rc_green = 2,
	rc_cyan = 3,
	rc_read = 4
}real_color_t;

void console_clear();

void console_putc_color(char c, real_color_t back, real_color_t fore);

//void console_write(char *cstr);

void console_write_color(char *cstr, real_color_t back, real_color_t fore);

//void console_write_hex(uint32_t n, real_color_t back, real_color_t fore);

//void console_write_dec(uint32_t n, real_color_t back, real_color_t fore);

#endif
