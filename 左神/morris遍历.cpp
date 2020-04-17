#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


typedef struct TreeNode
{
	struct TreeNode* _left;
	struct TreeNode* _right;
}Node;

typedef struct Tree
{
	Node* _head;
}Tree;

void morris(Node* head)
{
	if (head == nullptr)
	{
		return;
	}
	Node* cur = head;
	Node* mostRight = nullptr;
	while (cur != nullptr)
	{
		mostRight = cur->_left;
		if (mostRight != nullptr)
		{
			while (mostRight->_right != nullptr && mostRight->_right != cur)
			{
				mostRight = mostRight->_right;
			}
			if (mostRight->_right == nullptr)
			{
				mostRight->_right = cur;
				cur = cur->_left;
				continue;
			}
			else //这里就是 mostRight 指向了cur,所以要还原回去，将它指回去 
			{
				mostRight->_right = nullptr;
			}
		}
		mostRight->_right = nullptr;
	}
}
