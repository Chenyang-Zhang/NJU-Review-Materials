#include<iostream>
using namespace std;
//������һ�����������۰���ҷ����Ҹ����Ƿ�������{5,23,28,34,43,45,56,60,67,90}�ڣ�����ڣ�������±꣬���������not found����
int main()
{
	int n[10] = { 5,23,28,34,43,45,56,60,67,90 };
	cout << "������һ������:";
	int x;
	cin >> x;
	int a = 0, b = 9;
	while (n[a] != x&&n[b] != x)
	{
		int m = (a + b) / 2;
		if (n[m] == x) { a = m; break; }
		else if (n[m] > x) b = m;
		else a = m;
		if (abs(a - b) == 1) break;
	}
	if (n[a] == x) cout << a;
	else if (n[b] == x) cout << b;
	else cout << "not found";
	system("pause");
	return 0;
}