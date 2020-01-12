#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

typedef int ListType;
typedef struct ListNode
{
	struct ListNode* _next;
	ListType _val;
	/*ListNode()
		:_next(nullptr)
		, _val(0)
	{
	}*/
}ListNode;

void AddTotail(ListNode** pHead, int value)
{
	ListNode* newnode = new ListNode();
	newnode->_next = nullptr;
	newnode->_val = value;
	if (*pHead == nullptr)
	{
		*pHead = newnode;
	}
	else
	{
		ListNode* cur = *pHead;
		while (cur->_next)
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}
}
void ListPrint(ListNode* List)
{
	if (List == nullptr)
		return;
	ListNode* cur = List;
	while (cur)
	{
		cout << cur->_val << " ";
		cur = cur->_next;
	}
	cout << endl;
}
//µ¹Ðò´òÓ¡
void ReversePrint(ListNode* List)
{
	if (List == nullptr)
		return;
	stack<ListNode*> s;
	ListNode* cur = List;
	while (cur)
	{
		s.push(cur);
		cur = cur->_next;
	}
	while (!s.empty())
	{
		cout << s.top()->_val << " ";
		s.pop();
	}
	cout << endl;
}
// ÀûÓÃµÝ¹é µ¹Ðò´òÓ¡
void ReverseListR(ListNode* list) //Ì«¶à¿ÓÁË
{
	if (list == nullptr)
		return;
	if (list->_next)
	{	
		
		ReverseListR(list->_next);	
	
	}
	cout << list->_val << " ";
}
int main()
{
	ListNode *l = nullptr ;
	AddTotail(&l, 3);
	AddTotail(&l, 4);
	AddTotail(&l, 5);

	ListPrint(l);
	ReversePrint(l);
	ReverseListR(l);
	ListNode * List = nullptr;
	ReversePrint(List);

	system("pause");
}