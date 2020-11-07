#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//����ջ_ ѡ������
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

	dq.push_back(0); // ����push_back(0), Ҫ��Ȼ[0, k - 1] ȡ f��ʱ�򣬾ͻ����
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &q[i]);
		d = q[i];
		ans += d;                                                          // 1 2 3 4 5    k = 2
		// !     i
		f[i] = dq.front() + 1ll * d; // f[]��ָ ȥ��f[i]ʱ�������ѵĶ��٣�  f[i] = f[i] + f[i - k - 1] + f[i - 2k - 1] - ...; 
		while (dq.size() && dq.back() >= f[i])
		{
			dq.pop_back();
		}
		dq.push_back(f[i]);
		p[dq.back()] = i; // ���ü�¼ �Ƿ񳬹��� dq.front()���� ��¼���Ѿ�

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