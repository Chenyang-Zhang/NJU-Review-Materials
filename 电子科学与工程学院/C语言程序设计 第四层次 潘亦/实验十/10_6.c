#include<iostream>
using namespace std;
//���庯���ж�����
int isPrime(int num)
{
	int tmp = num - 1;
	for (int i = 2; i <= tmp; i++)
		if (num %i == 0)
			return 0;
	return 1;
}
int mpsort(int x[],int n)
{
	int Maxa, Last_Prime;
	//�������е�һ������ʼѰ��ż��
	for (int i = 0; i <= n - 1; i++)
		if (x[i] % 2 == 0) { Maxa = i; break; }
	//�������е�һ��ż����ʼѰ�����ż��
	for (int a = Maxa+1; a <= n - 1; a++)
	{
		if (x[a] % 2 == 0)
			if (x[a] > x[Maxa])
				Maxa = a;
	}
	//���������һ��Ԫ�ؿ�ʼѰ�����һ������
	for(int b=n-1;b>=0;b--)
		if (isPrime(x[b]) == 1)
		{
			Last_Prime = b;
			break;
		}
	//����ʹ��Ч�ʽϸߵĲ��뷨��������
	int t, j;
	for (int i = Maxa + 1; i <= Last_Prime; i++)
	{
		t = x[i];
		for( j = i - 1; t<x[j] && j >= Maxa; j--)
			x[j + 1] = x[j];
		x[j + 1] = t;
	}
	//������Ҫ�����Ԫ�ظ���
	return abs(Last_Prime - Maxa) + 1;
}
int main()
{
	int x[10], t;
	//�Ӽ�����������������Ԫ��
	for (int i = 0; i <= 9; i++)
		cin >> x[i];
	t = mpsort(x, 10);
	//���δ�ӡ������Ԫ��
	for (int i = 0; i <= 9; i++)
		cout << x[i] << " ";
	cout << "t=" << t << endl;
	system("pause");
	return 0;
}
