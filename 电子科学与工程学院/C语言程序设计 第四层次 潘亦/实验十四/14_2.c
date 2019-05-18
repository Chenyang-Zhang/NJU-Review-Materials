#include<iostream>
using namespace std;
#define M 5
#define N 6
//����һ����������
struct  data_array
{
	long num;
	int score;
};
//����һ����Ϣ����
typedef  struct student
{
	long num;
	int score;
	struct student *next;
} NODE;
//ͷ���뷨
void headinsert(NODE *head, NODE *p0)
{
	p0->next = head->next;
	head->next = p0;
}
//β���뷨
void tailinsert(NODE *p,NODE *q)
{
	q->next = p->next;
	p->next = q;
	p = q;
}
//����һ������������һ���������е�����
NODE * create(struct  data_array *array, int n)
{
	//�Ƚ�array�е����ݽ�����������
	struct data_array P;
	 for(int i=0;i<n;i++)
		 for(int m=0;m<n-i-1;m++)
			 if (array[m].num > array[m + 1].num)
			 {
				 P = array[m];
				 array[m] = array[m + 1];
				 array[m + 1] = P;
			 }
	 //����ͷ(��)ָ��;
	NODE *head;
	NODE *p;
	p = (NODE *)malloc(sizeof(NODE));
	p->next = NULL;
	head = p;
	//��array�е����ݽ���������
	while (n > 0)
	{
		p = (NODE *)malloc(sizeof(NODE));
		p->num = array[--n].num;
		p->score = array[n].score;
		headinsert(head, p);
	}
	return head;
}
//���������δ�ӡ����
void  display(NODE *head)
{
	NODE *p = head;
	while(p->next!=NULL)
	{
		p = p->next;
		cout << p->num << "     " <<p->score << endl;
	}
}
//����ĸ��Ʋ���
void   copy_list(NODE *head1, NODE **head2)
{
	NODE *h_ead;
	NODE *_p;
	NODE *_q;
	_q = (NODE *)malloc(sizeof(NODE));
	_q->next = NULL;
	h_ead = _q;
	while (head1->next != NULL)
	{
		_p = (NODE *)malloc(sizeof(NODE));
		_p->num =head1->next->num;
		_p->score= head1->next->score;
		tailinsert(_q, _p);
		_q = _p;
		head1 = head1->next;
	}
	*head2 = h_ead;
}
//����������ϲ�
NODE * merge(NODE *head1, NODE *head2)
{
	head1 = head1->next;
	head2 = head2->next;
	NODE *head;
	NODE *p;
	NODE *q;
	p = new NODE;
	p->next = NULL;
	head = p;
	while (head1!= NULL&&head2 != NULL)
	{
		q = new NODE;
		if (head1->num == head2->num)
		{
			NODE *middle = head1->score > head2->score ? head1 : head2;
			q->num = middle->num;
			q->score = middle->score;
			tailinsert(p, q);
			p = q;
			head1 = head1->next;
			head2 = head2->next;
		}
		else if (head1->num > head2->num)
		{
			q->num = head2->num;
			q->score = head2->score;
			tailinsert(p, q);
			p = q;
			head2 = head2->next;
		}
		else if (head2->num > head1->num)
		{
			q->num = head1->num;
			q->score = head1->score;
			tailinsert(p, q);
			p = q;
			head1 = head1->next;
		}
	}
	while (head1 != NULL)
	{
		q = new NODE;
		q->num = head1->num;
		q->score = head1->score;
		tailinsert(p, q);
		p = q;
		head1 = head1->next;
	}
	while (head2 != NULL)
	{
		q = new NODE;
		q->num = head2->num;
		q->score = head2->score;
		tailinsert(p, q);
		p = q;
		head2 = head2->next;
	}
	return head;
}
//����ͬԪ��ɾ��
NODE * del(NODE *head1, NODE *head2)
{
	//�ȷֱ��ס��һ���ڵ�
	NODE *Head1 = head1;
	NODE *Rem1 = head1;
	NODE *Rem2 = head2;
	head2 = head2->next;
	while (	Rem1->next != NULL)
	{
		Head1 = Rem1;
		Rem1 = Rem1->next;
		while (head2 != NULL)
		{
			if (Rem1->num == head2->num)
			{
				Head1->next = Rem1->next;
				free(Rem1);
				Rem1 = Head1;
			}
			head2 = head2->next;
		}
		head2 = Rem2->next;
	}
	return head1;
}
int main()
{
	struct  data_array data_a[M] = { { 20304,75 },{ 20311,89 },{ 20303,62 },{ 20307,87 },{ 20320,79} };
	struct data_array data_b[N] = { { 20302,65 },{ 20301,99 },{ 20311,87 },{ 20323,88 },{ 20307,92 },{ 20322,83 } };
	NODE *head_a=create(data_a, M);//����a����
	cout <<endl<< "a:" << endl;
	display(head_a);
	NODE *head_b = create(data_b, N);//����b����
	cout << "b:" << endl;
	display( head_b);
	NODE **A_dup= &head_a;
	NODE **B_dup = &head_b;
	copy_list(head_a, A_dup);//����a����
	copy_list(head_b, B_dup);
	NODE *a_dup = *A_dup;
	NODE *b_dup = *B_dup;
	NODE *Merge=merge(head_a, head_b);//�ϲ�a��b����
	cout << endl << "merge a&b:" << endl;
	display(Merge);
	cout << endl << "b_dup:" << endl;
	display(del(b_dup, a_dup));
	system("pause");
	return 0;
}