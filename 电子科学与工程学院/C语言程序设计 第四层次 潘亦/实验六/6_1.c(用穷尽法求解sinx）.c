#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double x, a = 1;
	cout << "������x=";
	cin >> x;
	double s = x / 1;
	long long m;
	int count = 1, n;
	for (int i = 3; fabs(a) >= pow(10, -8); i+=2)			//��3��ʼ��������׳�
	{
		for(m = 1, n = 1; n <= i; n++)						//����i�Ľ׳�
			m *= n;
		++count;											//���ۼ�ʽ���м�����ȷ������
		a = pow(x, i) / m; 
		if (count % 2 == 0) s -= a;
		else s += a;
	}
	cout <<"sinx="<<fixed<<setprecision(1)<<s;
	system("pause");
	return 0;
}