#include"DSA00PF.h"


int intCmp(const void *a, const void *b, int flag){
	return *(int*)a-*(int*)b;
}
int studCourcesCmp(const void *a, const void *b, int flag){
	struct studCources *x = (struct studCources*)a;
    struct studCources *y = (struct studCources*)b;
	if(flag==0)
		return (strcmp(x->studNo, y->studNo));
	else if(flag==1)
		return (x->grade)-(y->grade);
    else
    	return 0;	
}
//2,定义比较函数 
int floatCmp(const void *a, const void *b, int flag){
    return *(float*)a-*(float*)b;
}
