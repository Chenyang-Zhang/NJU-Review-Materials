#include<iostream>
using namespace std;
int x = 5, Num, m = 4;//x������������Σ���NumΪ��������mΪ���ʣ�µ�������
int CountPeach(int);
int main()
{
	cout << CountPeach(4) << endl;
	system("pause");
	return 0;
}
int CountPeach(int Num)//���庯��������Ӹ���
{
	if (Num % 4 == 0 && x > 0)//������Ա������������
	{
		x--;
		return CountPeach((Num / 4) * 5 + 1);
	}
	else if (Num % 4 != 0 && x > 0)//�����;���������ɱ������������¿�ʼ
	{
		x = 5;
		m++;
		return CountPeach(m);
	}
	else return Num;  //�������������������򷵻�������
}