#include<iostream>
using namespace std;
//����һ���������ڰѴ�д��ĸת��ΪСд��ĸ
char Letter_Change(char a)
{
	a = a + 32;
	return a;
}
//����һ����������Ѱ��������ĳ�ַ����ֵĴ���
void Letter_Count(char a[],char m,int Len)
{
	int count = 0;
	for (int n = 0; n <= Len-1; n++)
	{
		if (a[n] >= 'A'&&a[n] <= 'Z') 
			a[n] = Letter_Change(a[n]);
		if (a[n] == m) 
			count++;
	}
	if(count!=0) cout << m << ":" << count<<" ";
}
int main()
{
	char a[30] ;
	gets_s(a);
	//����ĸa��zѰ������a
	for (char x = 97; x <= 122; x++)
		Letter_Count(a, x,30);
	system("pause");
	return 0;
}