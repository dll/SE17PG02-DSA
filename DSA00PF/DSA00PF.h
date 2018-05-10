
/*
返回两个数中较大者
两个整型参数 
1，声明一个函数 
*/ 
int myMax(int a, int b);

/*
1,安装Github Extensions
2，创建本地代码仓库
3，将Dev-C++的项目提交到本地仓库 
4，将本地仓库提交到远程仓库：https://github.com/dll/SE17PG02-DSA.git 
5，下载 https://github.com/ SE17PG02-DSA-master.zip
*/

double myMax0(double a, double b);


char myMax1(char a, char b);

/*
Hello! This is a console application.
Press q to quit, press a to execute myMax.
a
Please input two integer numbers:
 m n
max=1
max0=1.00
max1=Unknown command 'm'! Ignoring...
Unknown command ' '! Ignoring...
Unknown command 'n'! Ignoring...
C语言输入和输出流的缓存，需要清理，而C++的cin/cout对此改进！ 

fflush(stdin)
*/

struct studCources {
	char studNo[10] ;
	char cources[20] ;
	double grade; 
}; 

/*
比较 struct studCources的大小，根据flag为0时，返回学号较大者，flag为1时，返回成绩较高者 
否则，flag不是0/1，返回空的结构体 
*/
struct studCources myMax2(struct studCources a, struct studCources b, int flag);

/**
myMax3函数：返回任意类型的两数中的最大者 
返回void*即void指针类型的函数，返回a,b中最大者
参数：
a,b都是void*类型，与函数返回值类型相同
s是a,b相同类型的内存大小：int4,double8,char1,studCources40(为什么不是38字节？结构体成员对齐） 
f是标志，可以设计为返回最小或最大；按照结构体不同成员返回最大者等 
*/ 
void *myMax3(void *a, void *b, int s, int f); 


typedef int (*compareFunc)(void *a,void *b,int flag);
void *myMax4(void *a, int s, int length, compareFunc func, int flag);
int intCmp(void *a,void *b, int flag);
int studCourcesCmp(void *a, void *b, int flag);
