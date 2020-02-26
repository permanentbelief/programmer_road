#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<vector<int>> vvi(4);
		int row = 0;
		int col = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int temp = 0;
				cin >> temp;
				vvi[i].push_back(temp);
			}
		}
		vector<pair<int, int>> leftdown;
		vector<pair<int, int>> rightup;
		for (int i = 0; i < n; i++)
		{
			leftdown.push_back(make_pair(vvi[0][i], vvi[1][i]));
			rightup.push_back(make_pair(vvi[2][i], vvi[3][i]));
		}
		int maxrow = rightup[0].first;
		int maxcol = rightup[0].second;
		int minrow = leftdown[0].first;
		int mincol = leftdown[0].second;
		for (auto it = leftdown.begin(); it != leftdown.end(); it++)
		{
			minrow = min(minrow, it->first);
			mincol = min(minrow, it->second);
		}
		for (auto it = rightup.begin(); it != rightup.end(); it++)
		{
			maxrow = max(maxrow, it->first);
			maxcol = max(maxrow, it->second);
		}
		int m = maxrow - minrow + 1;
		int k = maxcol - mincol + 1;
		vector<vector<int>> vv(m, vector<int>(k, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = leftdown[i].first; j < rightup[i].first; j++)
			{
				for (int o = leftdown[i].second; o < rightup[i].second; o++)
				{
					vv[j][o]++;
				}
			}
		}
		for (auto iter = rightup.begin(); iter != rightup.end(); iter++)
		{
			for (auto it = leftdown.begin(); it != leftdown.end(); it++)
			{
				if (iter->first == it->first && it->second == iter->second)
				{
					vv[it->first][it->second]--;
				}
			}
		}
		int count = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < k; j++)
			{
				count = max(count, vv[i][j]);
			}
		}
		cout << count << endl;
	}
}