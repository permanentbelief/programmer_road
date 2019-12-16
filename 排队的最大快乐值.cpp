#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;
vector<int> G[500001];
vector<int> happy(500001);

pair<int, int> dfs(int root){
	int n = G[root].size();
	int res1 = 0, res2 = happy[root];
	//res1: ��ǰ��ȡ��ǰroot�����ֵ������Ա���Ƿ�μӾ���
	//res2: ȡ��ǰroot�����ֵΪ��ǰroot�Ŀ���ֵ+��ǰroot�����з�ֱ�������Ŀ���ֵ�����ֵ
	for (int i = 0; i < n; ++i){
		pair<int, int> res = dfs(G[root][i]);
		res1 += max(res.first, res.second);
		res2 += res.first;
	}
	return{ res1, res2 };
}
int main(){
	int n, root;
	scanf("%d %d", &n, &root);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &happy[i]);
	}
	for (int i = 0; i < n - 1; ++i){
		int u_i, v_i;
		scanf("%d %d", &u_i, &v_i);
		G[u_i].push_back(v_i);
	}
	pair<int, int> res = dfs(root);
	printf("%d", max(res.first, res.second));
	system("pause");
	return 0;
}
