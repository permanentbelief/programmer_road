#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//
//// 最大的搜索二叉树
//class Node
//{
//public:
//	int value;
//	Node* left;
//	Node* right;
//
//	Node(int value)
//	{
//		this->value = value;
//	}
//
//};
//class ReturnType
//{
//public:
//	int size = 0;
//	Node* head;
//	int min;
//	int max;
//
//	ReturnType(int _size, Node* _head, int _min, int _max)
//	{
//		this->head = _head;
//		this->max = _max;
//		this->min = _min;
//		this->size = _size;
//	}
//};
//
//ReturnType process(Node* head)
//{
//	if (head == nullptr)
//		return ReturnType(0, nullptr, INT_MAX, INT_MIN);
//	Node* left = head->left;
//	ReturnType leftSubTressInfo = process(left);
//	Node* right = head->right;
//	ReturnType rightSubTressInfo = process(right);
//
//	int includeInSelf = 0;
//	if (left == leftSubTressInfo.head
//		&& right == rightSubTressInfo.head
//		&& head->value > leftSubTressInfo.max
//		&& head->value < rightSubTressInfo.min)
//		includeInSelf = leftSubTressInfo.size + rightSubTressInfo.size + 1;
//
//		int p1 = leftSubTressInfo.size;
//		int p2 = rightSubTressInfo.size;
//		int maxSize = max(max(p1, p2), includeInSelf);
//
//		Node* maxHead = p1 > p2 ? leftSubTressInfo.head : rightSubTressInfo.head;
//		if (maxSize == includeInSelf)
//			maxHead = head;
//
//		return ReturnType(maxSize,maxHead,
//		min(min(leftSubTressInfo.min,rightSubTressInfo.min),head->value),
//		max(max(leftSubTressInfo.max, rightSubTressInfo.max), head->value));
//}
//
//
////二叉树上的最远距离
//
//
//// 1.  左树的最大深度 不经过自己
//// 2.  右树的最大深度 不经过自己
//// 3.  自己的 + 左子树的深度 + 右子树的深度
//
//class ReturnType1
//{
//public:
//	int maxDistance;
//	int h;
//
//	ReturnType1(int m, int h)
//	{
//		this->maxDistance = m;
//		this->h = h;
//	}
//};
//ReturnType1* process1(Node* head)
//{
//	if (head == nullptr)
//	{
//		return new ReturnType1{ 0, 0 };
//	}
//	ReturnType1* leftReturnType = process1(head->left);
//	ReturnType1* rightReturnType = process1(head->right);
//
//	int includeHeadDistance = leftReturnType->h + 1 + rightReturnType->h;
//
//	int p1 = leftReturnType->maxDistance;
//	int p2 = rightReturnType->maxDistance;
//
//	int resultDistance = max(max(p1, p2), includeHeadDistance);
//	int itself = max(leftReturnType->h, rightReturnType->h) + 1;
//
//	return new ReturnType1{ resultDistance, itself };
//
//
//}
#include <map>

//class Node1
//{
//public:
//	int huo;
//	vector<Node1*> nexts[26];
//	Node1()
//	{
//
//	}
//	Node1(int huo)
//	{
//		this->huo = huo;
//		for (int i = 0; i < 26; i++)
//		{
//			nexts[i] = nullptr;
//		}
//	}
//};
//class ReturnData
//{
//public:
//	int lai_huo;
//	int bu_lai_huo;
//	ReturnData(int lai_huo, int bu_lai_huo)
//	{
//		this->lai_huo = lai_huo;
//		this->bu_lai_huo = bu_lai_huo;
//	}
//};
//
//int getMaxhuo(Node1* head)
//{
//
//}
//
//ReturnData process(Node1* head)
//{
//	int  huo = head->huo;
//	int buhuo = 0;
//	for (int i = 0; i < head->nexts.size(); i++)
//	{
//		Node1* next = head->nexts[i];
//
//
//	}
//}

//
//int process(vector<vector<int>>& matrix)
//{
//	vector<vector<int>> dp =
//}
//int main()
//{
//	Node* head = new Node(10);
//	head->left = new Node(11);
//	head->right = new Node(11);
//	head->left->right = new Node(12);
//	head->left->left = new Node(0);
//	cout << process1(head)->maxDistance << endl;
//
//	system("pause");
//}


#include <unordered_map>
#include <unordered_set>
#include <set>
int maxLength(string str)
{
	int res = 0;
	unordered_map<char, int> mymap;
	int start = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (mymap.find(str[i]) != mymap.end())
		{
			start = max(start, mymap[str[i]]);
		}
		mymap[str[i]] = i ;
		res = max(res,i-start);
	}
	return res;
 }

//int Get()
//{
//	vector<vector<int>> dp = 
//}

int main()
{
	string str1 = "bbbbb";
	cout << maxLength(str1) << endl;
	string str2 = "abca";
	cout << maxLength(str2) << endl;
	string str5 = "abcdedafg";
	cout << maxLength(str5) << endl;
	string str3 = "abcabcbb";
	cout << maxLength(str3) << endl;
	string str4 = "pwwkew";
	cout << maxLength(str4) << endl;
	system("pause");
}