
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

//�û�����float���͵����ֵʱ
//1,����float�ȽϺ���
int floatCmp(const void *a, const void *b, int flag);

int qsortfCmp(const void *a, const void *b);//qsort�⺯���ıȽϺ���ֻ�������������������� 

//DSA01D begin
//����int������ size����int���� 
void *intGen(void* data, const void *begin, const void *end,int size, int flag);
void *studCourcesGen(void* data, const void *begin, const void *end, int size, int flag); 

#endif
