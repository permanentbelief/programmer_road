//#define _CRT_SECURE_NO_WARNINGS 1 
//// //标准答案 回溯
////#include<iostream>
////#include<vector>
////using namespace std;
////int N, M; //分别代表行和列
////vector<vector<int>> maze;//迷宫矩阵
////vector<vector<int>> path_temp;//存储当前路径，第一维表示位置
////vector<vector<int>> path_best;//存储最佳路径
////void MazeTrack(int i, int j)
////{
////	maze[i][j] = 1;//表示当前节点已走，不可再走
////	path_temp.push_back({ i, j });//将当前节点加入到路径中
////	if (i == N - 1 && j == M - 1) //判断是否到达终点
////	if (path_best.empty() || path_temp.size() < path_best.size())
////		path_best = path_temp;
////
////	if (i - 1 >= 0 && maze[i - 1][j] == 0)//探索向上走是否可行
////		MazeTrack(i - 1, j);
////	if (i + 1 < N && maze[i + 1][j] == 0)//探索向下走是否可行
////		MazeTrack(i + 1, j);
////	if (j - 1 >= 0 && maze[i][j - 1] == 0)//探索向左走是否可行
////		MazeTrack(i, j - 1);
////	if (j + 1 < M && maze[i][j + 1] == 0)//探索向右走是否可行
////		MazeTrack(i, j + 1);
////	maze[i][j] = 0; //恢复现场，设为未走
////	path_temp.pop_back();
////}
////int main()
////{
////	while (cin >> N >> M)
////	{
////		maze = vector<vector<int>>(N, vector<int>(M, 0));
////		path_temp.clear();
////		path_best.clear();
////		for (auto &i : maze)
////		for (auto &j : i)
////			cin >> j;
////		MazeTrack(0, 0);//回溯寻找迷宫最短通路
////		for (auto i : path_best)
////			cout << '(' << i[0] << ',' << i[1] << ')' << endl;//输出通路
////	}
////	system("pause");
////	return 0;
////}
//// 我的 DFS
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void DFS(vector<vector<int>>& best_ret, vector<vector<int>>& ret, vector<vector<int>>& tmp, int x, int y
//	, int row, int col)
//{
//	ret[x][y] = 1; //标记此位置不能在进入递归序列，要不都一直循环着
//	tmp.push_back({ x, y });
//	if (x == row - 1 && y == col - 1) //判断是否到头 然后再看是否为最短的路径
//	{
//		if (best_ret.empty() || best_ret.size() < tmp.size())
//			best_ret = tmp;
//	}
//	static int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + pos[i][0];
//		int ny = y + pos[i][1];
//		if ( nx < 0 || nx >= row ||
//			ny < 0 || ny >= col || ret[nx][ny] == 1 )
//			continue;
//		DFS(best_ret, ret, tmp, nx, ny, row, col);
//		ret[x][y] = 0;
//		tmp.pop_back();
//	}
//
//}
//int main()
//{
//	int row = 0;
//	int col = 0;
//	while (cin >> row >> col)
//	{
//		vector<vector<int>> v(row, vector<int>(col, 0));
//		for (int i = 0; i < row; i++)
//		{
//			for (int j = 0; j < col; j++)
//			{
//				cin >> v[i][j];
//			}
//		}
//		vector<vector<int>> best_ret;
//		vector<vector<int>> tmp;
//		DFS(best_ret, v, tmp, 0, 0, row, col);
//		for (auto& e : best_ret)
//		{
//			cout << "(" << e[0] << "," << e[1] << ")" << endl;
//		}
//	}
//	system("pause");
//}
