#ifndef INCLUDE_GDT_H_
#define INCLUDE_GDT_H_

#include "types.h"

typedef struct gdt_entry_t{
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t  base_middle;
	uint8_t  access;
	uint8_t  granularity;
	uint8_t  base_high;
}__attribute__((packed)) gdt_entry_t;

typedef struct gdt_ptr_t {
	uint16_t limit;
	uint32_t base;
}__attribute__((packed)) gdt_ptr_t;

void init_gdt();

extern void gdt_flush(uint32_t);
#endif
