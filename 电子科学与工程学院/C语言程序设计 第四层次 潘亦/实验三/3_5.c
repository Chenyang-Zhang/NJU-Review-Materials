#include<cstdio>
#include<cmath>
#include<cstdlib>
int main()
{
	double x, y;A
	scanf_s("%lf%lf", &x, &y);
	printf("sin(x)=%lf\ncos(x)=%lf\nx�ľ���ֵ=%lf\ne^x=%lf\nx^y=%lf",
		sin(x), cos(x), abs(x), exp(x), pow(x, y));
	system("pause");
	return 0;
}