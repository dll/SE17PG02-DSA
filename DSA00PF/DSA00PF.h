
/*
�����������нϴ���
�������Ͳ��� 
1������һ������ 
*/ 
int myMax(int a, int b);

/*
1,��װGithub Extensions
2���������ش���ֿ�
3����Dev-C++����Ŀ�ύ�����زֿ� 
4�������زֿ��ύ��Զ�ֿ̲⣺https://github.com/dll/SE17PG02-DSA.git 
5������ https://github.com/ SE17PG02-DSA-master.zip
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
C���������������Ļ��棬��Ҫ������C++��cin/cout�Դ˸Ľ��� 

fflush(stdin)
*/

struct studCources {
	char studNo[10] ;
	char cources[20] ;
	double grade; 
}; 

/*
�Ƚ� struct studCources�Ĵ�С������flagΪ0ʱ������ѧ�Žϴ��ߣ�flagΪ1ʱ�����سɼ��ϸ��� 
����flag����0/1�����ؿյĽṹ�� 
*/
struct studCources myMax2(struct studCources a, struct studCources b, int flag);

/**
myMax3�����������������͵������е������ 
����void*��voidָ�����͵ĺ���������a,b�������
������
a,b����void*���ͣ��뺯������ֵ������ͬ
s��a,b��ͬ���͵��ڴ��С��int4,double8,char1,studCources40(Ϊʲô����38�ֽڣ��ṹ���Ա���룩 
f�Ǳ�־���������Ϊ������С����󣻰��սṹ�岻ͬ��Ա��������ߵ� 
*/ 
void *myMax3(void *a, void *b, int s, int f); 


typedef int (*compareFunc)(void *a,void *b,int flag);
void *myMax4(void *a, int s, int length, compareFunc func, int flag);
int intCmp(void *a,void *b, int flag);
int studCourcesCmp(void *a, void *b, int flag);
