#include<iostream>
#include<math.h>
using namespace std;
double Fun(double );								//��������Fun��x��
int main()
{                                                        
	double a, b, mid;
	a = 0, b = 3;
	while (fabs(Fun(a)) >1e-6 && fabs(Fun(b)) >1e-6)				//���˵�ֵ��Ϊ����ֵʱִ��ѭ��
	{
		mid = (a*Fun(b)-b*Fun(a))/(Fun(b)-Fun(a));
		while (Fun(mid) == 0)						//���ص�Ϊ����ֵʱ����ѭ��
		{
			cout << mid << endl;
			break;				
		}
		if (Fun(mid) > 0) b = mid;					//���ص㲻Ϊ����ֵʱ��Ϊ�˵�ֵ
		else a = mid;
	}
	if (fabs(Fun(a))<=1e-6) cout << a;
	else cout << b;
	system("pause");
	return 0;
}
double Fun(double x)								//���庯����F��x��
{
	return 2 * x*x*x - 4 * x*x + 3 * x - 6;
}