//..4����Ҫ���д����
//...�� ��д����void  line_sort(int a[][4], int b[], int n)��nΪ����������aָ������飬
//...�������Ԫ��֮��, �����浽bָ��������У����ݺ͵Ĵ�С��aָ���
//...��������Ϊ��λ����С�����˳���������С�
//...�� ��дmain��������ʼ����ά���飬���ԭʼ���飬
//...������line_sort�����õ��仯�Ժ�����鼰ÿ��֮�ͣ��������
//...��ĸ���Ԫ���Լ�ÿ��Ԫ�صĺ͡�
#include<cstdio>
#include<cstdlib>
void print(int a[][4], int m, int n);
void line_sort(int a[][4], int b[], int n)
{
	int B_number = 0;
	//�ȶ�������з�����Ͳ�����������b��
	for (int x = 0; x < n; x++)
	{
		int count = 0;
		for (int m = 0; m < 4; m++)
			count += a[x][m];
		b[B_number++] = count;
	}
	//����ѡ�����򷨶������������
	for (int i = 0; i < n-1; i++)
	{
		int point = i;
		for (int j = i + 1; j < n; j++)
			if (b[point] > b[j]) point = j;
		if (b[point] != b[i])
		{
			int t = b[i];
			b[i] = b[point];
			b[point] = t;
		}
		//ͬʱ���������[�н���]
		for (int m = 0; i != point&&m < n-1; m++)
		{
			int h = a[i][m];
			a[i][m] = a[point][m];
			a[point][m] = h;
		}
	}
}
//����һ��������������е�Ԫ��
void print(int a[][4],int m,int n)
{
	for (int p = 0; p < m; p++)
	{
		for (int q = 0; q < n; q++)
			printf("%5d", a[p][q]);
		printf("\n");
	}
}
int main()
{
	int a[][4] = { 1,4,5,7,3,5,7,8,9,10,2,3,1,3,4,2,1,2,1,1 };
	int b[10];
	print(a, 5, 4);
	printf("\n");
	line_sort(a, b, 5);
	print(a, 5, 4);
	printf("ÿ��Ԫ��֮�ͷֱ�Ϊ:%d %d %d %d %d\n", b[0], b[1], b[2], b[3], b[4]);
	system("pause");
	return 0;
}
