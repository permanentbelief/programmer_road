#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
//void Dfs(int index, int n, vector<int>& boxs, vector<int>& book)
//{
//	if (index == n + 1)
//	{
//		for (int i = 1; i <= n; i++)
//			cout << boxs[i] << " ";
//		cout << endl;
//		return; //向上回退
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (book[i] == 0)  //第i号牌仍在手上
//		{
//			boxs[index] = i;
//			book[i] = 1;  //现在第i号牌已经被用了
//			//处理下一个盒子
//			Dfs(index + 1, n, boxs, book);
//			//从下一个盒子回退到当前盒子，取出当前盒子的牌，
//			//尝试放入其它牌。
//			book[i] = 0;
//		}
//	}
//}
//int main()
//{
//	int n;
//	vector<int> boxs;
//	vector<int> books;
//	cin >> n;
//	boxs.resize(n + 1, 0);
//	books.resize(n + 1, 0);
//	Dfs(1, n, boxs, books);
//	system("pause");
//	return 0;
//}

/*
// Employee info
class Employee {
public:
// It's the unique ID of each node.
// unique id of this employee
int id;
// the importance value of this employee
int importance;
// the id of direct subordinates
vector<int> subordinates;
};
*/

//#include <unordered_map>
//
//class Employee {
//public:
//	int id;
//	int importance;
//	vector<int> subordinates;
//};
//class Solution {
//public:
//	//void DFS(unordered_map<int, Employee*>& m, Employee* employee, int &sum)
//	//{
//	//	auto v = employee->subordinates;
//	//	sum += employee->importance;
//	//	for (auto vinteger : v)
//	//	{
//	//		if (!m[vinteger]->subordinates.empty())
//	//		{
//	//			DFS(m, m[vinteger], sum);
//	//		}
//	//		sum += m[vinteger]->importance;
//	//	}
//	//}
//	int DFS(unordered_map<int, Employee*> info, int curID)
//	{
//		int curImportance = info[curID]->importance;
//
//		for (auto subid : info[curID]->subordinates)
//		{
//			curImportance += DFS(info, subid);
//		}
//		return curImportance;
//	}
//	int getImportance(vector<Employee*> employees, int id) {
//
//		unordered_map<int, Employee*> info;
//		for (auto& e : employees)
//		{
//			info[e->id] = e;
//		}
//
//		return DFS(info, id);
//
//		//int sum = 0;
//		//unordered_map<int, Employee*> m;
//		//for (int i = 0; i < employees.size(); i++)
//		//{
//		//	m[employees[i]->id] = employees[i];
//		//}
//		//Employee* e =nullptr;
//		//for (int i = 0; i < employees.size(); i++)
//		//{
//		//	if (employees[i]->id == id)
//		//	{
//		//		e = employees[i];
//		//		break;
//		//	}
//		//}
//		//DFS(m, e, sum);
//		//return sum;
//	}
//};
//
//int main()
//{
//	Employee e1;
//	Employee e2;
//	Employee e3;
//	Employee e4;
//	e1.id = 1;
//	e1.importance = 5;
//	e1.subordinates = { 2, 3 };
//	e2.id = 2;
//	e2.importance = 3;
//	e2.subordinates = {4};
//	e3.id = 3;
//	e3.importance = 4;
//	e3.subordinates = {};
//	e4.id = 4;
//	e4.importance = 1;
//	e4.subordinates = {};
//	vector<Employee*> vE = { &e1, &e2, &e3, &e4 };
//	Solution s;
//	cout << s.getImportance(vE, 1) << endl;
//	system("pause");
//}


//class Solution {
//public:
//
//	void DFS(vector<vector<int>>& vv, vector<vector<int>>& image, int x, int y, int newColor, int oldColor)
//	{
//
//		vv[x][y] = newColor;
//		static int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = x + pos[i][0];
//			int ny = y + pos[i][1];
//			if (nx < 0 || ny < 0 || nx >= image.size() || ny >= image[0].size() )
//				continue;
//			if (vv[nx][ny] == oldColor)
//				DFS(vv, image, nx, ny, newColor, oldColor);
//		}
//	}
//	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//		vector<vector<int>> vv(image);
//		if (image.empty())
//		{
//			return vv;
//		}
//		if (image[sr][sc] == newColor)
//			return image;
//		int oldColor = image[sr][sc];
//		DFS(vv, image, sr, sc, newColor, oldColor);
//		return vv;
//
//
//	}
//};
//
//int main()
//{
//	vector<vector<int>> image = { { 1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 1 } };
//	int sr = 1;
//	int sc = 1;
//	int newColor = 2;
//	Solution s;
//	vector<vector<int>> v = s.floodFill(image, sr, sc, newColor);
//	system("pause");
//
//}


//class Solution {
//public:
//	void DFS(vector<vector<char>>& grid, vector<vector<bool>>& books, int x, int y)
//	{
//		if (grid[x][y] == '0')
//			return;
//
//		books[x][y] = true;
//
//		static int pos[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = pos[i][0] + x;
//			int ny = pos[i][1] + y;
//
//			if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size())
//				continue;
//			if (books[nx][ny] == false)
//			DFS(grid, books, nx, ny);
//		}
//	}
//	int numIslands(vector<vector<char>>& grid) {
//		int count = 0;
//		if (grid.empty())
//			return count;
//		vector<vector<bool>> books(grid.size(), vector<bool>(grid[0].size(), false));
//
//		for (int i = 0; i < grid.size(); i++)
//		{
//			for (int j = 0; j < grid[0].size(); j++)
//			{
//				if (grid[i][j] == '1' && books[i][j] == false)
//				{
//					count++;
//					DFS(grid, books, i, j);
//				}
//			}
//		}
//		return count;
//	}
//};


class Solution {
public:

	int helper(vector<vector<int>>&grid, vector<vector<bool>>& books, int x, int y)
	{
	
		int sum = 0;
	
		books[x][y] = true;
		
		static int pos[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		for (int i = 0; i < 4; i++)
		{
			int nx = x + pos[i][0];
			int ny = y + pos[i][1];

			if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || books[nx][ny] == true  || grid[nx][ny] != 1)
				continue;
			sum += 1;
			sum += helper(grid, books, nx, ny);
			
		}
		return sum;

	}
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;
		vector<vector<bool>> books(grid.size(), vector<bool>(grid[0].size(), false));
		int max_ = 0;
		for (int i = 0; i <grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == 1 && books[i][j] == false)
				{
					/*int count = 0;
					helper(grid, books, i, j, count);
					max_ = max(max_,count );*/
					max_ = max(max_, helper(grid, books, i, j));
				}
			}
		}
		return max_;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> vvc = { { 1,0,1 }, {1,1,1 }, { 0,0,1 } };
	cout << s.maxAreaOfIsland(vvc) << endl;

	system("pause");

}