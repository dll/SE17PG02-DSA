
#ifndef DSA00PF_H
#define DSA00PF_H

struct studCources {
	char studNo [10] ;
	char cources[20] ;
	double grade;
};

int intCmp(const void *a, const void *b, int flag);
int studCourcesCmp(const void *a, const void *b, int flag);

//用户想获得float类型的最大值时
//1,声明float比较函数
int floatCmp(const void *a, const void *b, int flag);
#endif
