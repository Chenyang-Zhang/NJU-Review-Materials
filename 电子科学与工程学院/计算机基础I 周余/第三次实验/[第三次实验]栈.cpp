/*
���ݽṹ�γ�ʵ����
����:ջ�ı�ʾ��ʵ��
ʱ��:2018/3/27/16:24
Copyright@����ͩ. All Rights Reserved.
*/
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

#define STACK_INIT_SIZE 10
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
typedef bool Status;
typedef char SElemType;
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S) {
	//����һ����ջS
	S.base = (SElemType *)malloc(sizeof(SElemType)*STACK_INIT_SIZE);
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(SqStack &S) {
	//����ջS,S���ٴ���
	free(S.base);
	free(S.top);
	S.stacksize = NULL;
	return OK;
}

SElemType *Push(SqStack &S, SElemType e){
	//����Ԫ��eΪ�µ�ջ��Ԫ�� ����ջ��ָ��
	if (S.top - S.base >= S.stacksize) {
		//ջ��,׷�Ӵ洢�ռ�
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return S.top;
}

Status Pop(SqStack &S, SElemType &e) {
	//��ջ����, ��ɾ��ջ��Ԫ��, ��e������ֵ, ������OK, ���򷵻� ERROR
	if (S.top == S.base) {
		printf("��ջ �޷�����Pop����\n");
		return ERROR;
	}
	e = *--S.top;
	return OK;
}

Status Print(SqStack &S) {
	//��ջ������Ԫ�ش�ӡ����Ļ��
	SElemType *Temp = S.top - 1;
	for (; Temp+1 != S.base; Temp--)
		printf("%c ", *Temp);
	printf("\n");
	return OK;
}

int main()
{
	//����һ����ջ;
	SqStack S;
	InitStack(S);
	//
	char New;
	while (OK) {
		New = getchar();
		getchar();
		if (New == *(S.top-1))
		{
			Pop(S, New);
			printf("��ջ��Ԫ����ͬ ����ջ��Ԫ��:\n");
			Print(S);
		}
		else if (New == '$')
		{
			printf("ֹͣ����\n");
			break;
		}
		else
		{
			Push(S, New);
			printf("��ջ��Ԫ�ز�ͬ ѹ��ջ:\n");
			Print(S);
		}
	}
	system("pause");
	return 0;
}