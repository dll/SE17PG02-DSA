
#ifndef DSAFUNLIB_H
#define DSAFUNLIB_H

//DSA00PF begin
//函数指针： 比较函数的接口 
// a,b:const void *类型
//flag:getMax传入的参数 
typedef int (*cmpFun)(const void *a, const void *b, int flag);
//data->base：基地址 
//s：单位大小
//length：数据总数,2,..n 
//cmpFun：比较函数compareFunction（用户实现） 
//flag：升降序，或者指定结构体某成员进行比较 
void *getMax(const void *data, int s, int length, cmpFun cmpfun, int flag);

//DSA01D begin
//生成函数：用户编程。const void * data,size重命名 
typedef int (*genFun)(void* data, const void *begin, const void *end, int size,int flag);
//data存放数据，size基本单位，length总数，begin开始，end结束，genfun生成函数，flag0可重复，1不可重复 
void DSADataGenerator(void* data, int unitSize, int length, const void * begin, const void * end, genFun genfun, int flag);

#endif
