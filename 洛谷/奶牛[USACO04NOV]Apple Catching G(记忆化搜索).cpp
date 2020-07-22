#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

 // ��ţ[USACO04NOV]Apple Catching G ���仯����
const int N = 1e3 + 100;
const int M = 35;
int w;
int f[N][M];
int n, m;
int a[N];


int dfs(int u, int last, int w1)// ��ǰ��ʱ�䣬 �ϴε�λ�� w���ƶ��˶��ٴ�
{
	if (f[u][w] != 0)
		return f[u][w];
	if (u > n) return 0;
	if (w1 > w) return 0;

	int res = 0; // ��ʵ���� f[u][w1] ��ǰ��ʱ�� �ƶ��Ĵ���
	if (a[u] == last) // ��ʱ��a[u] == last
	{
		res = dfs(u + 1, a[u], w1) + 1;  // �����ƶ�
	}
	else //��ʱ��a[u] != last   �ϴ�λ�������λ�ò�ͬ
	{
		// �ϴ������λ�ò�ͬ ���ƶ�
		res = dfs(u + 1, last, w1);
		// ��ν�ƻ���� �ƶ���
		if (w1 < w)
			res = max(res, dfs(u + 1, a[u], w1 + 1) + 1);
	}
	f[u][w1] = res;
	return res;

}
int main()
{
	cin >> n >> w;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	cout << dfs(1, 1, 0) << endl;



}

