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

	//ǰ׺��
	deque<int> dq;

	int ans = 0; // ����
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
		//�������е���Сֵÿһ�μ�ȥ ��ͷ���ݵ�ֵ���жϴ� i-n λ�ó�����n����
		//����С���� front() ��ȥ ��ͷ�������Ƿ���ڵ��� 0
		if (i - n + 1 > 0 && a[dq.front()] - a[i - n] >= 0)
			ans++;
	}
	cout << ans << endl;

}
