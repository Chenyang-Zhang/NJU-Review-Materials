#include<iostream>
#include<cmath>
using namespace std; 
int s = 0;
int countvalue(int aa[])
{
	int count = 0;
	//��301��ʼ���εݼӼ������(ż������)
	for (int i = 501; i <= 800; i+=2)
	{
		int m = 2;
		for (; m <= i; m++)
		{
			if (i%m == 0) break;
		}
		if (m==i)
		{
			//�������������ֵ������aa
			aa[s++] = i;
			count++;
		}
	}
	return count;
}
int main()
{
	int Pri[200];
	//�����������
	int count = countvalue(Pri);
	//���δ�ӡ����������
	for (int i = 0; i <= s-1; i++)
	{
		cout << Pri[i]<<"  ";
		if (i % 10 == 9) cout << endl;
	}
	cout << "��" << count << "������" << endl;
	system("pause");
	return 0;
}