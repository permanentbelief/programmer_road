//#define _CRT_SECURE_NO_WARNINGS 1 
//
//
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <climits>
//#include <queue>
//#include <unordered_map>
//#include <cmath>
//using namespace std;
//
//typedef long long ll;
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <climits>
//
//
//using namespace std;
//
//typedef long long ll;
//const int N = 1e5 + 30;
//ll n, m;
//
//int a[N];
//
//
//bool check(ll mid) //和 m比 因为去掉的是m个
//{
//	ll sum = 0;
//	int ans = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		if (sum + a[i] > mid)
//		{
//			ans++;
//			sum = a[i];
//		}
//		else
//		{
//			sum += a[i];
//		}
//	}
//
//	return ans <= m;  //分的组少于 或者刚好的话
//}
//
//int main()
//{
//	cin >> n >> m;
//	ll r = 0;
//	ll l = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//		r += a[i];
//		l = max((ll)a[i], l);
//
//	}
//	int ans = 0;
//	while (l <= r)
//	{
//		int mid = (l + r) / 2;
//		if (check(mid))
//		{
//			r = mid - 1;
//		}
//		else
//		{
//			l = mid + 1;
//		}
//	}
//
//	cout << l << endl;
//
//	system("pause");
//}
//
//
//
//// 砍树的正确代码
////const int N = 1e6 + 30;
////
////priority_queue<int> pq;
////ll m, n;
////
////ll a[N];
////int ans = 0;
////bool check(ll mid)
////{
////	ll sum = 0;
////	for (int i = 1; i <= n; i++)
////	{
////		if (a[i] > mid)
////		{
////			sum += a[i] - mid;
////		}
////	}
////	return sum >= m;
////}
////
////int main()
////{
////		cin >> n >> m;
////		ll r = 1;
////		for (int i = 1; i <= n; i++)
////		{
////			cin >> a[i];
////			r = max(a[i], r);
////		}
////	
////		ll l = 1;
////		
////		while (l <= r)
////		{
////			ll mid = (l + r) / 2;
////			if (check(mid))
////			{
////				ans = mid;
////				l = mid + 1;
////			}
////			else
////			{
////				r = mid - 1;
////			}
////		}
////		cout << ans << endl;
////		system("pause");
////		return 0;
////} 
//
//// 砍树 求最大值 模板过不去  r = mid 的模板过不去
//
////bool check(ll mid)
////{
////	ll sum = 0;
////	for (int i = 1; i <= n; i++)
////	{
////		if (a[i] > mid)
////		{
////			sum += a[i] - mid;
////		}
////	}
////	return sum > m;
////}
////
////int main()
////{
////	cin >> n >> m;
////	ll r = 1;
////	for (int i = 1; i <= n; i++)
////	{
////		cin >> a[i];
////		r = max(a[i], r);
////	}
////
////	ll l = 1;
////	
////	while (l < r)
////	{
////		ll mid = (l + r) / 2;
////		if (check(mid))
////		{
////			l = mid + 1;
////		}
////		else
////		{
////			r = mid;
////		}
////	}
////	cout << l << endl;
////	system("pause");
////	return 0;
////
////}
//
//
//
////const int N = 1e5 + 50;
////double a[N];
////int n, m;
////char s[100];
////
////
////bool check(double mid)
////{
////	int ans = 0;
////	for (int i = 1; i <= n; i++)
////	{
////		ans += int(a[i] / mid);
////	}
////	return  ans >= m;
////}
////int main()
////{
////	cin >> n >> m;
////
////	double l = 0.0;
////	double r = 0.0;
////	for (int i = 1; i <= n; i++)
////	{
////		cin >> a[i];
////		
////		r = max(r, a[i]);
////	}
////	while (r - l > 1e-5)
////	{
////		double mid = (l + r) / 2;
////		if (check(mid))
////			l = mid;
////		else
////			r = mid;
////	}
////	//printf("%.2lf\n", l);
////
////	l = 2.3999999999999999;
////	sprintf(s + 1, "%.3lf", l); //格式化 小数
////	s[strlen(s + 1)] = '\0';
////	printf("%s", s + 1);
////	
////	system("pause");
////}
//
////
////const int N = 1e4 + 10;
////const int M = 5e4 + 20;
////int n, m, S, T;
////int h[N], ne[M], e[M], w[M], idx;
////
////void add(int a, int b, int c)
////{
////	w[idx] = c;
////	e[idx] = b;
////	ne[idx] = h[a];
////	h[a] = idx++;
////}
////int dis[N];
////bool st[N];
////
////bool spfa(int mid)
////{
////	memset(dis, 0x3f, sizeof dis);
////	queue<int> q;
////	q.push(S);
////	dis[S] = 1;
////	while (!q.empty())
////	{
////		int x = q.front();
////		q.pop();
////		for (int i = h[x]; i != -1; i = ne[i])
////		{
////			if (w[i] <= mid)
////			{
////
////			}
////		}
////	}
////}
//
//
////#include <iostream>
////#include <algorithm>
////#include <string>
////#include <vector>
////#include <stack>
////#include <climits>
////
////
////using namespace std;
////
////typedef long long ll;
////const int N = 1e5 + 30;
////ll n, m;
////
////int a[N];
////
////
////bool check(ll mid) //和 m比 因为去掉的是m个
////{
////	ll sum = 0;
////	int ans = 1;
////	for (int i = 1; i <= n; i++)
////	{
////		if (sum + a[i] > mid)
////		{
////			ans++;
////			sum = a[i];
////		}
////		else
////		{
////			sum += a[i];
////		}
////	}
////
////	return ans <= m;  //分的组少于 或者刚好的话
////}
////
////int main()
////{
////	cin >> n >> m;
////	ll r = 0;
////	ll l = 0;
////	for (int i = 1; i <= n; i++)
////	{
////		cin >> a[i];
////		r += a[i];
////		l = max((ll)a[i], l);
////		
////	}
////	int ans = 0;
////	while (l <= r)
////	{
////		int mid = (l + r) / 2;
////		if (check(mid))
////		{
////			ans = mid;
////			r = mid - 1;
////		}
////		else
////		{
////			l = mid + 1; 
////		}
////	}
////	cout << ans << endl;
////
////	system("pause");
////}
///*
//12 8
//
//1 3 6 11 18 27 38 41 56 73 92 113
//*/
//
//
//
////
////int n, q[1000001], l, w[1000001], ans;
////string s;
////
//////q是高精度数组
//////w是q反转过后的长度 n进制的。
//////ans 是反转的步数
//////s 是输入的高精度字符串
////// l是高精度数的长度
////void add(int a[], int b[])
////{
////	for (int i = 1; i <= l; i++)
////	{
////		a[i] += b[i];
////		a[i + 1] += a[i] / n; //进位
////		a[i] %= n;
////	}
////	if (a[l + 1] > 0)
////	{
////		l++;
////	}
////}
//////高精度反转
////void turn(int a[])
////{
////	int j = 0;
////	for (int i = l; i >= 1; i--)
////	{
////		w[++j] = a[i];
////	}
////}
////
////
////bool f(int a[])
////{
////	int ln = l;
////	int i = 1;
////	int j = l;
////	while (ln--)
////	{
////		if (ln < l / 2)
////		{
////			break;
////		}
////		if (a[i] != a[j])
////		{
////			return false;
////		}
////		i++;
////		j--;
////	}
////	return true;
////}
////void init()
////{
////	int j = 0;
////	for (int i = s.length() - 1; i >= 0; i--)
////	{
////		if (s[i] >= '0' && s[i] <= '9')
////		{
////			q[++j] = s[i] - '0';
////		}
////		else
////		{
////			q[++j] = s[i] - 'A' + 10;
////		}
////	}
////}
////int main()
////{
////	cin >> n >> s;
////	init();
////	l = s.size();
////	while (!f(q))
////	{
////		turn(q);
////		add(q, w);
////		ans++;
////		if (ans > 30)
////		{
////			break;
////		}
////	}
////	if (ans > 30)
////	{
////		printf("Impossible!");
////	}
////	else
////	{
////		printf("STEP=%d", ans);
////	}
////	system("pause");
////	return 0;
////}
//
////vector<string> vs;
////bool cmp1(string& a, string& b)
////{
////	int i = 0;
////	int j = 0;
////	while (i < a.size() && i < b.size())
////	{
////		if (a[i] > b[i])
////		{
////			return true;
////		}
////		else if (a[i] < b[i])
////		{
////			return false;
////		}
////		i++;
////	}
////	if (a.size() >= b.size())
////		return true;
////	return false;
////}
////int main()
////{
////	
////	int n = 0;
////	cin >> n;
////	string str;
////	vs.resize(n);
////	for (int i = 0; i < n; i++)
////	{
////		cin >> str;
////		vs[i] = str;
////	}
////	sort(vs.begin(), vs.end(), cmp1);
////	string ans;
////	for (int i = 0; i < vs.size(); i++)
////	{
////		ans += vs[i];
////	}
////	cout << ans << endl;
////	system("pause");
////}