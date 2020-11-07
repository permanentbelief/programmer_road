#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//单调栈_ 选择数字
typedef long long ll;
ll p[100010];
ll q[100010];
ll f[100010];
ll ans;
ll n, k;
ll d;
int main()
{
	deque<ll> dq;
	scanf("%lld %lld", &n, &k);

	dq.push_back(0); // 必须push_back(0), 要不然[0, k - 1] 取 f的时候，就会出错
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &q[i]);
		d = q[i];
		ans += d;                                                          // 1 2 3 4 5    k = 2
		// !     i
		f[i] = dq.front() + 1ll * d; // f[]是指 去掉f[i]时，所花费的多少，  f[i] = f[i] + f[i - k - 1] + f[i - 2k - 1] - ...; 
		while (dq.size() && dq.back() >= f[i])
		{
			dq.pop_back();
		}
		dq.push_back(f[i]);
		p[dq.back()] = i; // 不用记录 是否超过， dq.front()就是 记录了已经

		while (dq.size() && i - k > p[dq.front()])
		{
			dq.pop_front();
		}

	}
	long long s = 0;
	for (int i = n - k; i <= n; i++)
	{
		s = max(s, ans - f[i]);
	}
	printf("%lld\n", s);
}