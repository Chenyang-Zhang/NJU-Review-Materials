#include<stdio.h>
#include<cstdlib>
using namespace std;
int main()
{
	int a,b,c;
	printf("������һ��������ĳ����:");
	scanf_s("%d%d%d", &a, &b, &c);
	printf("�������������Ϊ:%d", a*b*c);
	system("pause");
	return 0;

}