// DataStructureDemo01.cpp : 定义控制台应用程序的入口点。
//基本数据结构：栈，队列，链表
//简单计算器逻辑，中缀转后缀，后缀计算
#include "stdafx.h"

#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<string>
#include<map>
using namespace std;

struct node
{
	double num;
	char op;
	bool flag;
};

string str;
stack<node> s;
queue<node> q;
map<char, int> op;

void Change() {
	//double num;
	node temp;
	for (unsigned int i = 0; i < str.length();) {
		if (str[i] >= '0'&&str[i] <= '9') {
			temp.flag = true;//标记为数字
			temp.num = str[i++] - '0';
			while (i < str.length() && str[i] >= '0'&&str[i] <= '9') {
				temp.num = temp.num * 10 + (str[i] - '0');
				i++;
			}
			q.push(temp);
		}
		else
		{
			temp.flag = false;//标记为操作符
			while (!s.empty() && op[str[i]] <= op[s.top().op]) {
				q.push(s.top());
				s.pop();
			}
			temp.op = str[i];
			s.push(temp);
			i++;
		}
	}
	while (!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
}

double Cal() {
	double temp1, temp2;
	node cur, temp;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur.flag == true) s.push(cur);
		else
		{
			temp2 = s.top().num;
			s.pop();
			temp1 = s.top().num;
			s.pop();
			temp.flag = true;
			if (cur.op == '+')temp.num = temp1 + temp2;
			else if (cur.op == '-')temp.num = temp1 - temp2;
			else if (cur.op == '*')temp.num = temp1 * temp2;
			else temp.num = temp1 / temp2;
			s.push(temp);
		}
	}
	return s.top().num;
}

//int main()
//{
//	op['+'] = op['-'] = 1;
//	op['*'] = op['/'] = 2;
//	/*while (getline(cin, str)&&str != "\0") {
//		for (string::iterator it = str.begin(); it != str.end(); it++) {
//			if (*it == ' ') str.erase(it);
//		}
//	}*/
//	getline(cin, str);
//	while (!s.empty())
//	{
//		s.pop();
//	}
//	Change();
//	printf("%.2f\n", Cal());
//    return 0;
//}

