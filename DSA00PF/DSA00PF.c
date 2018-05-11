#include"DSA00PF.h"


int intCmp(const void *a, const void *b, int flag){
	return *(int*)a-*(int*)b;
}
int studCourcesCmp(const void *a, const void *b, int flag){
	struct studCources *x = (struct studCources*)a;
    struct studCources *y = (struct studCources*)b;
	if(flag==0)
		return (strcmp(x->studNo, y->studNo));//strcmp字符串比较函数原型 
	else if(flag==1)
		return (x->grade)-(y->grade);
    else
    	return 0;	
}
//2,定义比较函数 
int floatCmp(const void *a, const void *b, int flag){  
	if(*(float*)a-*(float*)b==0) 
		return 0;
	else
		return *(float*)a-*(float*)b>0?1:-1;
}

int qsortfCmp(const void *a, const void *b){
	return floatCmp(a, b, 0);
}
