#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>


using namespace std;
const int N = 300;
int a[N];
int f[2 * N][2 * N];

int n;
int main()
{
	cin >> n;

	//  2    3    5    10     2
	// 
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[n + i] = a[i];
	}
	for (int i = 2; i <= n + 1; i++)
	{
		for (int l = 1; l + i - 1 <= 2 * n; l++)
		{
			int r = l + i - 1;
			for (int k = l + 1; k <= r - 1; k++)
			{
				f[l][r] = max(f[l][r], f[l][k] + f[k][r] + a[l] * a[k] * a[r]);
			}
		}
	}
	int res = 0;
	// 1 2 3 1 2 3
	for (int i = 1; i <= n; i++) res = max(res, f[i][n + i]);
	cout << res << endl;
	return 0;
}