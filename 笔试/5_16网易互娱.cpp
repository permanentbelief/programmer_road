#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//int main()
//{
//	int N = 0;
//	cin >> N;
//	string str;
//	vector<string> vs(N);
//	getchar();
//	for (int i = 0; i < N; i++)
//	{
//		getline(cin, str);
//		vs[i] = str;
//	}
//	
//	vector<vector<pair<int, int>>> vp(N);
//	for (int i = 0; i < vs.size(); i++)
//	{
//		vector<int> v;
//		
//		for (int j = 2; j < vs[i].size(); j++)
//		{
//			int sum = 0;
//			while (j < vs[i].size() && vs[i][j] != ' ')
//			{
//				sum = sum * 10 +  (vs[i][j] - '0');
//				j++;
//			}
//			v.push_back(sum);
//		}
//		for (int k = 0; k < v.size(); k+= 2)
//		{
//			vp[i].push_back(make_pair(v[k],v[k+1]));
//		}
//	}
//
//	int sum = 0;
//	cin >> sum;
//	vector<int> vsum(sum);
//	for (int k = 0; k < sum; k++)
//	{
//		cin >> vsum[k];
//		int a = vsum[k];
//		int max_ = 0;
//		int max_index = 1;
//		for (int i = 0; i < vp.size(); i++)
//		{
//			for (int j = 0; j < vp[i].size()- 1; j++)
//			{
//				if (a < vp[i][j].second)
//				{
//					if ((vp[i ][j].second - a)*vp[i][j].first > max_)
//					{
//						max_ = (vp[i][j].second - a)*vp[i][j].first;
//						max_index = vs[i][0];
//					}
//				}
//			}
//		}
//		cout << max_index << endl;
//	}
//
//	
//	system("pause");
//}

/*
1
3 0 50 1 1 10000 2

for (int i = 0; i < vs.size(); i++)
{
vector<pair<int, int>> ap;
for (int j = 2; j < vs[i].size(); j++)
{

int count = 0;
int a = 0;
int b = 0;
while (j < vs[i].size() && count != 2)
{
if (count != 2 && vs[i][j] != ' ')
{
if (count == 0)
{
a = vs[i][j] - '0';
count++;
}
else
{
b = vs[i][j] - '0';
count++;
}
}
j++;
}

ap.push_back(make_pair(a,b));
}
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//小球 乌龟赛跑
using namespace std;

int main()
{
	int Q = 0;
	cin >> Q;
	while (Q--)
	{
		int n = 0;
		int m = 0;
		cin >> n >> m;
		vector<vector<int>> vv(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
		{
			vv[i][0] = vv[i][m - 1] = 1;
		}
		for (int i = 0; i < m; i++)
		{
			vv[0][i] = vv[n - 1][i] = 1;
		}
		int X = 0;
		int Y = 0;
		int W = 0;
		int Z = 0;
		cin >> X >> Y >> W >> Z;
		X = X - 1;
		Y = Y - 1;
		//vv[X][Y] = 2;
		int tmp = 2;
		for (int i = 0; i < Z; i++)
		{
			if (W == 0) // 左上方  X - 1 , Y - 1
			{
				//X -= 1;
				//Y -= 1;
				if (X  - 1 == 0 && Y - 1 == 0)
					tmp += 2, W = 2;
				else if (Y - 1 == 0 && X - 1 != 0)
					tmp++,W = 3;
				else if (X - 1 == 0 && Y - 1 != 0)
					tmp++, W = 1;
				else
				{
					X -= 1;
					Y -= 1;
					continue;
				}
					

			}
			else if (W == 1)  // 右上方 X - 1 Y + 1
			{
				//X -= 1;
				//Y += 1;
				if (X - 1== 0 && Y + 1 == m - 1)
					tmp += 2, W = 3;
				else if (Y + 1== m  && X - 1 != 0)
					tmp++, W = 0;
				else if (X  - 1== 0 && Y + 1 != m - 1)
					tmp++, W = 2;
				else
				{
					X -= 1;
					Y += 1;
					continue;
				}
					

			}
			else if (W == 2)// 右下方  X + 1 Y + 1
			{

				if (X  + 1== n - 1 && Y + 1== m - 1)
					tmp += 2, W = 0;
				else if (Y + 1 == m - 1 && X + 1!= n - 1)
					tmp++, W = 1;
				else if (X +1 == n - 1 && Y + 1!= m - 1)
					tmp++, W = 3;
				else
				{
					X += 1;
					Y += 1;
					continue;
				}
					

			}
			else if (W == 3) //左下方 X + 1 Y - 1
			{

				if (X + 1== n - 1 && Y - 1== 0)
					tmp += 2, W = 1;
				else if (Y - 1 == 0 && X + 1!= n - 1)
					tmp++, W = 2;
				else if (X + 1 == n - 1 && Y - 1 != 0)
					tmp++, W = 0;
				else
				{
					X += 1;
					Y -= 1;
					continue;

				}

			}
		
		}
		cout << tmp << endl;
	}
	system("pause");
}

/*

5
6 5
4 3 0 42
10 6
5 3 1 46
5 5
3 3 1 7
5 5
3 3 1 6
7 7
4 5 2 9
*/