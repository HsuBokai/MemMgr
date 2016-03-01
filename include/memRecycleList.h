#ifndef _MEM_RECYCLE_LIST_H_
#define _MEM_RECYCLE_LIST_H_

typedef struct _MemRecycleList MemRecycleList;

struct _MemRecycleList {
	size_t	_arrSize;
	void* _first;
	MemRecycleList*  _nextList;
};

void resetRecycleList(MemRecycleList* obj) {
	if(obj->_nextList!=0) free(obj->_nextList);
	obj->_nextList = 0;
	obj->_first = 0;
}

MemRecycleList* new_MemRecycleList(const size_t a){
	MemRecycleList* obj = (MemRecycleList*) malloc(sizeof(MemRecycleList));
	obj->_arrSize = a;
	obj->_first = 0;
	obj->_nextList = 0;
	return obj;
}

void delete_MemRecycleList(MemRecycleList* obj) {
	resetRecycleList(obj);
	free(obj);
	obj = 0;
}

size_t getArrSize(const MemRecycleList* obj) { return obj->_arrSize; }

MemRecycleList* getNextList(const MemRecycleList* obj) { return obj->_nextList; }

void setNextList(MemRecycleList* obj, MemRecycleList* l) { obj->_nextList = l; }

void* popFront(MemRecycleList* obj) {
	if(obj->_first==0) return 0;
	void* tp = obj->_first;
	obj->_first = *(void**) obj->_first;
	*(size_t*)tp = obj->_arrSize;
	return tp;
}

void pushFront(MemRecycleList* obj, void* p) {
	*(void**)p = obj->_first;
	obj->_first = p;
}

void* getNext(const MemRecycleList* obj, void* p) {
	return (p==0)? 0:*(void**)p;
}

size_t numElm(const MemRecycleList* obj) {
	size_t count = 0;
	void* p = obj->_first;
	while (p) {
		p = getNext(obj, p);
		++count;
	}
	return count;
}

#endif
