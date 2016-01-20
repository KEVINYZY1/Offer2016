/*
�ж�һ�������Ƿ�Ϊ���Ľṹ��
���ף�
���������ΪN��ʱ�临�Ӷ�ΪO(N),����ռ临�ӶȴﵽO(1)
*/


#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int v) :val(v), next(NULL){}
};

ListNode *insert(ListNode *head, int val)
{
	if (!head)
	{
		head = new ListNode(val);
		head->next = head;
	}
	else{
		ListNode *p = head;
		while (p->next != head)
			p = p->next;
		p->next = new ListNode(val);
		p->next->next = head;
	}//else
	return head;
}

void display(ListNode *head)
{
	if (!head)
		cout << endl;
	else{
		ListNode *p = head;
		while (p->next != head)
		{
			cout << p->val << "��>";
			p = p->next;
		}//while
		cout << p->val << endl;
	}//else
}

/*���ø���ջ�洢�������нڵ�*/
bool isPalindrom1(ListNode *head)
{
	if (!head)
		return false;
	stack<int> stk;
	ListNode *p = head;
	while (p)
	{
		stk.push(p->val);
		p = p->next;
	}//while

	p = head;
	while (!stk.empty() && p)
	{
		if (stk.top() != p->val)
			return false;
		stk.pop();
		p = p->next;
	}//while
	return true;
}

/*�����������ø���ջ�洢������Ұ벿��*/
bool isPalindrom2(ListNode *head)
{
	if (!head)
		return true;
	stack<int> stk;

	ListNode *slow = head->next, *fast = head;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}//while
	
	/*��ʱfastָ���Ұ벿�ֵ�һ���ڵ�*/
	while (fast)
	{
		stk.push(fast->val);
		fast = fast->next;
	}//while

	slow = head;
	while (!stk.empty())
	{
		if (stk.top() != slow->val)
			return false;
	}//while
	return true;
}

/*�������������������ṹ�����������Ұ벿�ַ�ת��Ȼ��Ƚ�*/
bool isPalindrom3(ListNode *head)
{
	if (!head)
		return false;
	ListNode *n1 = head, *n2 = head;
	while (n2->next &&n2->next->next)
	{
		n1 = n1->next;
		n2 = n2->next;
	}//while
	n2 = n1->next; /*��ʱqָ���Ұ벿�ֵ�һ���ڵ�*/
	/*��벿������*/
	n1->next = NULL;
	ListNode *n3 = NULL;
	while (n2)
	{
		n3 = n2->next;
		n2->next = n1;
		n1 = n2;
		n2 = n3;
	}//while
	n3 = n1;
	n2 = head;
	bool ret = true;
	while (n1 &&n2)
	{
		if (n1->val != n2->val)
		{
			ret = false;
			break;
		}//if
		n1 = n1->next;
		n2 = n2->next;
	}//while

	n1 = n3->next;
	n3->next = NULL;
	while (n1)
	{
		n2 = n1->next;
		n1->next = n3;
		n3 = n1;
		n1 = n2;
	}//while
	return ret;
}