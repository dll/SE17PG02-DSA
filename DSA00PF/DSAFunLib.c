#include"DSAFunLib.h"

void *getMax(const void *data, int unitSize, int length, cmpFun cmpfun, int flag) {
	int i;
	char *ptr = (char*)data;
	char *max = ptr;

	for(i=1; i<length; i++) {
		char *item = ptr+i*unitSize;
		if(cmpfun(item,max,flag)>0)
			max = item;
	}
	return max;
}
