#include<iostream>
#include<cstdio>
using namespace std;
//���庯��CountDigit()���������м���
int CountDigit(int n)				   
{
	int m = 0;
	while (n != 0)
	{
		n /= 10;
		++m;
	}
	return m;
}
//���庯���ж��Ƿ�Ϊ��������
int f(int n)
{
	int a, b, c;
	if (CountDigit(n) == 3)
	{
		a = n / 100;
		b = n / 10 % 10;
		c = n % 10;
		if (a*a + b*b == c*c&&a!=0&&b!=0&&c!=0)
			return 1;
		else return 0;
	}
	else if (CountDigit(n) == 4)
	{
		a = n / 1000;
		b = n / 100 % 10;
		c = n - 1000 * a - 100 * b;
		if (a*a + b*b == c*c&&a != 0 && b != 0 && c != 0)
			return 1;
		else return 0;
	}
}
//����main������Ϊ����
int main()
{
	int m, n;
	cout << "������m��n��ֵ:";
	M: cin >> m >> n;
	if ((m <= 100 || m >= 10000) || (n <= 100 || n >= 10000) || m >= n)
	{
		cout << "�����������������:";
		goto M;
	}
	for (; m <= n; m++)
	{
		if (f(m) == 1)
		{
			if (CountDigit(m) == 3)
				printf("%d:%d*%d+%d*%d=%d*%d\n", m, m / 100, m / 100, m / 10 % 10, m / 10 % 10, m % 10, m % 10);
			else 
				printf("%d:%d*%d+%d*%d=%d*%d\n", m, m / 1000, m / 1000, m / 100 % 10, m / 100 % 10, m-m/100*100, m - m / 100*100);
		}
	}
	system("pause");
	return 0;
}