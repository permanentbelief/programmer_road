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
	int _val;
	TreeNode(int x)
		:_left(nullptr)
		, _right(nullptr)
		, _val(x)
	{}
}TreeNode;

typedef struct BTree
{
	TreeNode* _root = nullptr;
}BTree;

void InitTreeNode(BTree* B, int x)
{
	if (B->_root == nullptr)
	{
		B->_root = new TreeNode(x);
		return;
	}
	TreeNode* prev = nullptr;
	TreeNode* cur = B->_root;
	// TreeNode* cur = new TreeNode(x);
	while (cur != nullptr)
	{
		if (x < cur->_val)
		{
			prev = cur;
			cur = cur->_left;
		}
		else if (x > cur->_val)
		{
			prev = cur;
			cur = cur->_right;
		}
		else
			return;
	}
	cur = new TreeNode(x);
	if (x  <  prev->_val)
		prev->_left = cur;
	else if (x > prev->_val)
		prev->_right = cur;

}
void DFS(TreeNode* root, vector<vector<int>>&res, vector<int> tmp, int SpecialVal)
{
	tmp.push_back(root->_val);
	if (root->_val == SpecialVal)
	{
		res.push_back(tmp);
	}
	if (root->_left)
		DFS(root->_left, res, tmp, SpecialVal);
	if (root->_right)
		DFS(root->_right, res, tmp, SpecialVal);
	tmp.pop_back();
}
vector<vector<int>> FindSpecialWays(TreeNode* root, int SpecialVal)
{
	vector<vector<int>> res;
	vector<int> tmp;
	if (root)
		DFS(root, res, tmp, SpecialVal);

	return res;
}


int main()
{
	BTree B;
	InitTreeNode(&B, 10);
	InitTreeNode(&B, 4);
	InitTreeNode(&B, 2);
	InitTreeNode(&B, 7);
	InitTreeNode(&B, 8);
	InitTreeNode(&B, 5);
	//InitTreeNode(&B, 19);
	InitTreeNode(&B, 17);
	InitTreeNode(&B, 11);

	vector<vector<int>> out;
	out = FindSpecialWays((&B)->_root, 11);
	for (auto e : out)
	{
		for (auto ee : e)
		{
			cout << ee << " ";
		}
		cout << endl;
	}
	system("pause");

}