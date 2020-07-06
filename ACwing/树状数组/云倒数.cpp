#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//
////#include<iostream>
////#include<algorithm>
////#include<cstring>
////#include<string>
////using namespace std;
////struct Number
////{
////	int order;//序号
////	int value;//值
////}a[100005];
////int lsh[100005];//离散化后的数组
////int c[100005];
////int n;
////int lowbit(int x)//熟悉的lowbit
////{
////	return x&-x;
////}
////void update(int x, int k)//熟悉的增值函数
////{
////	for (int i = x; i <= n; i += lowbit(i))
////	{
////		c[i] += k;
////	}
////}
////int getSum(int x)//熟悉的求和函数,求前面和多少就是小于它数的个数
////{
////	int res = 0;
////	for (int i = x; i>0; i -= lowbit(i))
////	{
////		res += c[i];
////	}
////	return res;
////}
////
/////*
////以上我相信不用多说，只要有树状数组的基础就可以明白
////如果不熟悉的，其实没必要看这篇题解
////*/
////bool cmp(Number x, Number y)
////{
////	return x.value<y.value;
////}
//////排序函数
////int main()
////{
////	cin >> n;
////	for (int i = 1; i <= n; i++)
////	{
////		cin >> a[i].value;
////		a[i].order = i;//记录原序
////	}
////	sort(a + 1, a + n + 1, cmp);//快排
////	for (int i = 1; i <= n; i++)
////	{
////		lsh[a[i].order] = i;//离散化的过程
////	}
////	long long ans = 0;//不开longlong见祖宗
////	for (int i = 1; i <= n; i++)
////	{
////		update(lsh[i], 1);
////		ans += i - getSum(lsh[i]);//减去小于的数即为大于的数即为逆序数
////	}
////	memset(c, 0, sizeof c);
////	for (int i = n; i >= 1; i--)
////	{
////		ans += getSum(lsh[i] - 1);
////		update(lsh[i], 1);
////	}
////	cout << ans << endl;
////	return 0;
////}
//
//
//
//
//
//
//
////两次离散化 牛逼!
////#include <iostream>
////#include <algorithm>
////using namespace std;
////
////const int N = 1001;
////int n;
////int a[N];
////int c[N];
////int e[N];
////struct P
////{
////	int l, r;
////}point[N];
////int lowbit(int x)
////{
////	return x&(-x);
////}
////
////int query(int x)
////{
////	int ans = 0;
////	while (x > 0)
////	{
////		ans += c[x];
////		x -= lowbit(x);
////	}
////	return ans;
////}
////
////void add(int x, int y)
////{
////	while (x <= n)
////	{
////		c[x] += y;
////		x += lowbit(x);
////	}
////
////}
////bool cmp(P& p1, P& p2)
////{
////	return p1.l < p2.l;
////}
////int main()
////{
////	cin >> n;
////	for (int i = 1; i <= n; i++)
////	{
////		int d = 0;
////		cin >> d;
////		//a[i] = d + 1;
////		point[i].l = d + 1;
////		point[i].r = i;
////
////	}
////	sort(point + 1, point + n + 1, cmp);
////
////	int num = 0;
////	for (int i = 1; i <= n; i++)
////	{
////		if (point[i].l != point[i - 1].l)
////		{
////			e[point[i].r] = ++num;
////		}
////		else
////		{
////			e[point[i].r] = e[i - 1];
////		}
////	}
////	for (int i = 1; i <= n; i++)
////	{
////		a[i] = e[i];
////	}
////
////	for (int i = 1; i <= n; i++)
////	{
////		cout << query(a[i] - 1) << " ";
////		add(a[i], 1);
////	}
////	cout << endl;
////	system("pause");
////}
//
////vector<int> v;
////int main()
////{
////	int n, m;
////	scanf("%d%d", &n, &m);
////	if (n == 0 && m == 0) return 0;
////	//洛谷的数据那叫一个坑，我第一次80RE百思不得其解，下载了才
////	//发现数据是m=0，n=0,无输出............
////	for (int i = 1; i <= n; i++) v.push_back(i);
////	//vector动态数组在尾部插入。
////	int vz = 0;
////	while (v.size()>1)//当数组内有数时，做循环、
////	{
////		vz = (vz + m - 1) % v.size();
////		//vector数组下标从0开始，这一步重点在下面有详细解释。
////		cout << v[vz] << ' ';
////		//很简单的输出和删除。
////		v.erase(v.begin() + vz);
////		//vector利用内存块的移动实现删除，速度那叫一个快。
////	}
////	cout << v[0] << endl;
////	return 0;
////}
//
//
//
//
//
//

