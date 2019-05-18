#pragma once
//��������
#define Status bool
#define OK true
#define ERROR false 
#include<iostream>
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
using namespace std;
class tree {
	public:
		Status CreateBiTree(BiTree &T);
		//�������������������н���ֵ
		//������������ʾ�Ķ�����T
		Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e));
		//���ö�������洢�ṹ,Visit�ǶԽ�������Ӧ�ú���
		//�������������T,��ÿ�������ú���Visitһ���ҽ�һ��
		//һ��visit()ʧ��, �����ʧ��
		Status InOrderTraverse(BiTree T, Status(*visit)(TElemType e));
		//���ö�������洢�ṹ, Visit�ǶԽ�������Ӧ�ú���.
		//�������������T, ��ÿ���ڵ���ú���Visitһ���ҽ�һ��.
		//һ��visit()ʧ��, �����ʧ��
		Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e));
		//���ö�������洢�ṹ, Visit�ǶԽ�������Ӧ�ú���.
		//�������������T, ��ÿ���ڵ���ú���Visitһ���ҽ�һ��.
		//һ��visit()ʧ��, �����ʧ��
		Status BiTree_Transposition(BiTree &T);
		//���øú����Զ���������ת��
};



Status tree::CreateBiTree(BiTree &T) {
	//�������������������н���ֵ(һ���ַ�), �ո��ַ���ʾ����)
	//������������ʾ�Ķ�����T
	char ch;
	cin >> ch;
	if (ch == '*') T = NULL;
	else {
		if (!(T = new BiTNode)) exit(OVERFLOW);
		T->data = ch;                     //���ɸ����
		CreateBiTree(T->lchild);          //����������
		CreateBiTree(T->rchild);          //����������
	}
	return OK;
}

Status tree::PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	//���ö�������洢�ṹ, Visit�Ƕ�����Ԫ�ز�����Ӧ�ú���,
	//�������������T�ĵݹ麯��, ��ÿ������Ԫ�ص��ú���Visit.
	//��򵥵�Visit������:
	// Status PrintElement( TElemType e ){
	//	 printf(e);
	//   return OK;
	// }
	//����ʵ��:PrePrderTraverse(T, PrintElement);
	if (T) {
		if (Visit(T->data))
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit)) return OK;
		return ERROR;
	}
	else return OK;
}//PreOrderTtraverse

Status tree::InOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	if (T) {
		if (InOrderTraverse(T->lchild, Visit))
			if (Visit(T->data))
				if (InOrderTraverse(T->rchild, Visit)) return OK;
		return ERROR;
	}
}//InOrderTraverse

Status tree::PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	if (T) {
		if (PostOrderTraverse(T->lchild, Visit))
			if (PostOrderTraverse(T->rchild, Visit))
				if (Visit(T->data)) return OK;
		return ERROR;
	}
}//PostOrderTraverse

Status tree::BiTree_Transposition(BiTree &T) {
	BiTree Current = new BiTNode;
	if (T) {
		Current = T->lchild;
		T->lchild = T->rchild;
		T->rchild = Current;
		if (BiTree_Transposition(T->lchild))
			if (BiTree_Transposition(T->rchild))
				return OK;
	}
	return ERROR;
}