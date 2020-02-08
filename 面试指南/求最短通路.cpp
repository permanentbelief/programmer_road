#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


void Walkto(int prev, int toR, int toC, vector<vector<int>>& m,vector<vector<int>>& map, queue<int>& rQ,
	queue<int>& cQ)
{
	if (toR < 0 || toR == m.size() || toC < 0 || toC == m[0].size() || m[toR][toC] != 1 || map[toR][toC] != 0)
	{
		return;
	}
	map[toR][toC] = prev + 1;
	rQ.push(toR);
	cQ.push(toC);
}

int minPathValue(vector<vector<int>> m)
{
	int row = m.size();
	int col = m[0].size();
	queue<int> rQ;
	queue<int> cQ;
	int res = 0;
	vector<vector<int>> map(row, vector<int>(col,0));
	map[0][0] = 1;
	rQ.push(0);
	cQ.push(0);
	while (!rQ.empty())
	{
		int r = rQ.front();
		int c = cQ.front();
		rQ.pop();
		cQ.pop();
		if ( r == m.size() - 1  && c == m[0].size() - 1)
			return map[r][c];
		Walkto(map[r][c],r-1,c,m,map,rQ,cQ);
		Walkto(map[r][c], r+1, c, m, map, rQ, cQ);
		Walkto(map[r][c], r, c+1, m, map, rQ, cQ);
		Walkto(map[r][c], r, c-1, m, map, rQ, cQ);
	}
	return 0;
}


int main()
{
	vector<vector<int>> m{ { 1, 0, 1, 1, 1 }, { 1, 0, 1, 0, 1 }, { 1, 1, 1, 0, 1 }, { 1, 1, 1, 1, 1 } };
	cout << minPathValue(m) << endl;

	system("pause");
}