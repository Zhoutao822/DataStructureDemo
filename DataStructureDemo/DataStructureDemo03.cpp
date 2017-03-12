// DataStructureDemo03.cpp : 定义控制台应用程序的入口点。
//基本数据结构：栈，队列，链表
//静态链表  返回两个链表首个共用结点的地址，如果没有输出-1
#include "stdafx.h"
#include<cstdio>
#include<cstring>
const int maxn = 10010;


struct NODE
{
	char data;
	int next;
	bool flag;
}node[maxn];

int main()
{
	for (int i = 0; i < maxn; i++) {
		node[i].flag = false;
	}
	int s1, s2, n;
	scanf("%d%d%d", &s1, &s2, &n);
	int address, next;
	char data;
	for (int i = 0; i < n; i++) {
		scanf("%d %c %d",&address,&data,&next);
		node[address].data = data;
		node[address].next = next;
	}
	int p;
	for (p = s1; p != -1; p = node[p].next) {
		node[p].flag = true;
	}
	for (p = s2; p != -1;p=node[p].next) {
		if (node[p].flag == true) break;
	}
	if (p != -1) {
		printf("%05d\n",p);
	}
	else
	{
		printf("-1\n");
	}
    return 0;
}

