
#ifndef DSA00PF_H
#define DSA00PF_H

struct studCources {
	char studNo [10] ;
	char cources[20] ;
	double grade;
};

int intCmp(const void *a, const void *b, int flag);
int studCourcesCmp(const void *a, const void *b, int flag);

//�û�����float���͵����ֵʱ
//1,����float�ȽϺ���
int floatCmp(const void *a, const void *b, int flag);
#endif
