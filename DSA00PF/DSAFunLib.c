#include"DSAFunLib.h"

void *getMax(const void *data, int unitSize, int length, cmpFun cmpfun, int flag) {
	int i;
	char *ptr = (char*)data;//char1�ֽڣ������洢��λ�������������Ͷ���char���͵������� 
	char *max = ptr;//maxȡ��data�׵�ַ����һ���ֽ� 

	for(i=1; i<length; i++) {
		char *item = ptr+i*unitSize;//itemȡ�ڶ�Ԫ�غ��������ݣ�i*unitSize:int4,float8,double8 
		if(cmpfun(item,max,flag)>0)//-1, 0, 1 
			max = item;
	}
	return max;
}
