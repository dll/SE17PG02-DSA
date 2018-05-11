
#ifndef DSAFUNLIB_H
#define DSAFUNLIB_H

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

#endif
