#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

using namespace std;

const int N = 12;
const int M = 1 << N;
long long f[N][M];
int st[M];

int main()
{
	int n = 0;
	int m = 0;

	while (cin >> n >> m && (n || m))
	{
		for (int i = 0; i < 1 << n; i++)
		{
			int cnt = 0;
			st[i] = true;
			for (int j = 0; j < n; j++)
			{
				if (i >> j & 1)
				{
					if (cnt & 1)
						st[i] = false; //cnt 为当前已经存在多少个连续的0
					cnt = 0;
				}
				else
					cnt++;
			}

			if (cnt & 1) st[i] = false; //扫描完之后判断一下最后一段有多少个连续的0
		}

		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 0; j < 1 << n; j++)
			{
				for (int k = 0; k < 1 << n; k++)
				{
					if ((j & k) == 0 && (st[j | k]))
						f[i][j] += f[i - 1][k];
				}
			}
		}
		cout << f[m][0] << endl;
	}
	return 0;
}