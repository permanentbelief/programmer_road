#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


using namespace std;


const int N = 2e6 + 200;


int a[N];
int f[N];
int n;
int m;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i + n] = a[i];
	}
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		a[i] += a[i - 1];
	}

	//前缀和
	deque<int> dq;

	int ans = 0; // 计数
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		while (dq.size() && i - dq.front() > n)
		{
			// ans++;
			dq.pop_front();
		}
		while (dq.size() && a[dq.back()] >= a[i])
			dq.pop_back();
		dq.push_back(i);
		//将队列中的最小值每一次减去 队头数据的值，判断从 i-n 位置出发的n个数
		//中最小的数 front() 减去 队头的数据是否大于等于 0
		if (i - n + 1 > 0 && a[dq.front()] - a[i - n] >= 0)
			ans++;
	}
	cout << ans << endl;

}
