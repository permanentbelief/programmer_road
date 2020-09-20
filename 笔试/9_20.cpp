#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>

using namespace std;

//
//class Solution {
//public:
//
//	int max_ = 0;
//	void dfs(string& s, set<string>& ss, int u)
//	{
//		if (u == s.size())
//		{
//			max_ = max(max_, (int)ss.size());
//			return;
//		}
//		if (u > s.size())
//		{
//			return;
//		}
//		for (int i = u; i < s.size(); i++)
//		{
//			string tmp = s.substr(u, i - u + 1);
//			if (!ss.count(tmp))
//			{
//				//count += 1;
//				ss.insert(tmp);
//				dfs(s, ss, i + 1);
//				//count -= 1;
//				//    dfs(s,ss, u + 1, );
//				ss.erase(tmp);
//			}
//
//		}
//	}
//	int maxUniqueSplit(string s) {
//		if (s.empty())
//			return 0;
//
//		set<string> ss;
//		dfs(s, ss, 0);
//		return max_;
//
//	}
//};
//int main()
//{
//	string str = "ababccc";
//	Solution s;
//	cout << s.maxUniqueSplit(str) << endl;
//	system("pause");
//}

class Solution3 {
public:

	//vector<bool> rows(10);
	//vector<bool> cols(10);
	typedef long long ll;
	vector<vector<char>> b;
	void dfs(vector<vector<char>>& board, int row, int col)
	{
		// cout << "!!!!" << endl;

		if (col == 9)
		{
			row++;
			col = 0;
			dfs(board, row , col);
			//return;
		}
		if (row == 9)
		{
			b = board;
			return;
		}
		if (board[row][col] != '.')
		{
			dfs(board, row, col + 1);
			//return;
		}
		else
		{
			for (int i = 1; i <= 9; i++)
			{
				char a = (char)(i + '0');
				if (isValid(row, col, a, board))
				{
					board[row][col] = a;
					dfs(board, row, col + 1);
					board[row][col] = '.';
				}
			}
		}

	}
	bool isValid(int row, int col, char n, vector<vector<char>>& board)
	{
		for (int i = 1; i <= 9; i++)
		{
			if (board[row][i - 1] == n || board[i - 1][col] == n)
				return false;
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[(row / 3 * 3) + i][col / 3 * 3 + j] == n)
					return false;
			}
		}
		return true;
	}
	void solveSudoku(vector<vector<char>>& board) {
		int m = board.size();
		int n = board[0].size();
		dfs(board, 0, 0);

		board = b;

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}


	}
};


#include "a.h"

class A
{
public:
	int c = 10;
	int k = 1000;
	A()
	{
		delete this;
		//cout << c << endl;
		cout << "A ()" << endl;

	}
	~A()
	{
		cout << "~A()" << endl;
	}
	void func()
	{
		cout << "Func" << endl;
		//memset(this, 0, sizeof(*this));
	}
};



/*
void swap(int* a, int i, int j)
{
	a[i] ^= a[j];
	a[j] ^= a[i];
	a[i] ^= a[j];
}

//将数组a中的下标i到下标j之间的所有元素逆序倒置
void reverse(int a[], int i, int j)
{
	for (; i<j; ++i, --j)
	{
		swap(a, i, j);
	}
}

void print(int a[], int length)
{
	for (int i = 0; i<length; ++i)
		cout << a[i] << " ";
	cout << endl;
}

//求取全排列，打印结果
void combination(int a[], int length)
{
	if (length<2) return;

	bool end = false;
	while (true)
	{
		print(a, length);

		int i, j;
		//找到不符合趋势的元素的下标i
		for (i = length - 2; i >= 0; --i)
		{
			if (a[i]<a[i + 1]) break;
			else if (i == 0) return;
		}

		for (j = length - 1; j>i; --j)
		{
			if (a[j]>a[i]) break;
		}

		swap(a, i, j);
		reverse(a, i + 1, length - 1);
	}
}
*/
void swap(int* a, int i, int j)

{

	a[i] ^= a[j];

	a[j] ^= a[i];

	a[i] ^= a[j];

}



//将数组a中的下标i到下标j之间的所有元素逆序倒置

void reverse(int a[], int i, int j)

{

	for (; i<j; ++i, --j)

	{

		swap(a, i, j);

	}

}



void print(int a[], int length)

{

	for (int i = 0; i<length; ++i)

		cout << a[i] << " ";

	cout << endl;

}



//求取全排列，打印结果

void combination(int a[], int length)

{

	if (length<2) return;



	bool end = false;

	while (true)

	{

		print(a, length);



		int i, j;

		//找到不符合趋势的元素的下标i

		for (i = length - 2; i >= 0; --i)

		{

			if (a[i]<a[i + 1]) break;

			else if (i == 0) return;

		}



		for (j = length - 1; j>i; --j)

		{

			if (a[j]>a[i]) break;

		}



		swap(a, i, j);

		reverse(a, i + 1, length - 1);

	}

}
int main()
{

	int a[4] = { 1, 3, 4, 2 };
	combination(a, 4);


	system("pause");
}