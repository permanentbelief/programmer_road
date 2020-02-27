#define _CRT_SECURE_NO_WARNINGS 1 


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int DFS(int x, int y, int m, int n, int k)
{
	if (x >= m || y >= n || x == -1 || y == -1)
	{
		return 1;
	}
	if (k == 0 && x >= 0 && x < m && y >= 0 && y < n)
	{
		return 0;
	}

	int ans = 0;
		ans += DFS( x + 1, y, m, n, k-1);
		ans += DFS(x - 1, y, m, n, k-1);
		ans += DFS(x, y + 1, m, n, k-1);
		ans += DFS( x, y - 1, m, n, k-1);
		return ans;
}
int main()
{
	int m = 0;
	int n = 0;
	int x = 0;
	int y = 0;
	int K = 0;
	while (cin >> m >> n >> x >> y >> K)
	{
		
		cout << DFS(x, y, m, n, K) << endl;
	}
}