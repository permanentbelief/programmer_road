#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int N = 1e4;
int f[N];
int d[N];
void init(){
	for (int i = 1; i < N; i++) f[i] = i;
}
int find(int x){
	if (x == f[x])
		return x;
	return
		f[x] = find(f[x]);
}
void add(int a, int b){
	int u = find(a);
	int v = find(b);
	f[u] = v;
}

int main(){
	int n;
	int m;
	init();
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		char op = ' ';
		int a, b;
		cin >> op >> a >> b;
		if (op == 'E'){
			if (d[a]){
				add(d[a], b);
			}
			else{
				d[a] = b;
			}
			if (d[b]){
				add(d[b], a);
			}
			else{
				d[b] = a;
			}
		}
		else{
			add(a, b);
		}

	}
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (f[i] == i)
			cnt++;
	}
	cout << cnt << endl;
	system("pause");
}





//struct data{
//	int x, y, z;
//};
//data f[100005];
//
//int n, m, a[20005], b[20005];
//int i;
//bool cmp(data a, data b){
//	return a.z > b.z;
//}
//
//inline int find(int x)
//{
//	if (a[x] == x) return x;
//	a[x] = find(a[x]);
//	return a[x];
//}
//inline void ad(int x, int y)//合并
//{
//	x = find(a[x]);
//	y = find(a[y]);
//	a[x] = y;
//}
//inline bool check(int x, int y)//查找
//{
//	x = find(x);
//	y = find(y);
//	if (x == y) return true;
//	return false;
//}
//
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for (i = 1; i <= n; i++) a[i] = i;
//	for (i = 1; i <= m; i++)
//		scanf("%d%d%d", &f[i].x, &f[i].y, &f[i].z);
//	sort(f + 1, f + m + 1, cmp);//c党的优越感~
//	for (i = 1; i <= m + 1; i++)//为什么m+1呢？如果运行到m+1会输出0，想想为什么。
//	{
//		if (check(f[i].x, f[i].y)) { printf("%d", f[i].z); break; }//如果两个罪犯已经在同一监狱就输出 ，并退出
//		else
//		{
//			if (!b[f[i].x]) b[f[i].x] = f[i].y;//标记“敌人”
//			else { ad(b[f[i].x], f[i].y); }//将敌人的敌人合并
//			if (!b[f[i].y]) b[f[i].y] = f[i].x;
//			else { ad(b[f[i].y], f[i].x); }
//		}
//	}
//	return 0;
//}