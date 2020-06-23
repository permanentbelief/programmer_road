#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


#include<bits/stdc++.h>
#define N 110
using namespace std;
struct node{
	int from, to, dis;
}e[N * 2];
int n, k, fa[N], ans, cnt, tot;
int find(int x)//���鼯��������
{
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
inline void merge(int x, int y)//���鼯��������
{
	fa[find(y)] = find(x);
}
bool rule(const node &x, const node &y)//����Ȩ��С��������
{
	return x.dis<y.dis;
}
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)//���鼯��ʼ��
		fa[i] = i;
	for (int i = 1; i <= k; i++){
		scanf("%d %d %d", &e[i].from, &e[i].to, &e[i].dis);
		if (!e[i].dis)//ע��:���������Ŀӵ�,��ȨΪ0�ı߲��ܼ���������
			i--, k--;
		ans += e[i].dis;
	}
	sort(e + 1, e + 1 + k, rule);
	for (int i = 1; i <= k; i++){//��³˹�����㷨����С������
		if (cnt == n - 1)
			break;
		int u = e[i].from, v = e[i].to;
		if (find(u) != find(v)){
			merge(u, v);
			tot += e[i].dis;
			cnt++;
		}
	}
	printf("%d\n", ans - tot);//������մ�
	return 0;
}

