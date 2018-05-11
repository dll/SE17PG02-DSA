#include"DSAFunLib.h"

void *getMax(const void *data, int unitSize, int length, cmpFun cmpfun, int flag) {
	int i;
	char *ptr = (char*)data;//char1字节，基本存储单位，其它数据类型都是char类型的整数倍 
	char *max = ptr;//max取得data首地址：第一个字节 

	for(i=1; i<length; i++) {
		char *item = ptr+i*unitSize;//item取第二元素后所有数据，i*unitSize:int4,float8,double8 
		if(cmpfun(item,max,flag)>0)//-1, 0, 1 
			max = item;
	}
	return max;
}
