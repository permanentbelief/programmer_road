//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include<iostream>
//#include<vector>
//#include <queue>
//using namespace std;
//int main()
//{
//	int row = 0;
//	int col = 0;
//	vector<vector<int>> best_ret;
//	vector<vector<int>> ret;
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
//		queue<pair<int, int>> q;
//		q.push(make_pair(0, 0));
//		static int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
//		while (!q.empty())
//		{
//			auto top = q.front();
//			v[top.first][top.second] = 1;
//			q.pop();
//			ret.push_back({ top.first, top.second });
//			if (top.first == row - 1 || top.second == col - 1)
//			{
//				if (best_ret.empty() || best_ret.size() < ret.size())
//					best_ret = ret;
//			}
//			for (int i = 0; i < 4; i++)
//			{
//				int nx = top.first + pos[i][0];
//				int ny = top.second + pos[i][1];
//				if (nx < 0 || nx >= row || ny < 0 ||
//					ny >= col || v[nx][ny] == 1)
//					continue;
//				else
//				{
//					q.push(make_pair(nx, ny));
//				}
//			}
//			v[top.first][top.second] = 0;
//		
//		}
//		for (auto & e : best_ret)
//		{
//			cout << "(" << e[0] << "," << e[1] << ")" << endl;
//		}
//
//	}
//	system("pause");
//}