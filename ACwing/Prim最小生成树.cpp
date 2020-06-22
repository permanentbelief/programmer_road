#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;

const int INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim()
{
	memset(dist, 0x3f, sizeof dist); //!!!!!!!!!!!!!!���о����ʼ��Ϊ������

	int res = 0;  //��С���������бߵľ���֮��
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)  //�ҵ���ǰ����������е㵱�о�����С�ĵ�
		{
			if (!st[j] && (t == -1 || dist[t] > dist[j]))// j�㻹�ڼ����⣬���߻�û���ҵ���dist[t]>dist[j]
			{
				t = j; // t��ʱ���Ǿ�����С�ĵ��ˡ�
			}
		}
		if (i && dist[t] == INF) //˵�����ǵ�һ���㣬�ҵ�ǰ�����Ҽ�������ĵ� ����Ϊ���������ͨ��
			return INF;


		if (i) res += dist[t]; //ֻҪ���ǵ�һ���ߣ��Ͱѱ߼ӵ�������ȥ

		//���Ի������ۼӣ��ڸ��¡�

		for (int j = 1; j <= n; j++)
		{
			dist[j] = min(dist[j], g[t][j]);
		}


		st[t] = true;
	}
	return res;
}


int main()
{
	scanf("%d%d", &n, &m);
	memset(g, 0x3f, sizeof g);

	while (m--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = min(g[a][b], c);
	}
	int t = prim();
	if (t == INF)
		puts("impossible");
	else
		printf("%d\n", t);
	system("pause");
	return 0;
}