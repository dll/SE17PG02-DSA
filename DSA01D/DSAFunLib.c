#include"DSAFunLib.h"

//DSA00PF begin
void *getMax(const void *data, int unitSize, int length, cmpFun cmpfun, int flag) {
	int i;
	char *ptr = (char*)data;//char1�ֽڣ������洢��λ�������������Ͷ���char���͵������� 
	char *max = ptr;//maxȡ��data�׵�ַ����һ���ֽ� 

	for(i=1; i<length; i++) {
		char *item = ptr+i*unitSize;//itemȡ�ڶ�Ԫ�غ���������ݣ�i*unitSize:int4,float8,double8 
		if(cmpfun(item,max,flag)>0)//-1, 0, 1 
			max = item;
	}
	return max;
}

//DSA01D begin
void DSADataGenerator(void* data, int unitSize, int length,
	const void * begin, const void * end, genFun genfun, int flag){
	int i;
	char *ptr = (char*)data;//data��void*ת���ַ�*���� 
	
	for(i=1; i<=length; i++) {	
		char * item = ptr+i*unitSize;//i��size����		
		*item= *(char*)genfun(data, begin, end, i, flag); 		 
		if(i==length)
			ptr[0] = *item;
		else 
			ptr[i*unitSize] = *item;
	}
}
