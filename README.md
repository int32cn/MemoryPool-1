Statically Allocated Memory Pool for Embedded Systems
======================================
This Module is an implementation of memory pool in C.

## Compiling 
	$ make

## Example

	#include <stdio.h>
	#include <string.h>
	#include <MemPool.h>

	#define num_of_blks 3
	#define block_size 10
	static mp_t txMemPool;
	static int8_t txMem[num_of_blks][block_size];

	int main()
	{

		mp_ctor(&txMemPool, txMem, num_of_blks, block_size);

		int32_t * p = mp_get(&txMemPool);
		if (p != NULL){
			memset(p, 1, block_size);
			mp_put(&txMemPool, p);
		}
		p = mp_get(&txMemPool);

		int32_t *q = mp_get(&txMemPool);
		int32_t *k = mp_get(&txMemPool);

		memset(p, 1, block_size);
		memset(q, 1, block_size);
		memset(k, 1, block_size);

		int32_t *f = mp_get(&txMemPool);
		if (f != NULL) {

		} else {
			printf("there is no available memory\n");
		}

		mp_put(&txMemPool, f);
		mp_put(&txMemPool, q);
		mp_put(&txMemPool, k);
		
		mp_put(&txMemPool, p);

		return 0;
	}


