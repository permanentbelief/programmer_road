#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 205;

int n, k;           // n Ϊͼ�е�����k Ϊͼ�б���
int total;          // ��ͼ�����бߵ�Ȩֵ�ܺ�
int g[N][N];        // prim ��ͼ�õ��ڽӾ���
vector<int> dcc[N]; // �����е���ͨ��
int dcc_cnt;        // ����ͨ�������
int dist[N];        // prim �浽ÿ��������ľ����õ� dist
bool st[N];         // һ�� st ���ã�����������ͨ�飬���� prim ����ÿ�����Ƿ�����������

void dfs(int u)     // dfs ������е���ͨ��
{
	st[u] = true;   // �Ƚ� u �Ƴ� true����ʾ�Ѿ�����������ͨ������
	dcc[dcc_cnt].push_back(u); // ���� u �������ͨ��
	for (int i = 1; i <= n; i++) // �� 1 �� n ö�����е�
	if (g[u][i] < 0x3f3f3f3f && !st[i]) // ����õ� i �ܴ� u �߹�ȥ����û����������ͨ����
		dfs(i); // ��ô������ i
}

int prim(int u)     // prim ����ͨ�� u �е���С������
{
	int res = 0;    // res ��¼�������Ĵ�С
	memset(dist, 0x3f, sizeof dist); // �� dist ��Ϊ������
	memset(st, false, sizeof st);    // ����Ҫ���ʹ�� st������ÿ��Ҫ�Ƚ� st �Ƴ� false
	for (int i = 0; i < dcc[u].size(); i++) // ��չ dcc[u].size() ��
	{
		int t = -1;
		for (int j = 0; j < dcc[u].size(); j++) // ö��һ�µ�ǰ��ͨ�� u �����е�
		{
			int ver = dcc[u][j];                  // ���õ�ȡ��
			if (!st[ver] && (t == -1 || dist[t] > dist[ver])) // ����õ㲻�����������ҵ��õ�ľ�����ڵ��� t �ľ���
				t = ver;                          // ��ô�ý� t ��Ϊ�õ�
		}
		if (i) res += dist[t];                    // res ���ϵ������������о�������ĵ㵽�����������ľ���
		st[t] = true;                             // ���õ� t ��������������
		for (int j = 0; j < dcc[u].size(); j++) // ���µ�ǰ��ͨ�������е�
		{
			int ver = dcc[u][j];                  // ���õ�ȡ��
			dist[ver] = min(dist[ver], g[t][ver]);// ���¸õ����
		}
	}
	return res;     // ���ظ��������Ĵ�С
}

int main()
{
	scanf("%d%d", &n, &k);
	memset(g, 0x3f, sizeof g); // ��ͼ�����бߵľ����ʼ��Ϊ������
	for (int i = 0; i < k; i++) // ����ͼ
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = min(g[a][b], c);
		total += c;
	}
	for (int i = 1; i <= n; i++) // ö�����е㣬����ͨ��
	if (!st[i])                // ����õ�û�м������е��κ���ͨ��
	{
		dcc_cnt++;           // ��ô����һ���µ���ͨ��
		dfs(i);                // ���õ㼰�õ��ܵ������е�����½�����ͨ��
	}
	for (int i = 1; i <= dcc_cnt; i++) // ö��������ͨ�飬���������ͨ�����С������
		total -= prim(i);          // ��Ȩֵ�ͼ�ȥ����С�������Ĵ�С
	printf("%d\n", total);         // ���ʣ�µ�Ȩֵ��
	return 0;
}
