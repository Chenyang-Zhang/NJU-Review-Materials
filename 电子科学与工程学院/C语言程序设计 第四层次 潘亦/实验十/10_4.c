#include<iostream>
using namespace std;
//���庯����bruter-force�㷨��������������Լ��
int Gcd(int a, int b)
{
	int z = a < b ? a : b;
	while ((a%z != 0) || (b%z != 0))
		z--;
	return z;
}
//���庯�����ʣ��Ԫ�ص����Լ��
int  Del_findgcd(int a[], int n, int *f)
{
	int m = 1;
	//ȥ�������е������±�Ԫ�ز���ż���±�Ԫ��ǰ��
	for (int i = 2; i <= n - 1; i+=2)
	{
		a[m++] = a[i];
	}
	//���μ���������������Լ��
	int GCD = Gcd(a[0], a[1]);
	for (int i = 2; i <= m - 1; i ++)
	{
		GCD = Gcd(GCD, a[i]);
	}
	*f = GCD;
	//����Ԫ���е�ʣ��Ԫ�ظ���
	return m;
}
int main()
{
	int a[10] = { 6,  8,  9,   11,  12,  13,  15,  16,  18 , 19 };
	int n = 10; int f; 
	int number = Del_findgcd(a, n, &f);
	//���δ�ӡ�������е�ʣ��Ԫ��
	for (int i = 0; i <= number - 1; i++)
		cout << a[i]<<" ";
	cout << ", " << "max common divisor is:" << f;
	system("pause");
	return 0;
}

