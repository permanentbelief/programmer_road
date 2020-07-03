#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



using namespace std;

const int M = 100003;
vector<int> E[M];
int indegree[M];

int main(){
	int n, m, u, v;
	cin >> n >> m;
	int r[20];
	for (int i = 0; i<m; i++){
		cin >> u >> v;
		E[v].push_back(u);
		indegree[u]++;
	}
	priority_queue<int> q;
	for (int i = 1; i <= n; i++)
	if (!indegree[i])
		q.push(i);
	int k = n;
	while (!q.empty()){
		int p = q.top();
		q.pop();
		r[p] = k--;
		for (int i = 0; i<E[p].size(); i++){
			v = E[p][i];
			indegree[v]--;
			if (indegree[v] == 0)
				q.push(v);
		}
	}
	for (int i = 1; i <= n; i++){
		if (i == n)
			cout << r[i] << endl;
		else
			cout << r[i] << " ";
	}
	return 0;
}