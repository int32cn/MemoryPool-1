#include <MemoryPool.h>


void mp_ctor(mp_t * const me, void * const addr, size_t num_blks, size_t blk_size)
{
	int8_t *pblk;
	void **pnext_blk;
	
	pnext_blk = (void **)addr;
	pblk = (int8_t *)addr + blk_size;

	uint32_t i;
	for(i = 0; i < num_blks - 1; i++){
		*pnext_blk = pblk;
		pnext_blk = (void **)pblk;
		pblk = pblk + blk_size;

	}
	pnext_blk = (void *)0;

	me->mem_start = addr;
	me->mem_free_blk = addr;
	me->mem_num_blks = num_blks;
	me->mem_num_free = num_blks;
	me->mem_blk_size = blk_size;
}

void *mp_get(mp_t * const me)
{
	void *pblk;

	if (me->mem_num_free > 0){
		pblk = me->mem_free_blk;
		me->mem_free_blk = *(void **)pblk;
		me->mem_num_free--;
		return pblk; 
	}

	return (void *)0;	
}

void mp_put(mp_t * const me, void *pblk)
{
	if (pblk != NULL) {
		*(void **)pblk = me->mem_free_blk;
		me->mem_free_blk = pblk;
		me->mem_num_free++;	
	}
}


