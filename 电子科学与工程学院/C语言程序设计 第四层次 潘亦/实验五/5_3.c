#include<cstdlib>
#include<cstdio>
int Pri_Right(int a);
int main()
{
	for (int n = 2;; n++)
	{
		int m = n*n + n + 41;
		if (Pri_Right(m) == 1) printf("%d\n", m);
		else
		{
			printf("%d�����������ù�ʽ������", m);
			system("pause");
		}
	}
	return 0;
}
int Pri_Right(int a)
{
	int i = 2;
	for (; i <= a; i++)
	{
		if (a%i == 0) break;
	}
	if (i == a) return 1;
	else return -1;
}