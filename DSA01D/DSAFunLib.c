#include"DSAFunLib.h"

//DSA00PF begin
void *getMax(const void *data, int unitSize, int length, cmpFun cmpfun, int flag) {
	int i;
	char *ptr = (char*)data;//char1字节，基本存储单位，其它数据类型都是char类型的整数倍 
	char *max = ptr;//max取得data首地址：第一个字节 

	for(i=1; i<length; i++) {
		char *item = ptr+i*unitSize;//item取第二元素后的所有数据，i*unitSize:int4,float8,double8 
		if(cmpfun(item,max,flag)>0)//-1, 0, 1 
			max = item;
	}
	return max;
}

//DSA01D begin
void DSADataGenerator(void* data, int unitSize, int length,
	const void * begin, const void * end, genFun genfun, int flag){
	int i;
	char *ptr = (char*)data;//data：void*转成字符*类型 
	
	for(i=1; i<=length; i++) {	
		char * item = ptr+i*unitSize;//i的size倍数		
		*item= *(char*)genfun(data, begin, end, i, flag); 		 
		if(i==length)
			ptr[0] = *item;
		else 
			ptr[i*unitSize] = *item;
	}
}
