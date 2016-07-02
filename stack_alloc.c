#include "stack_alloc.h"
#include "alloc_error.h"

void sta_init(mem_stack_t *stack, void *buf, size_t stack_sz){
	stack->pointer = 0;	
	stack->buf = buf;
	stack->size = stack_sz;
}

void *sta_alloc(mem_stack_t *stack, size_t block_sz){
	//Add overflow protection.
	if((stack->pointer + block_sz) >= stack->size){
		return NULL;
	}
	void *top = (void *)(stack->buf + stack->pointer);
	stack->pointer += block_sz;
	return top;
}

uint32_t sta_get_high_mark(mem_stack_t *stack){
	return stack->pointer;
}

void sta_free_to_mark(mem_stack_t *stack, uint32_t mark){
	if(mark < stack->pointer){
		stack->pointer = mark;
	}	
}

void sta_clear(mem_stack_t *stack){
	stack->pointer = 0;
}
