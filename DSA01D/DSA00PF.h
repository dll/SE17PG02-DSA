
#ifndef DSA00PF_H
#define DSA00PF_H
//DSA00PF begin
struct studCources {
	char studNo[10] ;
	char cources[20] ;
	double grade;
};

int intCmp(const void *a, const void *b, int flag);
int studCourcesCmp(const void *a, const void *b, int flag);

//用户想获得float类型的最大值时
//1,声明float比较函数
int floatCmp(const void *a, const void *b, int flag);

int qsortfCmp(const void *a, const void *b);//qsort库函数的比较函数只有两个参数，包裹函数 

//DSA01D begin
//生成int函数， size生成int个数 
void *intGen(void* data, const void *begin, const void *end,int size, int flag);
void *studCourcesGen(void* data, const void *begin, const void *end, int size, int flag); 

#endif
