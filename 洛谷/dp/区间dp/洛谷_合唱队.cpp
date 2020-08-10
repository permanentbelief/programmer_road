#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


using namespace std;

#define MOD 19650827
int f[1100][1100][2];

int n;
int a[1100];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[i][i][0] = 1;
	}


	for (int l = 2; l <= n; l++)
	{
		for (int i = 1; i + l - 1 <= n; i++)
		{
			int j = i + l - 1;
			if (a[j] > a[j - 1])
				f[i][j][1] += f[i][j - 1][1];
			if (a[j] > a[i])
				f[i][j][1] += f[i][j - 1][0];
			if (a[i] < a[i + 1])
				f[i][j][0] += f[i + 1][j][0];
			if (a[i] < a[j])
				f[i][j][0] += f[i + 1][j][1];

			f[i][j][0] %= MOD;
			f[i][j][1] %= MOD;
		}
	}
	cout << (f[1][n][0] + f[1][n][1]) % MOD;
}