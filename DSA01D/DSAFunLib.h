
#ifndef DSAFUNLIB_H
#define DSAFUNLIB_H

//DSA00PF begin
//����ָ�룺 �ȽϺ����Ľӿ� 
// a,b:const void *����
//flag:getMax����Ĳ��� 
typedef int (*cmpFun)(const void *a, const void *b, int flag);
//data->base������ַ 
//s����λ��С
//length����������,2,..n 
//cmpFun���ȽϺ���compareFunction���û�ʵ�֣� 
//flag�������򣬻���ָ���ṹ��ĳ��Ա���бȽ� 
void *getMax(const void *data, int s, int length, cmpFun cmpfun, int flag);

//DSA01D begin
//���ɺ������û���̡�const void * data,size������ 
typedef int (*genFun)(void* data, const void *begin, const void *end, int size,int flag);
//data������ݣ�size������λ��length������begin��ʼ��end������genfun���ɺ�����flag0���ظ���1�����ظ� 
void DSADataGenerator(void* data, int unitSize, int length, const void * begin, const void * end, genFun genfun, int flag);

#endif
