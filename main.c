#include <stdlib.h>
#include "memTest.h"

int main(){
	MemTestObj* obj = new_MemTestObj();
	delete_MemTestObj(obj);
	return 0;
}
