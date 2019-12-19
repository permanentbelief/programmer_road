#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>

#include <vector>
using namespace std;

// 值得注意的是 题目中的 row和col是格子数 ，不是路线数
int main()
{
	int row = 0;
	int col = 0;
	while (cin >> row >> col)
	{

		vector<vector<int>> Max_M(row + 1, vector<int>(col + 1, 1));
		if (Max_M.empty())
		{
			cout << 0 << endl;
			return 0;
		}
		for (int i = 1; i < row + 1; i++)
		{
			for (int j = 1; j < col + 1; j++)
			{
				Max_M[i][j] = Max_M[i - 1][j] + Max_M[i][j - 1];
			}
		}
		cout << Max_M[row][col] << endl;
	}
	system("pause"); 
}