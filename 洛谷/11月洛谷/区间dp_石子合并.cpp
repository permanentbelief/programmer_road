#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int N = 150;
int f[N][N];
int fm[N][N];
int n;
int a[N];
int Sums[N];

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		Sums[i] = Sums[i - 1] + a[i];
		//cout << Sums[i] << " ";
	}
	//cout <<endl;


	for (int len = 2; len <= n; len++)
	{
		for (int i = 1; i + len - 1 <= n; i++)
		{

			int j = i + len - 1;
			// f[i][j] = 0x3f3f3f3f;
			fm[i][j] = 0xcfcfcfcf;
			for (int k = i; k < j; k++)
			{
				//f[i][j] = min(f[i][j],f[i][k] + f[k + 1][j] + Sums[j] - Sums[i - 1]);
				fm[i][j] = max(fm[i][j], fm[i][k] + fm[k + 1][j] + Sums[j] - Sums[i - 1]);
			}
		}
	}
	cout << fm[1][n] << endl;
}
