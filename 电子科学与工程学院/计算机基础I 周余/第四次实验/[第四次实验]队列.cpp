#include<iostream>
using namespace std;

typedef int QElemType;
typedef bool Status;
#define OK true
#define ERROR false
typedef struct QNode {
	//�ڵ�ṹ
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q);     //����һ���ն���
Status DestroyQueue(LinkQueue &Q);  //����һ������ ����Q��������
Status EnQueue_Tail(LinkQueue &Q, QElemType e);  //����Ԫ��eΪQ�µĶ�βԪ��
Status EnQueue_Head(LinkQueue &Q, QElemType e);  //����Ԫ��eΪQ�µĶ�ͷԪ��
Status DeQueue_Head(LinkQueue &Q, QElemType &e); //�����в���, ��ɾ��Q�Ķ�ͷԪ��, ��e������ֵ, ������OK;//���򷵻�ERROR
Status DeQueue_Tail(LinkQueue &Q, QElemType &e); //�����в���, ��ɾ��Q�Ķ�βԪ��, ��e������ֵ, ������OK;//���򷵻�ERROR
Status ClearQueue(LinkQueue &Q);                 //���������

int main() {
	//����n,k��ֵ�Լ�����
	int n, k;
	cout << "������n��k��ֵ:" << endl;
	cin >> n >> k;
	int *list = (int*)malloc(n * sizeof(int));
	cout << "����������Ԫ��" << endl;
	for (int i = 0; i < n; i++)
		cin >> list[i];
	//����һ���µ�˫�����
	LinkQueue Q;
	InitQueue(Q);
	cout << "������Сֵ����:" << endl;
	cout << "[";
	int Frequency = 0; //��ǲ�������
	int Pop;
	for (int i = 0; i <= n; i++) {
		if (Frequency >= k) cout << list[Q.front->data] << " ";
		if (i == n) break;
		if (Frequency == 0) {
			EnQueue_Head(Q, i);
			Frequency++;
		}
		if (i - Q.front->data >= k)
		{
			DeQueue_Head(Q, Pop);
		}
		if (list[i] < list[Q.front->data] &&list[i] < list[Q.rear->data]) {
			InitQueue(Q);
			EnQueue_Head(Q, i);
			Frequency++;
		}
		else if (list[i] > list[Q.front->data] && list[i] > list[Q.rear->data]) {
			EnQueue_Tail(Q, i);
			Frequency++;
		}
		else if (list[i] > list[Q.front->data] && list[i] < list[Q.rear->data]) {
			DeQueue_Tail(Q, Pop);
			EnQueue_Tail(Q, i);
			Frequency++;
		}

	}
	cout << "]" << endl;
	system("pause");
	return 0;
}

Status InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q) {
	while (Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

Status EnQueue_Tail(LinkQueue &Q, QElemType e) {
	 //����eΪQ���µĶ�βԪ��
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue_Head(LinkQueue &Q, QElemType &e) {
	//ɾ�����е�ͷԪ��
	if (Q.front == Q.rear) return ERROR;
	QueuePtr p = Q.front;
	e = p->data;
	p = Q.front->next;
	Q.front = p;
	if (Q.rear == p) Q.rear = Q.front;
	return OK;
}

Status DeQueue_Tail(LinkQueue &Q, QElemType &e) {
	//ɾ�����е�βԪ��
	QueuePtr Current = Q.front;
	while (Current->next != Q.rear)
		Current = Current->next;
	e = Current->data;
	free(Current->next);
	Q.rear = Current;
	Q.rear->next = NULL;
	return OK;
}

Status EnQueue_Head(LinkQueue &Q, QElemType e) {
	//����eΪ�µĶ�ͷԪ��
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = Q.front->next;
	Q.front->next = p;
	Q.front = p;
	if (!Q.front->next) Q.rear = Q.front;
	return OK;
}

