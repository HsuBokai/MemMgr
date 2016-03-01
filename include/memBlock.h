#ifndef _MEM_BLOCK_H_
#define _MEM_BLOCK_H_

typedef struct _MemBlock MemBlock;

struct _MemBlock {
	char*		_begin;
	char*		_ptr;
	char*		_end;
	MemBlock*	_nextBlock;
};

MemBlock* new_MemBlock(MemBlock* n, size_t b){
	MemBlock* obj = (MemBlock*) malloc(sizeof(MemBlock));
	obj->_nextBlock = n;
	obj->_begin = malloc(b);
	obj->_ptr = obj->_begin;
	obj->_end = obj->_begin + b;
	return obj;
}

void delete_MemBlock(MemBlock* obj) {
	free(obj->_nextBlock);
	free(obj);
	obj = NULL;
}

void reset(MemBlock* obj) { 
	obj->_ptr = obj->_begin; 
}
/*
bool getMem(MemBlock* obj, size_t t, T*& ret) {
	t = toSizeT(t);
	ret = (T*)_ptr;
	return (getRemainSize() < t)? false : ( _ptr+=t ) == _ptr;
}
*/
size_t getRemainSize(const MemBlock* obj){ 
	return (size_t)(obj->_end - obj->_ptr); 
}

MemBlock* getNextBlock(const MemBlock* obj) {
	return obj->_nextBlock; 
}

#endif
