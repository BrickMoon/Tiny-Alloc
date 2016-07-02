#include "pool_alloc.h"

void pool_create(mem_pool_t *p_pool, void *buf, size_t buf_len, size_t obj_len){
	unsigned long long upper, i;

	//Make sure that the buffer is large enough for at least
	//one object
	if(buf_len < obj_len || obj_len < sizeof(void *)){
		p_pool->front = 0;
		return;
	}

	p_pool->front = buf;		
	p_pool->buf = p_pool->front;
	p_pool->obj_len = obj_len;

	upper = buf_len  - obj_len;
	for (i = 0; i < upper;){
		*(unsigned long long *)(p_pool->buf + i) = 
		(unsigned long long )(p_pool->buf + (i += obj_len));
	}
	*(unsigned long long *)(p_pool->buf + upper) = 0; 
}

void *pool_alloc(mem_pool_t *p_pool){
	void *front;

	//If front is null, the pool is empty.
	if(p_pool->front == NULL){
		return NULL;
	}

	front = p_pool->front;
	p_pool->front = (void *)(*(unsigned long long *)(p_pool->front));
	return front;
}

void pool_free(mem_pool_t *p_pool, void *p_obj){
	*(unsigned long long *)(p_obj) = (unsigned long long)p_pool->front;	
	p_pool->front = p_obj;
}
