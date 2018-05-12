#include <stdlib.h> 
#include <stdio.h>
#include <time.h>

#include"DSA00PF.h"

//DSA00PF begin
int intCmp(const void *a, const void *b, int flag){
	return *(int*)a-*(int*)b;
}
int studCourcesCmp(const void *a, const void *b, int flag){
	struct studCources *x = (struct studCources*)a;
    struct studCources *y = (struct studCources*)b;
	if(flag==0)
		return (strcmp(x->studNo, y->studNo));//strcmp字符串比较函数原型 
	else if(flag==1)
		return (x->grade)-(y->grade);
    else
    	return 0;	
}
//2,定义比较函数 
int floatCmp(const void *a, const void *b, int flag){  
	if(*(float*)a-*(float*)b==0) 
		return 0;
	else
		return *(float*)a-*(float*)b>0?1:-1;
}

int qsortfCmp(const void *a, const void *b){
	return floatCmp(a, b, 0);
}

//DSA01D begin
void  *intGen(void* data, const void *begin, const void *end, int size, int flag)
{
	int temp=*(int*)data;
	int *x = (int*)begin;
    int *y = (int*)end;
    int *i = &temp; 
    srand (time(NULL));//生成随机的时间种子 
    sleep(1);//休眠 
	if(flag==0){//可重复 		
		*i = rand() % (*y-*x) + *x;//生成随机数10---100： 10+rand()%90:0---89  10---99 
		return i;
	} 
	else if(flag==1){//不可重复 
		*i = rand() % (*y-*x) + *x;
		int f=0;
		while(1){
			f=0;
			for(int j=0;j<size;j++){
				if(*i==((int*)data)[j]){
					f=1;
					break;
				}
			}
			if(f==0)
				return i; 
			srand (time(NULL));
			*i = rand() % (*y-*x) + *x;
		} 
	} 
    else//错误 
    	return NULL;	
}
void *studCourcesGen(void* data, const void *begin, const void *end, int size, int flag)
{
	struct studCources *item = (struct studCources*)(data+(size-1)*sizeof(struct studCources));
	struct studCources *x = (struct studCources*)begin;
    struct studCources *y = (struct studCources*)end;
    srand (time(NULL));//生成随机的时间种子 
    sleep(1);//休眠 
	int xx= atoi(x->studNo+2);
	int yy= atoi(y->studNo+2);
	int intNo = rand() % (yy-xx) + xx; 
	char strNo[10]="";
	itoa(intNo, strNo, 10);
	strcpy(item->studNo,"SN0");		
	strcpy(item->studNo,strcat(item->studNo,strNo));
	
	xx= atoi(x->cources+2);
	yy= atoi(y->cources+2);
	int intCs = rand() % (yy-xx) + xx; 
	char strCs[10]="";
	itoa(intCs, strCs, 10);	
	strcpy(item->cources,"CN0");
	strcpy(item->cources,strcat(item->cources,strCs));	
	
	item->grade = rand() % ((int)y->grade-(int)x->grade) + (int)x->grade;
	//printf("%10s %20s %8.0lf\n", item->studNo, item->cources, item->grade);
	
	return item;	
}
