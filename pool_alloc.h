#ifndef POOL_ALLOC_H
#define POOL_ALLOC_H

#include <stddef.h>
#include <stdint.h>

typedef struct{
	char *buf;
	void *front;
	size_t obj_len;
}mem_pool_t;

void pool_create(mem_pool_t *p_pool, void *buf, size_t buf_len, size_t obj_len);
void *pool_alloc(mem_pool_t *p_pool);
void pool_free(mem_pool_t *p_pool, void *p_obj);

#endif
