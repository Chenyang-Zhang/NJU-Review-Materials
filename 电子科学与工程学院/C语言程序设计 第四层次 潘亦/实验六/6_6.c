#include<iostream>
#include<math.h>
using namespace std;
double F(double);							//�����������ú���F��x��
int main()
{
	int x;
	double a=1;
	cout << "1.���η�" << endl;
	cout << "2.���η�" << endl;
	cout << "3.�˳�" << endl;
	cout << "����������ִ��ѡ��ǰ�����:";
	cin >> x;								//ȷ��ִ��ѡ��
	double h,sum = 0;
	if (x == 1)                            //n=1��ִ�����η�
	{
		cout << "��ȷ��΢�ֶ�n:";
		double n; cin >> n;
		h = 2 / n;
		for (int i = 1; i <= n - 1; i++)
		{
			a += h;
			sum +=F(a);
		}
		cout << (2 / n)*((F(1) + F(3)) / 2 + sum);
	}
	else if (x == 2)						//n=2��ִ�о��η�
	{
		cout << "��ȷ��΢�ֶ�n:";
		double n; cin >> n;
		h = 2 / n;
		for (int i = 1; i <= n - 1; i++)
		{
			a += h;
			sum += F(a);
		}
		cout << (2 / n)*(sum);
	}
	else if (x == 3)						//����Ϊ3����main����
	{
		return 0;
	}
	else
	{
		cout << "Type Error" << endl;
	}
	system("pause");
	return 0;
}
double F(double x)							//���庯��F��x��
{
	return exp(3 * x) + pow(x, 7);
}