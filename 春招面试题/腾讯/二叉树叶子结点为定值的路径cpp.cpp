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

void DFS(TreeNode* root, int expectNumber, vector<vector<int>>& res, vector<int> path)
{
	path.push_back(root->_val);
	if (root->_left == NULL && root->_right == NULL)
	{
		if (expectNumber == root->_val)
			res.push_back(path);
	}
	if (root->_left)
		DFS(root->_left, expectNumber - root->_val, res, path);
	if (root->_right)
		DFS(root->_right, expectNumber - root->_val, res, path);
	path.pop_back();
}
vector<vector<int>> FindPath(TreeNode* root, int expectNumber)
{
	vector<vector<int>> res;
	vector<int> path;
	if (root)
		DFS(root, expectNumber, res, path);
	return res;
}

int main()
{
	BTree B;
	InitTreeNode(&B, 5);
	InitTreeNode(&B, 3);
	InitTreeNode(&B, 2);
	InitTreeNode(&B, 4);
	InitTreeNode(&B, 6);
	InitTreeNode(&B, 7);
	vector<vector<int>> out;
	out = FindPath((&B)->_root, 12);
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