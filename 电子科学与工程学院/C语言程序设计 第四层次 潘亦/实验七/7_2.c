#include<stdio.h>
#include<cmath>
using namespace std;
int prime(int);										//����ȷ�������ĺ���
int main()
{
	int m, n;
	int count = 0;
	scanf_s("%d%d", &m, &n);
	for (; m <= n - 2; m++)										//��m��ʼ������nѰ������
	{
		if (prime(m) == 1)										//�����������ȷ����Ӷ����Ƿ�Ϊ����
		{
			if (prime(m + 2) == 1)
			{
				printf("(%d,%d)\n", m, m + 2);					//�Ӷ���ҲΪ���������
				++count;										//��¼�������Ķ���  
			}
		}
		else
			if (m == (n - 2) && count == 0) 
				printf("��������û��������\n");					//������m-2ʱ��δ�ҵ������������û����������
			else if ((m == (n - 2)) && count != 0)
				printf("�������ڵ���������%d��\n", count);
	}
	system("pause");
	return 0;
}
int prime(int n)												//���庯���жϺ����������Ƿ�Ϊ����
{
	int i = 2;
	for (; i < sqrt(n); i++)
	{
		if (n%i == 0) return 0;									//��������������0
	}
	if (i >= sqrt(n)) return 1;									//������������1
}