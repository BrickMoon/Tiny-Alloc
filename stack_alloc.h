#ifndef STACK_ALLOC_H
#define STACH_ALLOC_H

#include <stdint.h>
#include <stddef.h>

typedef struct{
	char *buf;
	uint32_t pointer;		
	size_t size;
}mem_stack_t;

void sta_init(mem_stack_t *stack, void *buf, size_t stack_sz);
void *sta_alloc(mem_stack_t *stack, size_t block_sz);
uint32_t sta_get_high_watermark(mem_stack_t *stack);
void sta_free_to_watermark(mem_stack_t *stack, uint32_t mark);
void sta_clear(mem_stack_t *stack);

#endif
