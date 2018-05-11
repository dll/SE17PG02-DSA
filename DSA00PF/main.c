#include <stdio.h>
#include <stdlib.h> 
#include"DSAFunLib.h"
#include"DSA00PF.h"


int main(int argc, char** argv) {
	char input = 0;

	int x, y;

	printf("Hi! 这是我们的DSA函数库测试程序.\n");
	printf("请按q 键退出, a 键执行getMax函数\n");
	while(1) {
		if(scanf("%c",&input) == 1) {
			if(input == 'a') {
				// 测试1:int类型求最大值
				int intnums[] = { 3, 1, 5, 8, 7, 6, 9, 2, 4 };
				int *pMax = (int *)getMax(intnums,sizeof(int),sizeof(intnums)/sizeof(int), intCmp, 0);
				int max = *pMax;
				printf("getMax=%d\n",max);

				// 测试2:结构体类型求最大值
				struct studCources scDatas[]= {{"se17","DSA",90}, {"se15","SE",99},{"se17","c",80}}, *cc;
				cc=(struct studCources*)getMax(scDatas,sizeof(struct studCources),sizeof(scDatas)/sizeof(struct studCources), studCourcesCmp, 1);
				printf("getMax=%.lf\n",cc->grade);
				cc=(struct studCources*)getMax(scDatas,sizeof(struct studCources),sizeof(scDatas)/sizeof(struct studCources), studCourcesCmp, 0);
				printf("getMax=%s\n",cc->studNo);

				//测试3:float类型求最大值 3使用库函数getMax
				float floatnums[] = {3.14, 1.23, 5.20, 8.8, 2.17, 6.1888, 99, 2.56, 4.4};
				float *pfMax = (float *)getMax(floatnums,sizeof(float),sizeof(floatnums)/sizeof(float), floatCmp, 0);//4使用用户定义的比较函数floatCmp
				float fmax = *pfMax;
				printf("getMax=%.4lf\n",fmax);
				
				qsort(floatnums,sizeof(floatnums)/sizeof(float),sizeof(float),qsortfCmp);
				for(int i=0; i<sizeof(floatnums)/sizeof(float);i++)
					printf("%.4lf ", floatnums[i]);

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
Hi! 这是我们的DSA函数库测试程序.
请按q 键退出, a 键执行getMax函数
a
getMax=9
getMax=99
getMax=se17
getMax=99.0000
1.2300 2.1700 2.5600 3.1400 4.4000 5.2000 6.1888 8.8000 99.0000

*/ 
