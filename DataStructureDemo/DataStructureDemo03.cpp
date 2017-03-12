// DataStructureDemo02.cpp : �������̨Ӧ�ó������ڵ㡣
//�������ݽṹ��ջ�����У�����
//��̬����Ļ������� ��ɾ�Ĳ�
#include "stdafx.h"
#include<cstdio>

#define N 10

struct node
{
	int data;
	node* next;
};
//��������
node* create(int Array[]) {
	node *p, *pre, *head;
	head = new node;
	head->next = NULL;
	pre = head;
	for (int i = 0; i < N; i++) {
		p = new node;
		p->data = Array[i];
		p->next = NULL;
		pre->next = p;
		pre = p;
	}
	return head;
}

//����Ԫ�� ����������x�ĸ���
int search(node* head, int x) {
	int count = 0;
	node* p = head->next;
	while (p != NULL) {
		if (p->data == x) {
			count++;
		}
		p = p->next;
	}
	return count;
}

//����Ԫ��
void insert(node* head, int pos, int x) {
	node* p = head;
	for (int i = 0; i < pos - 1; i++) {
		p = p->next;
	}
	node* q = new node;
	q->data = x;
	q->next = p->next;
	p->next = q;
}

//ɾ��Ԫ��
void del(node* head, int x) {
	node* p = head->next;
	node* pre = head;
	while (p != NULL) {
		if (p->data == x) {
			pre->next = p->next;
			delete(p);
			p = pre->next;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}

int main()
{
	int Array[N] = { 5,3,6,1,2 };
	node* L = create(Array);

	printf("%d\n", search(L, 0));
	printf("\n");

	insert(L, 2, 111);

	del(L, 0);

	L = L->next;
	while (L != NULL) {
		printf("%d ",L->data);
		L = L->next;
	}


    return 0;
}

