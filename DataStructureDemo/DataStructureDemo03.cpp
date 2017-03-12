// DataStructureDemo02.cpp : 定义控制台应用程序的入口点。
//基本数据结构：栈，队列，链表
//动态链表的基本操作 增删改查
#include "stdafx.h"
#include<cstdio>

#define N 10

struct node
{
	int data;
	node* next;
};
//创建链表
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

//查找元素 返回链表中x的个数
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

//插入元素
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

//删除元素
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