//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#define ll long long int
//using namespace std;
//const int N = 500005;
//int n, z, vc[N], va[N];//va为离散化后的数组,vc为树状数组
//int lowbit(int x){ return x&-x; }
//
//struct Node
//{
//	int v, order;//用于离散化
//}a[N];//a为一开始读入数据的数组
//bool cmp(Node a, Node b)
//{
//	return a.v<b.v;
//}
//void update(int x, int y)//树状数组更新
//{
//	for (int i = x; i <= n; i += lowbit(i))
//		vc[i] += y;
//}
//int getsum(int x)//树状数组求和
//{
//	int ans = 0;
//	for (int i = x; i>0; i -= lowbit(i))
//		ans += vc[i];
//	return ans;
//}
//int main(void)
//{
//
//	while (scanf("%d", &n) && n)
//	{
//		memset(vc, 0, sizeof(vc));
//		for (int i = 1; i <= n; i++)
//		{
//			scanf("%d", &a[i].v);//读入a[i]的数据和位置，为后面的离散化做准备
//			a[i].order = i;
//		}
//		sort(a + 1, a + 1 + n, cmp);//对a数组按照a.v从小到大排序
//		for (int i = 1; i <= n; i++)
//			va[a[i].order] = i;//离散化
//		ll ans = 0;
//		/*
//		for(int i=1;i<=n;i++)
//		{
//
//		update(va[i],1,n);
//		ans+=i-getsum(va[i]);//树状数组求逆序对个数的方法
//		}
//		*/
//		for (int i = n; i >= 1; i--)
//		{
//			ans += getsum(va[i]);
//			update(va[i], 1);
//		}
//		printf("%lld\n", ans);
//	}
//	return 0;
//}



// 北大 pingpong 

//#include<iostream>
//#include<cstdio>
//#include<cstdlib>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int n;
//int a[20010];
//int tree[100010];
//inline int lowbit(int x){ return x&(-x); }
//void update(int x, int k)
//{
//	while (x <= 100000)
//	{
//		tree[x] += k;
//		x += lowbit(x);
//	}
//}
//int query(int x)
//{
//	int sum = 0;
//	while (x != 0)
//	{
//		sum += tree[x];
//		x -= lowbit(x);
//	}
//	return sum;
//}
//int l_low[20010], l_up[20010], r_low[20010], r_up[20010];
//int main()
//{
//	int T;
//	scanf("%d", &T);
//	for (int _ = 1; _ <= T; ++_)
//	{
//		long long ans = 0;
//		scanf("%d", &n);
//		for (int i = 1; i <= n; ++i)scanf("%d", &a[i]);
//		for (int i = 1; i <= n; ++i)
//		{
//			l_low[i] = query(a[i] - 1); //左边比a[i]小的
//			l_up[i] = query(100000) - query(a[i] - 1); //右边比a[i]大的
//			update(a[i], 1);
//		}
//		for (int i = 1; i <= 100000; ++i)tree[i] = 0;
//		for (int i = n; i >= 1; --i)
//		{
//			r_low[i] = query(a[i] - 1); // 右边比a[i]小的
//			r_up[i] = query(100000) - query(a[i] - 1); // 左边比a[i]大的
//			update(a[i], 1);
//		}
//		for (int i = 1; i <= 100000; ++i)tree[i] = 0;
//
//		for (int i = 1; i <= n; i++)
//		{
//			ans += (long long)r_low[i] * (long long)l_up[i];
//			ans += (long long)l_low[i] * (long long)r_up[i];
//		}
//		printf("%lld\n", ans);
//	}
//}


//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//const int N = 3e4 + 20;
//int n,m;
//long long a[N];
//
//int c1[N], c2[N];
//int A[N], _A[N];
//int left1[N], right1[N];
//int _Q(int val)
//{
//	return lower_bound(_A + 1, _A + m + 1, val) - _A;
//}
//
//inline int lowbit(int i){
//	return i&(-i);
//}
//
//void add(int *C, int pos, int val){
//	while (pos <= N){
//		C[pos] += val;
//		pos += lowbit(pos);
//	}
//}
//
//int sum(int *C, int pos){
//	int res = 0;
//	while (pos>0){
//		res += C[pos];
//		pos -= lowbit(pos);
//	}
//	return res;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> A[i];
//		_A[i] = A[i];
//	}
//	sort(_A + 1, _A + 1 + n);
//	m = unique(_A + 1, _A + 1 + n) - (_A + 1);
//
//
//	for (int i = 1; i <= n; ++i){
//		add(c1, _Q(A[i]), 1);
//		left1[i] = sum(c1, _Q(A[i]) - 1);
//		//“减去A[i]出现个数”的隐式体现，就是我们只计算“A[i]-1（映射意义上）”的出现个数
//	}
//	for (int i = n; i >= 1; --i){
//		add(c2, _Q(A[i]), 1);
//		right1[i] = n - i - (sum(c2, _Q(A[i])) - 1);
//		//小细节，计算Rit时需要注意表达式与Lef不同 
//	}
//	long long ans = 0;
//	for (int i = 2; i<n; ++i) ans += left1[i] * right1[i];
//	//“乘法原理”的显式体现 
//	cout << ans;
//
//	system("pause");
//}


#include<cstdio>
#include<algorithm>
#define N 100005
using namespace std;
int n, l, len, m, now, i, ans;
char k;
//x记录这个点的坐标，val记录这个点是线段的头还是线段的尾;
struct P{ int x, val; int operator<(const P&t)const{ return x<t.x; } }line[N << 1];
int main()
{
	scanf("%d%d", &n, &m);
	for (i = 0; i<n; ++i)
	{
		scanf("%d %c", &len, &k);
		//将线段拆成点;
		if (k == 'R')
		{
			line[++l] = P{ now, +1 };
			line[++l] = P{ now += len, -1 };
		}
		else
		{
			line[++l] = P{ now, -1 };
			line[++l] = P{ now -= len, +1 };
		}
	}
	sort(line + 1, line + l + 1);
	//"扫描..."
	now = line[1].val;
	for (i = 2; i <= l; ++i)
	{
		if (now >= m) ans += line[i].x - line[i - 1].x;
		now += line[i].val;
	}
	printf("%d", ans);
}