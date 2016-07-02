#ifndef DOUBLE_STACK_ALLOC_H
#define DOUBLE_STACH_ALLOC_H

#include <stdint.h>
#include <stddef.h>

typedef struct{
	char *buf;
	uint32_t pointer;		
	uint32_t high_pointer;
	size_t size;
}mem_double_stack_t;

void dbl_sta_init(mem_double_stack_t *stack, void *buf, size_t stack_sz);
void *dbl_sta_alloc(mem_double_stack_t *stack, size_t block_sz);
void *dbl_sta_alloc_high(mem_double_stack_t *stack, size_t block_sz);
uint32_t dbl_sta_get_high_mark(mem_double_stack_t *stack);
void dbl_sta_free_to_mark(mem_double_stack_t *stack, uint32_t mark);
uint32_t dbl_sta_get_high_mark_high(mem_double_stack_t *stack);
void dbl_sta_free_to_mark_high(mem_double_stack_t *stack, uint32_t mark);
void dbl_sta_clear(mem_double_stack_t *stack);
void dbl_sta_clear_high(mem_double_stack_t *stack);

#endif
