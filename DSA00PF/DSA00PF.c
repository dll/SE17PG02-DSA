#include<stdlib.h>
#include"DSA00PF.h"

/*
�Զ��庯����ʵ�� 
*/ 


/*
2,����/ʵ�ֺ��� 
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
		if(*(int *)a > *(int *)b)//�ȽϺ��� 
			return (void*)a;//a;(int*)-->(void*) 
		else
			return (void*)b;				
	} 
	else if(s==sizeof(double)){
		if(0<*(double *)a-*(double *)b)//�ȽϺ��� 
			return (void*)a;
		else
			return (void*)b;			
	}
	else if(s==sizeof(char)){
		if(*(int *)a>*(int *)b)//�ȽϺ��� 
			return (void*)a;
		else
			return (void*)b;		
	}
	else if(s==sizeof(struct studCources)){ 
		if(0==f){
			if(stricmp(((struct studCources*)a)->studNo,((struct studCources*)b)->studNo))//�ȽϺ��� 
				return (struct studCources*)a;
			else
				return (struct studCources*)b;
		}else if(1==f){
			if(0<(((struct studCources*)a)->grade-((struct studCources*)b)->grade))//�ȽϺ��� 
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


// myMax4 ��������˵����
// data ���Ƚ�����������׵�ַ,uniteSize��Ԫ�ֽڸ���
// length�����ݵĳ��ȡ�{1,3,5,6}��length=4
// �Ƚ�data1��data2ָ����������Ƚϣ�
// ���data1>data2���򷵻�����
void *myMax4(void *a, int unitSize, int length, compareFunc func, int flag)
{
    int i;
    char *ptr = (char*)a;//char1�ֽڣ��Ǳ�׼��int=char*4;double=char*8 
    char *max = ptr;
    
    for(i=1;i<length;i++)
    {
        char *item = ptr+i*unitSize;
        //����ȡ�����ֽڽ��бȽ���func�ڲ�������
        if(func(item,max,flag)>0)
        {
            max = item;
        }
    }

    return (void*)max;//void*������ʽ���������������ͣ���ʾת��void* -->(int*) 
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
