
#ifndef DSAFUNLIB_H
#define DSAFUNLIB_H

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

#endif
