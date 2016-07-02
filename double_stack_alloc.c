#include "double_stack_alloc.h"
#include "alloc_error.h"

void dbl_sta_init(mem_double_stack_t *stack, void *buf, size_t stack_sz){
	stack->pointer = 0;	
	stack->high_pointer = stack_sz;
	stack->buf = buf;
	stack->size = stack_sz;
}

void *dbl_sta_alloc(mem_double_stack_t *stack, size_t block_sz){
	if((stack->pointer + block_sz) >= stack->high_pointer){
		return NULL;
	}
	void *top = (void *)(stack->buf + stack->pointer);
	stack->pointer += block_sz;
	return top;
}

uint32_t dbl_sta_get_high_mark(mem_double_stack_t *stack){
	return stack->pointer;
}

void dbl_sta_free_to_mark(mem_double_stack_t *stack, uint32_t mark){
	if(mark < stack->pointer){
		stack->pointer = mark;
	}	
}

void dbl_sta_clear(mem_double_stack_t *stack){
	stack->pointer = 0;
}

void *dbl_sta_alloc_high(mem_double_stack_t *stack, size_t block_sz){
	uint32_t high_pointer_new = stack->high_pointer - block_sz;
	if((high_pointer_new <= stack->pointer) || 
	(high_pointer_new >= stack->size)){
		return NULL;
	}
	return (stack->buf + (stack->high_pointer -= block_sz));
}

uint32_t dbl_sta_get_high_mark_high(mem_double_stack_t *stack){
	return stack->high_pointer;
}
void dbl_sta_free_to_mark_high(mem_double_stack_t *stack, uint32_t mark){
	if((mark > stack->high_pointer) && (mark < stack->size)){
		stack->high_pointer = mark;
	}	
}

void dbl_sta_clear_high(mem_double_stack_t *stack){
	stack->high_pointer = stack->size;
}
