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
////	int order;//���
////	int value;//ֵ
////}a[100005];
////int lsh[100005];//��ɢ���������
////int c[100005];
////int n;
////int lowbit(int x)//��Ϥ��lowbit
////{
////	return x&-x;
////}
////void update(int x, int k)//��Ϥ����ֵ����
////{
////	for (int i = x; i <= n; i += lowbit(i))
////	{
////		c[i] += k;
////	}
////}
////int getSum(int x)//��Ϥ����ͺ���,��ǰ��Ͷ��پ���С�������ĸ���
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
////���������Ų��ö�˵��ֻҪ����״����Ļ����Ϳ�������
////�������Ϥ�ģ���ʵû��Ҫ����ƪ���
////*/
////bool cmp(Number x, Number y)
////{
////	return x.value<y.value;
////}
//////������
////int main()
////{
////	cin >> n;
////	for (int i = 1; i <= n; i++)
////	{
////		cin >> a[i].value;
////		a[i].order = i;//��¼ԭ��
////	}
////	sort(a + 1, a + n + 1, cmp);//����
////	for (int i = 1; i <= n; i++)
////	{
////		lsh[a[i].order] = i;//��ɢ���Ĺ���
////	}
////	long long ans = 0;//����longlong������
////	for (int i = 1; i <= n; i++)
////	{
////		update(lsh[i], 1);
////		ans += i - getSum(lsh[i]);//��ȥС�ڵ�����Ϊ���ڵ�����Ϊ������
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
////������ɢ�� ţ��!
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
////	//��ȵ������ǽ�һ���ӣ��ҵ�һ��80RE��˼������⣬�����˲�
////	//����������m=0��n=0,�����............
////	for (int i = 1; i <= n; i++) v.push_back(i);
////	//vector��̬������β�����롣
////	int vz = 0;
////	while (v.size()>1)//������������ʱ����ѭ����
////	{
////		vz = (vz + m - 1) % v.size();
////		//vector�����±��0��ʼ����һ���ص�����������ϸ���͡�
////		cout << v[vz] << ' ';
////		//�ܼ򵥵������ɾ����
////		v.erase(v.begin() + vz);
////		//vector�����ڴ����ƶ�ʵ��ɾ�����ٶ��ǽ�һ���졣
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
//int n, z, vc[N], va[N];//vaΪ��ɢ���������,vcΪ��״����
//int lowbit(int x){ return x&-x; }
//
//struct Node
//{
//	int v, order;//������ɢ��
//}a[N];//aΪһ��ʼ�������ݵ�����
//bool cmp(Node a, Node b)
//{
//	return a.v<b.v;
//}
//void update(int x, int y)//��״�������
//{
//	for (int i = x; i <= n; i += lowbit(i))
//		vc[i] += y;
//}
//int getsum(int x)//��״�������
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
//			scanf("%d", &a[i].v);//����a[i]�����ݺ�λ�ã�Ϊ�������ɢ����׼��
//			a[i].order = i;
//		}
//		sort(a + 1, a + 1 + n, cmp);//��a���鰴��a.v��С��������
//		for (int i = 1; i <= n; i++)
//			va[a[i].order] = i;//��ɢ��
//		ll ans = 0;
//		/*
//		for(int i=1;i<=n;i++)
//		{
//
//		update(va[i],1,n);
//		ans+=i-getsum(va[i]);//��״����������Ը����ķ���
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



// ���� pingpong 

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
//			l_low[i] = query(a[i] - 1); //��߱�a[i]С��
//			l_up[i] = query(100000) - query(a[i] - 1); //�ұ߱�a[i]���
//			update(a[i], 1);
//		}
//		for (int i = 1; i <= 100000; ++i)tree[i] = 0;
//		for (int i = n; i >= 1; --i)
//		{
//			r_low[i] = query(a[i] - 1); // �ұ߱�a[i]С��
//			r_up[i] = query(100000) - query(a[i] - 1); // ��߱�a[i]���
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
//		//����ȥA[i]���ָ���������ʽ���֣���������ֻ���㡰A[i]-1��ӳ�������ϣ����ĳ��ָ���
//	}
//	for (int i = n; i >= 1; --i){
//		add(c2, _Q(A[i]), 1);
//		right1[i] = n - i - (sum(c2, _Q(A[i])) - 1);
//		//Сϸ�ڣ�����Ritʱ��Ҫע����ʽ��Lef��ͬ 
//	}
//	long long ans = 0;
//	for (int i = 2; i<n; ++i) ans += left1[i] * right1[i];
//	//���˷�ԭ������ʽ���� 
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
//x��¼���������꣬val��¼��������߶ε�ͷ�����߶ε�β;
struct P{ int x, val; int operator<(const P&t)const{ return x<t.x; } }line[N << 1];
int main()
{
	scanf("%d%d", &n, &m);
	for (i = 0; i<n; ++i)
	{
		scanf("%d %c", &len, &k);
		//���߶β�ɵ�;
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
	//"ɨ��..."
	now = line[1].val;
	for (i = 2; i <= l; ++i)
	{
		if (now >= m) ans += line[i].x - line[i - 1].x;
		now += line[i].val;
	}
	printf("%d", ans);
}