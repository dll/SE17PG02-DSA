#include<stdlib.h>
#include"DSA00PF.h"

/*
自定义函数的实现 
*/ 


/*
2,定义/实现函数 
*/

int myMax(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}

double myMax0(double a, double b){
	/*if(a>b)*/
	if(0<a-b)
		return a;
	else
		return b;
}

char myMax1(char a, char b){
	if(a>b)
		return a;
	else
		return b;
}

struct studCources myMax2(struct studCources a, struct studCources b, int flag){
	struct studCources c= {"000","000",0.0};
	if(0==flag){
		if(a.studNo>b.studNo)
			c=a;
		else
			c=b;
	}else if(1==flag){
		if(0>a.grade-b.grade)
			c=a;
		else
			c=b;
	}else{
		return c;
	}
	return c;
}

void * myMax3(void *a, void *b, int s, int f){
	if(s==sizeof(int)){ 
		if(*(int *)a > *(int *)b)//比较函数 
			return (void*)a;//a;(int*)-->(void*) 
		else
			return (void*)b;				
	} 
	else if(s==sizeof(double)){
		if(0<*(double *)a-*(double *)b)//比较函数 
			return (void*)a;
		else
			return (void*)b;			
	}
	else if(s==sizeof(char)){
		if(*(int *)a>*(int *)b)//比较函数 
			return (void*)a;
		else
			return (void*)b;		
	}
	else if(s==sizeof(struct studCources)){ 
		if(0==f){
			if(stricmp(((struct studCources*)a)->studNo,((struct studCources*)b)->studNo))//比较函数 
				return (struct studCources*)a;
			else
				return (struct studCources*)b;
		}else if(1==f){
			if(0<(((struct studCources*)a)->grade-((struct studCources*)b)->grade))//比较函数 
				return (struct studCources*)a;
			else
				return (struct studCources*)b;
		}else{
			return 0;
		}
	}
	//else if(s==sizeof(float))//... 
	else
		return 0;
}


// myMax4 函数参数说明：
// data 待比较数据数组的首地址,uniteSize单元字节个数
// length：数据的长度。{1,3,5,6}：length=4
// 比较data1和data2指向的数据做比较，
// 如果data1>data2，则返回正数
void *myMax4(void *a, int unitSize, int length, compareFunc func, int flag)
{
    int i;
    char *ptr = (char*)a;//char1字节，是标准：int=char*4;double=char*8 
    char *max = ptr;
    
    for(i=1;i<length;i++)
    {
        char *item = ptr+i*unitSize;
        //到底取几个字节进行比较是func内部的事情
        if(func(item,max,flag)>0)
        {
            max = item;
        }
    }

    return (void*)max;//void*可以隐式接受任意数据类型，显示转换void* -->(int*) 
}

int intCmp(void *a,void *b, int flag){
    int *ptr1 = (int*)a;
    int *ptr2 = (int*)b;

    int i1=*ptr1;
    int i2=*ptr2;

    return i1-i2;//if(i1>i2)return i1;else return i2; i1-i2?i1:i2;
}
int studCourcesCmp(void *a, void *b, int flag){
	struct studCources *x = (struct studCources*)a;
    struct studCources *y = (struct studCources*)b;
	if(flag==1)
		return (x->grade)-(y->grade);
	else if(flag==0)
    	return (strcmp(x->studNo, y->studNo));
    else
    	return 0;	
}
