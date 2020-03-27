#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//  // 三体攻击
//int getInt()
//{
//	char ch = getchar();
//	int x = 0;
//	int f = 1;
//	while (ch < '0' || ch > '9')
//	{
//		if (ch == '-')
//			f = -1;
//		ch = getchar();
//	}
//	while ('0' <= ch && ch <= '9')
//	{
//		x = x * 10 + ch - '0';
//		ch = getchar();
//	}
//	return x*f;
//}
//
//
//inline int getIndex(int i, int j, int k)
//{
//	return ((i - 1)*b + (j - 1))*c + k;
//}
//
//int a = 0;
//int b = 0;
//int c = 0;
//int A = 0;
//int B = 0;
//int C = 0;
//int m = 0;
//int main()
//{
//	A = getInt();
//	B = getInt();
//	C = getInt();
//	m = getInt(); 
//	a = A + 1, b = B + 1, c = C + 1;
//	
//	int* data = new int[a*b*c];
//
//
//	int(*atk)[7] = new int[m + 1][7];
//
//	for (int i = 1; i <= A; i++)
//	{
//		for (int j = 1; j <= B; j++)
//		{
//			for (int k = 1; k <= C; ++k)
//			{
//				data[getIndex(i, j, k)] = getInt();
//			}
//		}
//	}
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = 0; j < 7; j++)
//		{
//			atk[i][i] = getInt();
//		}
//		//执行攻击
//		for (int x = atk[i][0]; x <= atk[i][1]; i++)
//		{
//			for (int y = atk[i][2]; y <= atk[i][3]; ++y)
//			{
//				for (int z = atk[i][4]; z <= atk[i][5]; ++z)
//				{
//					data[getIndex(x, y, z)] -= atk[i][6];
//					if (data[getIndex(x, y, z)] < 0)
//					{
//						cout << i << endl;
//						delete[] data;
//						delete[] atk;
//						return 0;
//					}
//				}
//			}
//		}
//	}
//
//
//	system("pause");
//}


//全球变暖



void DFS(vector<vector<char>>& vvc, vector<vector<bool>>& books,int x, int y)
{
	books[x][y] = true;
	if (vvc[x][y] == '#')
	{
		vvc[x][y] = '.';
		return;
	}


	if (x - 1 >= 0 && books[x-1][y] == false)
	{
		DFS(vvc,books, x - 1, y);
	}
	if (x + 1 < vvc.size() && books[x+1][y] == false)
	{
		DFS(vvc, books, x + 1, y);
	}
	if (y - 1 >= 0 && books[x][y-1] == false)
	{
		DFS(vvc, books, x, y - 1);
	}
	if (y + 1 < vvc[0].size() && books[x][y+1] == false)
	{
		DFS(vvc,books, x, y + 1);
	}

}


//int main()
//{
//	int N = 0;
//	while (cin >> N)
//	{
//		vector<vector<bool>> books(N,vector<bool>(N, false));
//		vector<vector<char>> vvc(N, vector<char>(N));
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				cin >> vvc[i][j];
//			}
//		}
//		//海洋 .
//		//陆地 #
//
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				if (vvc[i][j] == '.' && books[i][j] == false)
//				{
//					DFS(vvc, books, i, j);
//				}
//			}
//		}
//		for (auto e : vvc)
//		{
//			for (auto ee : e)
//			{
//				cout << ee;
//			}
//			cout << endl;
//		}
//	}
//}
/*
7
.......
.##....
.##....
....##.
..####.
...###.
.......

5
..##.
####.
.###.
.....
.....

*/


//输出的是给定所有牌的全排列
#include <iostream>
#include<vector>
using namespace std;
//首先是每次都要重复干的事情，每次就是在盒子前面将手里的牌按从小到大的顺序放一张放到
//盒子里面
bool flags[4] = { false };
int  books[4];
int pai = 3;
void dfs(int steps)
{
	//先做三个盒子三张扑克牌
	if (steps == pai + 1)
	{
		for (int i = 1; i <= pai; ++i)
		{
			cout << books[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= pai; ++i)
	{
		if (flags[i] == false)
		{
			books[steps] = i;
			flags[i] = true;
			dfs(steps + 1);
			flags[i] = false;
		}
	}


}
int main()
{
	dfs(1);
	system("pause");
	return 0;
}



#include <iostream>
#include <vector>
#include <stack>

void Core(const std::vector<int>& arr, std::vector<int>& cur, std::stack<int>& sta, int index, std::vector<std::vector<int>>& res)
{
	if (sta.empty() && index == arr.size())
	{
		res.push_back(cur);
		return;
	}
	if (index < arr.size())
	{
		sta.push(arr[index]);
		Core(arr, cur, sta, index + 1, res);
		sta.pop();
	}
	if (!sta.empty())
	{
		int temp = sta.top();
		sta.pop();
		cur.push_back(temp);
		Core(arr, cur, sta, index, res);
		sta.push(temp);
		cur.pop_back();
	}
}
std::vector<std::vector<int>> Sol(std::vector<int> arr)
{
	std::vector<std::vector<int>> res;
	std::stack<int> sta;
	std::vector<int> cur;
	if (arr.size() < 1)
	{
		return res;
	}
	Core(arr, cur, sta, 0, res);
	return res;
}
int main()
{
	std::vector<std::vector<int>> res = Sol({ 1, 2, 3 });
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[0].size(); j++)
		{
			std::cout << res[i][j] << " ";
		}
		std::cout << std::endl;
	}
}