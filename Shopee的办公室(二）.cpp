#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//using namespace std;
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int n = 0;
//	cin >> x >> y >> n;
//	vector<vector<int>> vv(x + 1, vector<int>(y + 1, 0));
//	vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
//	for (int i = 0; i < n; i++)
//	{
//		int a = 0;
//		int b = 0;
//		cin >> a >> b;
//		vv[x - a][b] = 1; //ÏÝÚå
//	}
//	for (int i = 0; i < vv[0].size(); i++)
//	{
//		if (vv[x][i] == 0)
//		{
//			dp[x][i] = 1;
//		}
//		else
//		{
//			//Îª1ÊÇÏÝÚå
//			break;
//		}
//	}
//	for (int i = x; i >= 0; i--)
//	{
//		if (vv[i][0] == 0)
//		{
//			dp[i][0] = 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//	for (int i = x - 1; i >= 0; i--)
//	{
//		for (int j = 1; j <= y; j++)
//		{
//			if (vv[i][j] == 1)
//			{
//				dp[i][j] = 0;
//				continue;
//			}
//			else
//			{
//				dp[i][j] = dp[i + 1][j] + dp[i][j - 1];
//			}
//		}
//	}
//	cout << dp[0][y] << endl;
//	system("pause");
//
//}