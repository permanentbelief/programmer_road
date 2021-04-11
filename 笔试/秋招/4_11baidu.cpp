//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//#include <unordered_set>
//using namespace std;
//
////
////#include <bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 100;
//int n, m;
//int f[N];
//int d[N];
//char op;
//int x, y;
//
//void init(){
//	for (int i = 1; i < N; i++){
//		f[i] = i;
//		d[i] = 1;
//	}
//}
//int find(int x){
//	if (x == f[x])
//		return x;
//	return f[x] = find(f[x]);
//}
//void add(int x, int y){
//	int u = find(x);
//	int v = find(y);
//	f[v] = u;
//}
//int query(int x, int y){
//	int u = find(x);
//	int v = find(y);
//	if (f[u] == f[v])
//		return 1;
//	return -1;
//}
//int main(){
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++){
//		f[i] = i;
//	}
//	vector<int> v;
//	for (int i = 1; i <= m; i++){
//		cin >> op >> x >> y;
//		if (op == 'C'){
//			add(x, y);
//		}
//		else{
//			v.push_back(query(x, y), d[x] - d[y]);
//		}
//	}
//	for (int i = 0; i < v.size(); i++){
//		cout << v[i] << endl;
//	}
//	system("pause");
//}
//
//
//
///*
//aaca
//caaa
//2
//
//2
//
//
//"aaca" - "aaac" - "caaa"
//"aaca" - "acaa" - "caaa"
//*/
//
//
//string s, t;
//unordered_set<string> us;
//int k;
//int main(){
//	cin >> s;
//	cin >> t;
//	cin >> k;
//	queue<string> q;
//	int n = s.size();
//	int count = 0;
//
//	us.insert(s);
//	q.push(s);
//	int cnt = 0;
//	while (q.size()){
//		int sz = q.size();
//		while (sz--){
//			auto ttop = q.front();
//			q.pop();
//		/*	if (ttop == t && count == k ){
//				cnt++;
//				continue;
//			}*/
//			string tmp = ttop;
//
//			for (int i = 0; i < ttop.size(); i++){
//				string ss = tmp;
//				reverse(tmp.begin(), tmp.end());
//				reverse(tmp.begin() + i, tmp.end());
//				reverse(tmp.begin(), tmp.begin() + i);
//				if(ttop != t && count == k - 1 && tmp == t)
//					cnt++;
//				if (!us.count(tmp)){
//					q.push(tmp);
//						us.insert(tmp);
//				}
//				tmp = ss;
//			}
//		}
//
//		count++;
//		if (count >= k)
//			break;
//	}
//	cout << cnt << endl;
//	system("pause");
//}
//
//
////
//
//
//int main()
//{
//	cin >> T;
//	while (T--){
//		cin >> n >> m;
//		for (int i = 1; i <= n; i++){
//			cin >> a[i];
//		}
//		for (int i = 1; i <= m; i++){
//			cin >> b[i];
//		}
//		sort(b + 1, b + m + 1);
//		for (int i = 1; i <= n; i++){
//			int rw = upper_bound(b + 1, b + 1 + m, a[i]) - b;
//			cout << m - rw  + 1<< " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//}
//
//
////using namespace std;
////
////
//
//int main()
//{
//	int T = 0;
//	int n, m = 0;
//	cin >> T;
//	while (T--){
//		int a[1200];
//		int b[1200];
//		memset(a, 0, sizeof(a));
//		memset(b, 0, sizeof(b));
//		cin >> n >> m;
//		for (int i = 1; i <= n; i++){
//			cin >> a[i];
//		}
//		for (int i = 1; i <= m; i++){
//			cin >> b[i];
//		}
//		vector<int> v;
//		//sort(b + 1, b + m + 1);
//		for (int i = 1; i <= n; i++){
//			int cnt = 0;
//			for (int j = 1; j <= m; j++){
//				if (b[j] > a[i]){
//					cnt++;
//				}
//			}
//			v.push_back(cnt);
//		}
//		for (int i = 0; i < v.size() - 1; i++){
//			cout << v[i] << " ";
//		}
//		cout << v[v.size() - 1] << endl;
//		
//	}
//	system("pause");
//}
//
//
//
//
///*
//#include <bits/stdc++.h>
//using namespace std;
//
//
//const int N = 1000 + 200;
//
//int main()
//{
//int T = 0;
//int n,m = 0;
//cin >> T;
//while (T--){
//vector<int> a;
//vector<int> b;
//cin >> n ;
//cin >> m;
//a.resize(n);
//b.resize(m);
//for (int i = 0; i < n; i++){
//cin >> a[i];
//}
//for (int i = 0; i < m; i++){
//cin >> b[i];
//}
//vector<int> v;
////sort(b + 1, b + m + 1);
//for (int i = 0; i < n; i++){
//int cnt = 0;
//for(int j = 0; j < m; j++){
//if(b[j] > a[i]){
//cnt++;
//}
//}
//v.push_back(cnt);
//}
//for(int i = 0; i < v.size() - 1; i++){
//cout << v[i] << " ";
//}
//cout << v[v.size() - 1] << endl;
//// cout << endl;
//}
//}
//
//
//
//*/
//
//
//
////#include <bits/stdc++.h>
//using namespace std;
//
//string s, t;
//unordered_set<string> us;
//int k;
//int main(){
//	cin >> s;
//	cin >> t;
//	cin >> k;
//	queue<string> q;
//	int n = s.size();
//	int count = 0;
//
//	us.insert(s);
//	q.push(s);
//	int cnt = 0;
//	while (q.size()){
//		int sz = q.size();
//		while (sz--){
//			auto ttop = q.front();
//			q.pop();
//			string tmp = ttop;
//			for (int i = 0; i < ttop.size(); i++){
//				string ss = tmp;
//				reverse(tmp.begin(), tmp.end());
//				reverse(tmp.begin() + i, tmp.end());
//				reverse(tmp.begin(), tmp.begin() + i);
//				if (ttop != t && count == k - 1 && tmp == t)
//					cnt++;
//				if (!us.count(tmp)){
//					q.push(tmp);
//					us.insert(tmp);
//				}
//				tmp = ss;
//			}
//		}
//		count++;
//		if (count >= k)
//			break;
//	}
//	cout << cnt % 10000000007 << endl;
//	//system("pause");
//}
//
//
//
