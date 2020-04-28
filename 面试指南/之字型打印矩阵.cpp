#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


//
//void PrintEdge(vector<vector<int>>& ret, int leftupx, int leftupy, int rightdownx, int rightdowny)
//{
//	if (leftupx == rightdownx)
//	{
//		cout << ret[leftupx][leftupy] << " ";
//		leftupx++;
//	}
//	else if (leftupy == rightdowny)
//	{
//		cout << ret[leftupx][leftupy] << " ";
//		leftupy++;
//	}
//	else
//	{
//		int curR = leftupx;
//		int curY = leftupy;
//		while (curY != rightdownx)
//		{
//			cout << ret[leftupx][curY] << " ";
//			curY++;
//		}
//		while (curR != rightdownx)
//		{
//			cout << ret[curR][rightdowny] << " ";
//			curR++;
//		}
//		while (curY != leftupy)
//		{
//			cout << ret[rightdownx][curY] << " ";
//			curY--;
//		}
//		while (curR != leftupx)
//		{
//			cout << ret[curR][leftupy] << " ";
//			curR--;
//		}
//	}
//}
//
//int main()
//{
//	int m = 0;
//	int n = 0;
//	cin >> m >> n;
//	vector<vector<int>> v(m, vector<int>(n));
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> v[i][j];
//		}
//	}
//
//	int leftupx = 0;
//	int leftupy = 0;
//	int rightdownx = m - 1;
//	int rightdowny = n - 1;
//	while (leftupx <= rightdownx && leftupy <= rightdowny)
//	{
//		PrintEdge(v, leftupx++, leftupy++, rightdownx--, rightdowny--);	
//	
//	}
//	
//
//	system("pause");
//}

int i = 1;
void PrintEdge(vector<vector<int>>& ret, int leftupx, int leftupy, int rightdownx, int rightdowny)
{
	if (leftupx == rightdownx)
	{
		for (int j = leftupy; j <= rightdowny; j++)
		{
			i++;
			cout << i << " ";
		}

		
		
	}
	else if (leftupy == rightdowny)
	{
		for (int j = leftupx; j <= rightdownx; j++)
		{
			i++;
			cout << i << " ";
		}

	}
	else
	{
		int curR = leftupx;
		int curY = leftupy;
		while (curY != rightdowny)
		{
			
			cout << i << " ";
			i++;
			curY++;
		}
		while (curR != rightdownx)
		{
			
			cout <<i << " ";
			i++;
			curR++;
		}
		while (curY != leftupy)
		{
			
			cout <<i << " ";
			i++;
			curY--;
		}
		while (curR != leftupx)
		{
			
			cout << i<< " ";
			i++;
			curR--;
		}
	}
}

//int main()
//{
//	int m = 0;
//	int n = 0;
//	cin >> m >> n;
//	vector<vector<int>> v(m, vector<int>(n));
//
//	int leftupx = 0;
//	int leftupy = 0;
//	int rightdownx = m - 1;
//	int rightdowny = n - 1;
//	while (leftupx <= rightdownx && leftupy <= rightdowny)
//	{
//		PrintEdge(v, leftupx++, leftupy++, rightdownx--, rightdowny--);
//
//	}
//	system("pause");
//}


void PrintLevel(vector<vector<int>>& matrix, int tR, int tC, int dR, int dC, bool f)
{
	if (f)
	{
		while (tR != dR + 1)
		{
			cout << matrix[tR++][tC--] << " ";
		}
	}
	else
	{
		while (dR != tR - 1)
		{
			cout << matrix[dR--][dC++] << " ";
		}
	}
}

void Print(vector<vector<int>>& matrix)
{
	int tR = 0;
	int tC = 0;
	int dR = 0;
	int dC = 0;
	int endR = matrix.size() - 1;
	int endC = matrix[0].size() - 1;
	bool fromUp = false;
	while (tR != endR + 1)
	{
		PrintLevel(matrix,tR,tC,dR,dC, fromUp);
		tR = tC == endC ? tR + 1 : tR;
		tC = tC == endC ? tC : tC + 1;
		dC = dR == endR ? dC + 1 : dC;
		dR = dR == endR ? dR : dR + 1;
		fromUp = !fromUp;
	}
	cout << endl;
}
int main()
{
	vector<vector<int>>matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
	Print(matrix);
	system("pause");
}