#include <stdio.h>
#include <stdlib.h> 
#include"DSAFunLib.h"
#include"DSA00PF.h"


int main(int argc, char** argv) {
	char input = 0;

	int x, y;

	printf("Hi! 这是我们的DSA函数库测试程序.\n");
	printf("请按q 键退出, a 键执行DSADataGenerator函数\n");
	while(1) {
		if(scanf("%c",&input) == 1) {
			if(input == 'a') {
				// 测试1:int类型求最大值
				/*int intnums[] = { 3, 1, 5, 8, 7, 6, 9, 2, 4 };
				int *pMax = (int *)getMax(intnums,sizeof(int),sizeof(intnums)/sizeof(int), intCmp, 0);
				int max = *pMax;
				printf("getMax=%d\n",max);*/

				// 测试2:结构体类型求最大值
				/*struct studCources scDatas[]= {{"se17","DSA",90}, {"se15","SE",99},{"se17","c",80}}, *cc;
				cc=(struct studCources*)getMax(scDatas,sizeof(struct studCources),sizeof(scDatas)/sizeof(struct studCources), studCourcesCmp, 1);
				printf("getMax=%.lf\n",cc->grade);
				cc=(struct studCources*)getMax(scDatas,sizeof(struct studCources),sizeof(scDatas)/sizeof(struct studCources), studCourcesCmp, 0);
				printf("getMax=%s\n",cc->studNo);*/

				//测试3:float类型求最大值 3使用库函数getMax
				/*float floatnums[] = {3.14, 1.23, 5.20, 8.8, 2.17, 6.1888, 99, 2.56, 4.4};
				float *pfMax = (float *)getMax(floatnums,sizeof(float),sizeof(floatnums)/sizeof(float), floatCmp, 0);//4使用用户定义的比较函数floatCmp
				float fmax = *pfMax;
				printf("getMax=%.4lf\n",fmax);
				
				qsort(floatnums,sizeof(floatnums)/sizeof(float),sizeof(float),qsortfCmp);
				for(int i=0; i<sizeof(floatnums)/sizeof(float);i++)
					printf("%.4lf ", floatnums[i]);*/
					
				// 测试4:生成int类型数据
				#define N 5
				int intnums[N]={0}, intnums1[N]={0};
				int b=10,e=100;
				
				DSADataGenerator(intnums, sizeof(int), N, &b, &e, intGen, 0);
				for(int i=0;i<N;i++)
					printf("%d ", intnums[i]);				
				int *pMax = (int *)getMax(intnums,sizeof(int),sizeof(intnums)/sizeof(int), intCmp, 0);
				int max = *pMax;
				printf("getMax=%d\n",max);
					
				DSADataGenerator(intnums1, sizeof(int), N, &b, &e, intGen, 1);
				for(int i=0;i<N;i++)
					printf("%d ", intnums1[i]);
				pMax = (int *)getMax(intnums1,sizeof(int),sizeof(intnums1)/sizeof(int), intCmp, 0);
				max = *pMax;pMax=0;
				printf("getMax=%d\n",max);
				
				// 测试5:生成studCources类型数据
				struct studCources be[]= {{"SN001","CN001",00}, {"SN100","CN100",99}};
				struct studCources SCs[N]={0};
				DSADataGenerator(SCs, sizeof(struct studCources), N, be, be+1, studCourcesGen, 0);
				printf("%10s %20s %8.0lf\n", be[0].studNo, be[0].cources, be[0].grade);	
				for(int i=0;i<N;i++)
					printf("%10s %20s %8.0lf\n", SCs[i].studNo, SCs[i].cources, SCs[i].grade);	
				printf("%10s %20s %8.0lf\n", be[1].studNo, be[1].cources, be[1].grade);				
				struct studCources *sc = (struct studCources *)getMax(SCs,sizeof(struct studCources),sizeof(SCs)/sizeof(struct studCources), studCourcesCmp, 0);
				printf("getMax=%s\n",sc->studNo);

			} else if(input == 'q') {
				break;
			} else if(input != '\n') {
				printf("未知命令 '%c'! 忽略...\n",input);
			}
		} else {
			printf("非法输入! 忽略...\n");
		}
	}

	return 0;
}


/*

*/ 
