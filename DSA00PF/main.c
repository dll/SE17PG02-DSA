#include <stdio.h>
#include <stdlib.h> 
#include"DSAFunLib.h"
#include"DSA00PF.h"


int main(int argc, char** argv) {
	char input = 0;

	int x, y;

	printf("Hi! �������ǵ�DSA��������Գ���.\n");
	printf("�밴q ���˳�, a ��ִ��getMax����\n");
	while(1) {
		if(scanf("%c",&input) == 1) {
			if(input == 'a') {
				// ����1:int���������ֵ
				int intnums[] = { 3, 1, 5, 8, 7, 6, 9, 2, 4 };
				int *pMax = (int *)getMax(intnums,sizeof(int),sizeof(intnums)/sizeof(int), intCmp, 0);
				int max = *pMax;
				printf("getMax=%d\n",max);

				// ����2:�ṹ�����������ֵ
				struct studCources scDatas[]= {{"se17","DSA",90}, {"se15","SE",99},{"se17","c",80}}, *cc;
				cc=(struct studCources*)getMax(scDatas,sizeof(struct studCources),sizeof(scDatas)/sizeof(struct studCources), studCourcesCmp, 1);
				printf("getMax=%.lf\n",cc->grade);
				cc=(struct studCources*)getMax(scDatas,sizeof(struct studCources),sizeof(scDatas)/sizeof(struct studCources), studCourcesCmp, 0);
				printf("getMax=%s\n",cc->studNo);

				//����3:float���������ֵ 3ʹ�ÿ⺯��getMax
				float floatnums[] = {3.14, 1.23, 5.20, 8.8, 2.17, 6.1888, 99, 2.56, 4.4};
				float *pfMax = (float *)getMax(floatnums,sizeof(float),sizeof(floatnums)/sizeof(float), floatCmp, 0);//4ʹ���û�����ıȽϺ���floatCmp
				float fmax = *pfMax;
				printf("getMax=%.4lf\n",fmax);
				
				qsort(floatnums,sizeof(floatnums)/sizeof(float),sizeof(float),qsortfCmp);
				for(int i=0; i<sizeof(floatnums)/sizeof(float);i++)
					printf("%.4lf ", floatnums[i]);

			} else if(input == 'q') {
				break;
			} else if(input != '\n') {
				printf("δ֪���� '%c'! ����...\n",input);
			}
		} else {
			printf("�Ƿ�����! ����...\n");
		}
	}

	return 0;
}


/*
Hi! �������ǵ�DSA��������Գ���.
�밴q ���˳�, a ��ִ��getMax����
a
getMax=9
getMax=99
getMax=se17
getMax=99.0000
1.2300 2.1700 2.5600 3.1400 4.4000 5.2000 6.1888 8.8000 99.0000

*/ 
