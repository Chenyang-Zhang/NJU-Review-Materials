#include<iostream>
using namespace std;
//����һ������ȷ��������ʮ�������еı�ʾ
void ShiEr(int m)
{
	switch (m)
	{
	case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:cout << m; break;
	case 10:cout << "A"; break;
	case 11:cout << "B"; break;
	case 12:cout << "C"; break;
	}
}
int main()
{
	int n, Yushu[20], i = 0;
	//����һ��ʮ��������
	cin >> n;
	//����������
	do {
		Yushu[i] = n %12;
		i++;
		n = n / 12;
	} while (n / 12 != 0);
	//���ʮ���������ĵ�һλ
	ShiEr(n);
	for (int m = i - 1; m >= 0; m--)
	{
		//���ε�����������е�Ԫ��
		ShiEr(Yushu[m]);
	}
	system("pause");
	return 0;
}