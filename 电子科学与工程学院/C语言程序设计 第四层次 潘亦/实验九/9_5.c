#include<iostream>
#include<cstdlib>
int *count(char *ch_p)
{
	//����ֲ���̬������Ԫ����ĸ���м���
	static int count = 0;
	//���ַ�ת��Ϊ�����
	if ('A' <= *ch_p&&*ch_p <='Z') printf("%c", *ch_p - 'A' + 'a');
	else printf("%c", *ch_p);
	//���ַ�ΪԪ�����ۼ�
	if (*ch_p == 'a' || *ch_p == 'e' || *ch_p == 'i' || *ch_p == 'u' || *ch_p == 'o' || *ch_p == 'A' ||*ch_p == 'E' || *ch_p == 'O' || *ch_p == 'I' || *ch_p == 'U')
	{
		count++;
	}
	return &count;
}
int main()
{
	char ch; int *Count=0;
	while ((ch = getchar()) != '\n')
	{
		Count=count(&ch);
	}
	printf(": %d", *Count);
	system("pause");
	return 0;
}