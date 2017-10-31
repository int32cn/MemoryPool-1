#ifndef __MEMORYPOOL_H__
#define __MEMORYPOOL_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct{

	void *mem_start;
	void *mem_free_blk;
	uint32_t mem_num_blks;
	uint32_t mem_blk_size;
	uint32_t mem_num_free;	

}mp_t;

void mp_ctor(mp_t * const me, void * const addr, size_t num_blks, size_t blk_size);
void *mp_get(mp_t * const me);
void mp_put(mp_t * const me, void *pblk);

#endif
