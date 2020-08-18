#include "gdt.h"
#include "string.h"

#define GDT_LENGTH 5

gdt_entry_t gdt_entries[GDT_LENGTH];

gdt_ptr_t gdt_ptr;

extern uint32_t stack;

static void gdt_set_gate(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran)
{
	gdt_entries[num].base_low = (base & 0XFFFF);
	gdt_entries[num].base_middle = (base >> 16) & 0XFF;
	gdt_entries[num].base_high = (base >> 24) & 0XFF;
	gdt_entries[num].limit_low = (limit & 0XFFFF);
	gdt_entries[num].granularity = (limit >> 16) & 0X0F;
	gdt_entries[num].granularity |= gran & 0XF0; 
	gdt_entries[num].access = access;
}

void init_gdt()
{
	gdt_ptr.limit = sizeof(gdt_entry_t) * GDT_LENGTH -1;
	gdt_ptr.base = (uint32_t)&gdt_entries;

	gdt_set_gate(0,0,0,0,0);
	gdt_set_gate(1,0,0XFFFFFFFF,0X9A,0XCF);
	gdt_set_gate(2,0,0XFFFFFFFF,0X92,0XCF);
	gdt_set_gate(3,0,0XFFFFFFFF,0XFA,0XCF);
	gdt_set_gate(4,0,0XFFFFFFFF,0XF2,0XCF);

	gdt_flush((uint32_t)&gdt_ptr);
}
