

//���ݽṹ�γ�ʵ��һ



#include<cstdio>
#include<cstdlib>
#define ElemType int
#define print printf
#define MAX_NUMBER 100
#define Position_Insert 101
#define Data_Insert 101
#define Delete_Position 100



typedef struct LNode{ 
	//�������ṹ
	ElemType data;
	LNode *next;
}*Node;

typedef struct {
	//��������ṹ
	Node head, tail; //�ֱ�ָ�����������е�ͷ�������һ�����
	int len;
}Linklist;

Linklist *InitList() {
	//����һ���յ���������
	Linklist *Linklist1 = (Linklist *)malloc (sizeof(Linklist));
	Linklist1->head = (Node)malloc(sizeof(Node));
	Linklist1->tail= (Node)malloc(sizeof(Node));
	Linklist1->head->next = NULL;
	Linklist1->tail->next = NULL;
	Linklist1->len = 0;
	return Linklist1;
}

Linklist *Init_LinkList(int Len) {
	//��������������
	Linklist *Linklist1 = InitList();
	while (Len > 0)
	{
		Node p = (Node)malloc(sizeof(Node));
		if (!p) exit(1);
		p->data = Len;
		p->next = Linklist1->head->next;
		Linklist1->head->next = p;
		if(Len == MAX_NUMBER) Linklist1->tail = p;
		Linklist1->len++, Len--;
		printf("Element %d ��������\n", p->data);
	}
	return Linklist1;
}

void insert(Linklist *L, int i, ElemType e){
	//�ڴ�ͷ���ĵ������е�i��Ԫ��֮ǰ����Ԫ��
	Node Move = (Node)malloc(sizeof(Node));
	Move = L->head->next;
	//Ѱ������Ĳ���ڵ�ǰ��
	for (int Middle = 1; Middle < i-1; Middle++)
		Move = Move->next;
	//����ڵ�
	Node Insert = (Node)malloc(sizeof(Node));
	Insert->data = e;
	Insert->next = Move->next;
	Move->next = Insert;
}

void Delete(Linklist *L, int i, ElemType &e) {
	//ɾ�������е�i��Ԫ��
	Node Move = (Node)malloc(sizeof(Node));
	Move = L->head->next;
	//Ѱ������Ĳ���ڵ�ǰ��
	for (int Middle = 1; Middle < i - 1; Middle++)
		Move = Move->next;
	Node Be_Delete = (Node)malloc(sizeof(Node));
	Be_Delete = Move->next;
	e = Be_Delete->data;
	Move->next = Move->next->next;
}

void Print_LinkList(Linklist *Linklist1){
	//���������ӡ����
	int i = 1;
	if (Linklist1->len == 0) {
		printf("������\n");
		return;
	}
	Node Move = (Node)malloc(sizeof(Node));
	Move = Linklist1->head->next;
	while (Move != NULL){
		printf("Linklist �� %d ������: %d\n", i++, Move->data);
		Move = Move->next;
	}
}
/*
int main()
{

	//����һ���洢 1~100 ����������
	printf("����һ���洢 1~100 ����������\n");
	Linklist *LinkList = Init_LinkList(MAX_NUMBER);

	//��ӡ��������
	printf("\n\n��ӡ��������\n");
	Print_LinkList(LinkList);

	//�����101�����
	printf("\n\n�����101������\n");
	insert(LinkList, Position_Insert, Data_Insert);
	Print_LinkList(LinkList);

	//ɾ����100�����
	printf("\n\nɾ����100������\n");
	int Delete_Data;
	Delete(LinkList, Delete_Position, Delete_Data);
	Print_LinkList(LinkList);


	//�ҵ���������Ĺ������
	Linklist *Linklist1 = Init_LinkList(MAX_NUMBER);
	Linklist *Linklist2 = Init_LinkList(10);
	Linklist2->head->next->next = Linklist1->head->next->next->next;
	Linklist2->tail = Linklist1->tail;
	Node FindFirstCommonNode(Linklist *Link1, Linklist *Link2);
	Node Common = FindFirstCommonNode(Linklist1, Linklist2);

	printf("\n\n����1:\n");
	Print_LinkList(Linklist1);

	printf("\n\n����2:\n");
	Print_LinkList(Linklist2);

	printf("\n\n��������Ԫ��Ϊ:%d\n", Common->data);

	//������2ת��
	printf("\n\n������2ת��:\n");
	void Reverse_LinkList(Linklist *Linklist);
	Reverse_LinkList(Linklist2);
	Print_LinkList(Linklist2);

	system("pause");
	return 0;

}
*/

Node FindFirstCommonNode(Linklist *Link1, Linklist *Link2) {
	//��������ͷ���ĵ�������ཻ�ĵ�һ�����
	int flag = 0;
	if (Link1->tail != Link2->tail) {
		printf("û�й������");
		exit(1);
	}
	Node Link1_Move = (Node)malloc(sizeof(Node));
	Link1_Move = Link1->head;
	while(Link1_Move != NULL){
		//������һ������
		Node Link2_Move = (Node)malloc(sizeof(Node));
		Link2_Move = Link2->head;
		for (; Link2_Move != NULL; Link2_Move = Link2_Move->next) 
		{
			if (Link2_Move == Link1_Move)
			{
				flag = 1;
				break;
			}
		}
		if (flag) break;
		Link1_Move = Link1_Move->next;
	}
	return Link1_Move;
}



void Reverse_LinkList(Linklist *Linklist) {
	//����������о͵�����
	Node Pre_Node = (Node)malloc(sizeof(Node));
	Node Front_Node = (Node)malloc(sizeof(Node));
	Node Middle_Node = (Node)malloc(sizeof(Node));

	Front_Node = Linklist->head->next->next;
	Middle_Node = Linklist->head->next;
	//�Ƚ�ͷ������ת��
	Linklist->head->data = Linklist->head->next->data;
	Linklist->head->next = NULL;
	Linklist->tail = Linklist->head;

	Pre_Node = Linklist->head;

	while (Front_Node->next != NULL)
	{
		Middle_Node->next = Pre_Node;
		Middle_Node->data = Front_Node->data;
		Pre_Node = Middle_Node;
		Middle_Node = Front_Node;
		Front_Node = Front_Node->next;
	}
	Middle_Node->data = Front_Node->data;
	Middle_Node->next = Pre_Node;
	Front_Node->next = Middle_Node;
	Linklist->head = Front_Node;
}
