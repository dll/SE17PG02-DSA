#include <stdio.h>
#include"DSA00PF.h"

/*
void Foo() {
	printf("Hello World!\n");
}*/


int main(int argc, char** argv) {
	char input = 0;

	int x, y;

	printf("Hello! This is a console application.\n");
	printf("Press q to quit, press a to execute myMax.\n");
	while(1) {
		if(scanf("%c",&input) == 1) {
			if(input == 'a') {
			/*	printf("Please input two integer numbers:\n");
				scanf("%d%d", &x, &y);
				printf("max=%d", myMax(x,y));3??????myMax??????????????????????е?????*/

			/*	printf("\nmax0=%.2lf",myMax0(x,y));

				fflush(stdin);
				char a,b;
				scanf("%c%c", &a, &b);
				printf("\nmax1=%c",myMax1(a,b));
				fflush(stdin);*/
				
				/*printf("Please input two students and cources grades:\n"); 
				struct studCources a, b, c;
				int flag;
				scanf("%s %s %lf", a.studNo, a.cources, &a.grade);
				scanf("%s %s %lf", b.studNo, b.cources, &b.grade);
				scanf("%d", &flag);
				c=myMax2(a,b,flag);
				printf("%s %s %.1lf", c.studNo, c.cources, c.grade);*/
				
				/*int x=1,y=2;
				printf("max=%d\n",*((int*)myMax3(&x, &y, sizeof(int), 0))); 
				
				double m=2.22, n=3.33;
				printf("max=%.1lf\n",*((double*)myMax3(&m, &n, sizeof(double), 0)));  

				char p='a', q='b';
				printf("max=%c\n",*((char*)myMax3(&p, &q, sizeof(char), 0)));  
				
				struct studCources aa={"se17","DSA",90}, bb={"se15","SE",99}, *cc;
				cc=((struct studCources*)myMax3(&aa, &bb, sizeof(struct studCources), 0));
				printf("max=%s\n",cc->studNo);  
				cc=((struct studCources*)myMax3(&aa, &bb, sizeof(struct studCources), 1));
				printf("max=%lf\n",cc->grade); */
				
				// test1:int类型求最大值
				int intnums[] = { 3, 1, 5, 8, 7, 6, 9, 2, 4 };
				int *pMax = (int *)myMax4(intnums,sizeof(int),sizeof(intnums)/sizeof(int), intCmp, 0);
    			int max = *pMax;
    			printf("myMax4=%d\n",max);
				 
				// test2:结构体类型求最大值
				struct studCources scDatas[]={{"se17","DSA",90}, {"se15","SE",99},{"se17","c",80}}, *cc;
				cc=(struct studCources*)myMax4(scDatas,sizeof(struct studCources),sizeof(scDatas)/sizeof(struct studCources), studCourcesCmp, 1);
				printf("max=%.lf\n",cc->grade);  
				cc=(struct studCources*)myMax4(scDatas,sizeof(struct studCources),sizeof(scDatas)/sizeof(struct studCources), studCourcesCmp, 0);
				printf("max=%s\n",cc->studNo); 
				
				/*Foo();*/
			} else if(input == 'q') {
				break;
			} else if(input != '\n') {
				printf("Unknown command '%c'! Ignoring...\n",input);
			}
		} else {
			printf("Invalid input! Ignoring...\n");
		}
	}

	return 0;
}

