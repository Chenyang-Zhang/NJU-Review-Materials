#include<iostream>
#include<cstdlib>
using namespace std;
int find(int);
int main()
{
	for (int i = 1000; i <= 9999; i++)//�ӵ�һ����λ��1000���������һ��
	{
		int m = find(i);
		if (m != 0) cout <<i<<" "<<m;
	}
	system("pause");
	return 0;
}
int find(int n)//���庯��findȷ�����Ƿ�ΪĿ����
{
	int a, b, c, d;
	a = n / 1000;
	b = n / 100 % 10;
	c = n / 10 % 10;
	d = n % 10;
	int m = (1000 * d + 100 * c + 10 * b + a);
	if (m== 9 * n)
		return m;
	else return 0;
}