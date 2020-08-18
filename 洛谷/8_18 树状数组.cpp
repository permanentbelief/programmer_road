#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;



using namespace std;

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		if (nums.size() < k) return false;
		double maxVal = DBL_MIN;
		double minVal = DBL_MAX;
		// 寻找最值
		for (double n : nums){
			maxVal = max(maxVal, n);
			minVal = min(minVal, n);
		}

		double err = 1e-5;
		// 用二分法查找平均值x，对于每个x去检查是否有子数组的平均值大于x
		while (maxVal - minVal > err){
			double mid = (maxVal + minVal) / 2.0;
			if (check(nums, mid, k))
				minVal = mid;
			else
				maxVal = mid;
		}
		return maxVal;
	}

private:
	// 判断数组内是否有一段长度大于等于k的子数组，满足均值大于key
	// 只需利用当前累加和，减去当前最小累加和即可判断
	// 时间复杂度O(n)
	bool check(vector<int>&nums, double key, int k){
		double sum = 0, prev = 0, minSum = 0;
		for (int i = 0; i < k; ++i)
			sum += nums[i] - key;
		if (sum >= 0)
			return true;
		for (int i = k; i < nums.size(); ++i) {
			sum += nums[i] - key;
			prev += nums[i - k] - key;
			minSum = min(prev, minSum);
			if (sum >= minSum)
				return true;
		}
		return false;
	}
};

//const int N = 1000;

bool check1(vector<int>& arr, double mid, int k)
{
	double sums = 0;
	double minSum = 0;
	double prev = 0;
	for (int i = 0; i < k; i++)
	{
		sums += arr[i] - mid;
	}
	cout << sums << endl;
	if (sums >= 0)
		return  true;
	for (int i = k; i < arr.size(); i++)
	{
		sums += arr[i] - mid;
		prev += arr[i - k] - mid;
		minSum = min(minSum, prev);
		if (sums >= minSum)
			return true;
	}
	return false;
}
bool check(vector<int>&nums, double key, int k){
	double sum = 0, prev = 0, minSum = 0;
	for (int i = 0; i < k; ++i)
		sum += nums[i] - key;
	if (sum >= 0)
		return true;
	for (int i = k; i < nums.size(); ++i) {
		sum += nums[i] - key;
		prev += nums[i - k] - key;
		minSum = min(prev, minSum);
		if (sum >= minSum)
			return true;
	}
	return false;
}

double re(vector<int>& nums, int k)
{

	/*
	if(arr.size() < k)
	return false;
	double r = INT_MIN;
	double l = INT_MAX;

	int ll = INT_MIN;
	int rr = INT_MAX;
	//  cout << l << r  << endl;
	for(int n : arr)
	{
	rr = min(rr,n);
	ll = max(ll,n);
	}

	// l = ll*1.0;
	//r = rr*1.0;
	//  cout << ll << rr <<endl;
	//   cout << l << r <<endl;
	double err = 0.000001;
	// cout << err  << endl;
	while(r - l > err)
	{
	double mid = (l + r)  / 2.0;
	if(check(arr,mid,k))
	l = mid;
	else
	r = mid;
	}
	return r;
	*/
	if (nums.size() < k) return false;
	double maxVal = INT_MIN;
	double minVal = INT_MAX;
	// 寻找最值
	for (double n : nums){
		maxVal = max(maxVal, n);
		minVal = min(minVal, n);
	}

	double err = 1e-5;
	// 用二分法查找平均值x，对于每个x去检查是否有子数组的平均值大于x
	while (maxVal - minVal > err){
		double mid = (maxVal + minVal) / 2.0;
		if (check(nums, mid, k))
			minVal = mid;
		else
			maxVal = mid;
	}
	return maxVal;

}

//int main()
//{
//	vector<int> arr = { 1, 12, -5, -6, 50, 3 };
//	Solution s;
//	cout << s.findMaxAverage(arr,5) <<endl;
//	int k = 5;
//	cout << re(arr, k) << endl;
//
//}

//
//int main()
//{
//	vector<int> arr = { 5, 6, 7, 8, 9, 1, 2, 3, 4 };
//	int k = 8;
//	int l = INT_MAX;
//	int r = 0;
//
//	for (int i = 0; i < arr.size(); i++)
//	{
//		r += arr[i];
//		l = min(l, arr[i]);
//	}
//	while (l < r)
//	{
//		int mid = (l + r + 1) / 2;
//
//		/*
//		int sums = 0;
//		int cnt = 1;
//		for(int i = 0; i < arr.size(); i++)
//		{
//		if(sums + arr[i] > mid)
//		{
//		sums = 0;
//		cnt++;
//		}
//		sums += arr[i];
//		}
//		*/
//		int cnt = 0;
//		int sum = 0;
//		//for (int a : arr)
//		//{
//
//		//	if (sum + a >= mid)
//		//	{
//		//		cnt++;
//		//		sum = 0;
//		//	}
//		//	sum += a;
//		//}
//		//mid = 6;
//		// cnt = 0;
//		// sum = 0;
//		mid = 3;
//		for (int a : arr)
//		{
//			sum += a;
//			if (sum  >= mid)
//			{
//				cnt++;
//				sum = 0;
//			}
//			//sum += a;
//		}
//		if (cnt >= (k + 1))
//			l = mid;
//		else
//			r = mid - 1;
//	}
//	cout << l << endl;
//	system("pause");
//}


//#include <set>
//
//class Solution {
//public:
//	int countRangeSum(vector<int>& nums, int lower, int upper) {
//		int size = nums.size();
//		multiset<long long> preSums; // 储存前缀和 不能丢弃重复值
//
//		long long preSum = 0;
//		long long ans = 0;
//		for (int i = 0; i < size; i++){
//			preSum += nums[i];
//
//			if (preSum >= lower && preSum <= upper)
//				ans++;
//
//			if (preSums.size() != 0){
//				long long thresh1 = preSum - upper;
//				long long thresh2 = preSum - lower;
//
//				auto it1 = preSums.lower_bound(thresh1);
//				auto it2 = preSums.upper_bound(thresh2);
//
//				ans += (std::distance(it1, it2));
//			}
//			preSums.insert(preSum);
//		}
//		return ans;
//	}
//};

//
//template <class K>
//struct TreeNode
//{
//	TreeNode<K>* _left;
//	TreeNode<K>* _right;
//	K _key;
//
//	TreeNode(const K& key)
//		:_key(key)
//		, _left(nullptr)
//		, _right(nullptr)
//	{
//
//	}
//};


//template <class K>
//class BSTree
//{
//	typedef TreeNode<K> Node;
//public:
//
//	Node* _root;
//	BSTree
//		:_root(nullptr)
//	{
//
//	}
//	bool insert(const K& key)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(key);
//			return true;
//		}
//		Node* cur = _root;
//		Node* p = nullptr;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				p = _root;
//				cur = cur->left;
//			}
//			else if (cur->_key > key)
//			{
//				p = _root;
//				cur = cur->right;
//			}
//			else
//				return false;
//
//		}
//		cur = new Node(key);
//
//		if (p->_key < key)
//		{
//			p->_right = cur;
//		}
//		if (p->key > key)
//		{
//			p->left = cur;
//		}
//		return true;
//	}
//
//	Node* find(const K& key)
//	{
//		if (_root == nullptr)
//			return _root;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//				cur = cur->left;
//			else if (cur->key == key)
//				return  cur;
//			else
//				cur = cur->right;
//
//		}
//		return nullptr;
//	}
//
//	bool erase(const K& key)
//	{
//		Node* p = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				p = cur;
//				cur = cur->right;
//			}
//			else if (cur->_key > key)
//			{
//				p = cur;
//				cur = cur->left;
//			}
//			else
//			{
//				//找到了
//				Node* del = cur; 
//				if (cur->left == nullptr)
//				{
//					if (p->left == cur)
//					{
//						p->left = cur->right;
//					}
//					else
//					{
//						p->right = cur->right;
//					}
//				}
//				else if (cur->right == nullptr)
//				{
//					if (p->left == cur)
//					{
//						p->left = cur->left;
//					}
//					else
//					{
//						p->right = cur->left;
//					}
//				}
//				else
//				{
//					Node* lp = cur;
//					Node* lr = cir->right;
//					while (lr->left)
//					{
//						lp = lr;
//						lr = lr->left;
//					}
//					cur->_key = lr->_key;
//					del = lr;
//
//					if (lp->left == lr)
//					{
//						lp->left = lr->right;
//					}
//					else
//					{
//						lp->right = lr->right;
//					}
//				}
//			}
//			delete del;
//			return true;
//		}
//	}
//
//	void RotateL(Node * p)
//	{
//
//	}
//};
//int main()
//{
//	BSTree<int> b;
//}
//
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#include<cmath>
//#define int long long
//#define lowbit(x) ((x)&(-(x)))
//using namespace std;
//const int MAXN = 500010;
//int n, c[MAXN], ans = 0, rank[MAXN];
//struct node{
//	int x, id;
//}a[MAXN];
//bool cmp(node a, node b){
//	if (a.x == b.x) return a.id<b.id;
//	return a.x<b.x;
//}
//void add(int x){//将a[x]++ 
//	for (int i = x; i <= n; i += lowbit(i)){
//		c[i]++;
//	}
//}
//int sum(int x){//求a[1...x]，即x前面与x造成顺序对的数量 
//	int ret = 0;
//	for (int i = x; i; i -= lowbit(i)){
//		ret += c[i];
//	}
//	return ret;
//}
//bool cmp2(node a, node b){
//	return a.id<b.id;
//}
//signed main(){
//	cin >> n;
//	for (int i = 1; i <= n; i++){
//		cin >> a[i].x;
//		a[i].id = i;
//	}
//	sort(a + 1, a + n + 1, cmp);//第一次按值排序，记录大小关系 
//	for (int i = 1; i <= n; i++){//排完序后记录，大小即为当前编号 
//		a[i].x = i;
//	}
//	sort(a + 1, a + n + 1, cmp2);//第二次按值（离散化后的）排序 
//	for (int i = 1; i <= n; i++){//值大的肯定先插入进去，前面的一定是顺序对 
//		add(a[i].x);//插入树状数组 
//		ans = max(ans, i - sum(a[i].x));//求本组能造成多少逆序对，求后面的逆序对等于总数减去前面的顺序对 
//	}
//	cout << ans + 1 << endl;//+1是因为还要再查一遍 
//	return 0;
//}
//
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//int tree[500010], rank1[500010], n;
//long long ans;
//struct point
//{
//	int num, val;
//}a[500010];
//inline bool cmp(point q, point w)
//{
//	if (q.val == w.val)
//		return q.num<w.num;
//	return q.val<w.val;
//}
//inline void insert(int p, int d)
//{
//	for (; p <= n; p += p&-p)
//		tree[p] += d;
//}
//inline int query(int p)
//{
//	int sum = 0;
//	for (; p; p -= p&-p)
//		sum += tree[p];
//	return sum;
//}
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &a[i].val), a[i].num = i;
//	sort(a + 1, a + 1 + n, cmp);
//	for (int i = 1; i <= n; i++)
//		rank1[a[i].num] = i;
//	rank1[1] = 4;
//	rank1[2] = 1;
//	rank1[3] = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		insert(rank1[i], 1);
//		ans += i - query(rank1[i]);
//	}
//	printf("%lld", ans);
//	return 0;
//}


/* 简单题 区间修改 单点查询

#include <bits/stdc++.h>

using namespace std;
const int N = 100010;

int n, c[N];
void add(int i, int val)
{
while (i <= n)
{
c[i] += val;
i += i&-i;
}
}

int ask(int i)
{
int sum = 0;
while (i >= 1)
{
sum += c[i];
i -= i&-i;
}
return sum;
}
int main()
{
int m, t, l, r;
cin >> n >> m;

while (m--)
{
cin >> t;
if (t == 1)
{
cin >> l >> r;
add(l, 1);
add(r + 1, -1);
}
else{
cin >> l;
if (ask(l) % 2 == 0) cout << 0;
else cout << 1;
cout << endl;
}
}
}

*/

/*
区间修改 单点查询

#include <bits/stdc++.h>

using namespace std;
const int N = 1e7 + 10000;
int c[N];
int a[N];
int n,l,r,k,m;


int lowbit(int x)
{
return x&-x;
}
int ask(int x)
{
long long res = 0;
while(x > 0)
{
res += c[x];
x -= lowbit(x);
}
return res;
}

void add(int x, int t)
{
while(x <= n)
{
c[x] += t;
x += lowbit(x);
}

}
int main()
{
cin >> n >> m;
while(m--)
{
cin >> k;
if(k == 0)
{
cin >>l >> r;
add(l,1);
add(r + 1, - 1);
}
else
{
cin >> l;
cout << ask(l) << endl;
}
}

}

*/




/*
简单题 区间修改 单点查询


*/

/*
#include <stdio.h>
#include <iostream>
#include <memory.h>
using namespace std;
int n,m,a[50001],maxn[50001],minx[50001],s;
inline int lowbit(int x)
{
return x&-x;
}
inline void update(int x,int k)//区间[x,n]修改最值
{
while(x<=n)
{
maxn[x]=max(maxn[x],k);
minx[x]=min(minx[x],k);
x+=lowbit(x);
}
}
inline int query(int l,int r)//区间[l,r]查询最值
{//对比一下树状数组的查询区间和，其实还是很像的
register int mn(2e9+7),mx(-2e9-7);
while(l<=r)
{
while(r-lowbit(r)>=l)//while(r>0)
{
mx=max(mx,maxn[r]);
mn=min(mn,minx[r]);
r-=lowbit(r);
}
mx=max(a[r],mx);
mn=min(a[r],mn);
r--;
}
return mx-mn;
}
signed main()
{
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
register int i,j;
memset(minx,2E9+7,sizeof(minx));
cin>>n>>m;
for(i=1;i<=n;i++)
{
cin>>a[i];
update(i,a[i]);//单点修改
}
for(i=1;i<=m;i++)
{
register int l,r;
cin>>l>>r;
cout<<query(l,r)<<endl;//区间查询最值
}
return 0;
}
*/
//
//
//
//using namespace std;
//const int N = 100500;
//
//int c[N], n;
//
//struct node
//{
//	int val, pos;
//	bool operator< (const node& n) const
//	{
//		if (val == n.val) return pos < n.pos;
//		return val < n.val;
//	}
//}a[N];
//
//int lowbit(int x)
//{
//	return x&-x;
//}
//
//
//bool  cmp(node& a, node& b)
//{
//	return a.pos < b.pos;
//}
//int get(int x)
//{
//	int  sum = 0;
//	for (int i = x; i > 0; i -= lowbit(x))
//	{
//		sum += c[i];
//	}
//	return sum;
//}
//
//void add(int x, int t)
//{
//	for (int i = x; i <= n; i += lowbit(i))
//	{
//		c[i] += t;
//	}
//
//}
//
//int main()
//{
//	cin >> n;
//	int ans = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int mm = 0;
//		cin >> mm;
//		a[i] = { mm, i };
//	}
//	sort(a + 1, a + 1 + n);
//	for (int i = 1; i <= n; i++)
//	{
//		a[i].val = i;
//	}
//	sort(a + 1, a + n + 1, cmp);
//	//int ans = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		add(a[i].val,1);
//		ans = max(ans, i - get(a[i].val));
//	}
//	cout << ans + 1 << endl;
//}





/*
简单题 区间修改 单点查询


*/

/*
#include <stdio.h>
#include <iostream>
#include <memory.h>
using namespace std;
int n,m,a[50001],maxn[50001],minx[50001],s;
inline int lowbit(int x)
{
return x&-x;
}
inline void update(int x,int k)//区间[x,n]修改最值
{
while(x<=n)
{
maxn[x]=max(maxn[x],k);
minx[x]=min(minx[x],k);
x+=lowbit(x);
}
}
inline int query(int l,int r)//区间[l,r]查询最值
{//对比一下树状数组的查询区间和，其实还是很像的
register int mn(2e9+7),mx(-2e9-7);
while(l<=r)
{
while(r-lowbit(r)>=l)//while(r>0)
{
mx=max(mx,maxn[r]);
mn=min(mn,minx[r]);
r-=lowbit(r);
}
mx=max(a[r],mx);
mn=min(a[r],mn);
r--;
}
return mx-mn;
}
signed main()
{
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
register int i,j;
memset(minx,2E9+7,sizeof(minx));
cin>>n>>m;
for(i=1;i<=n;i++)
{
cin>>a[i];
update(i,a[i]);//单点修改
}
for(i=1;i<=m;i++)
{
register int l,r;
cin>>l>>r;
cout<<query(l,r)<<endl;//区间查询最值
}
return 0;
}
*/




//
//using namespace std;
//const int N = 1e5 + 10;
//
//int c[N], n;


/*
struct node
{
int val,pos;
bool operator< (const node& n) const
{
if(val == n.val) return pos < n.pos;
return val < n.val;
}
}a[N];
*/
//int a[N];
//int lowbit(int x)
//{
//	return x&-x;
//}

/*
bool  cmp(node& a, node& b)
{
return a.pos < b.pos;
}
*/
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//		//a[i] -= i;
//	}
//
//	int len = 1;
//	c[1] = a[1];
//	for (int i = 2; i <= n; i++)
//	{
//		if (a[i] >= c[len])
//		{
//			c[++len] = a[i];
//		}
//		else
//		{
//			int pos = lower_bound(c + 1, c + 1 + len, a[i]) - c;
//			c[pos] = a[i];
//		}
//	}
//	cout << n - len << endl;
//
//}

/*
推销员 贪心
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,sum[100010],q[100010],h[100010];//n 疲劳前缀和 前i个最大值 后i个最大值
struct node{
int s;//距离
int a;//疲劳
}v[100010];
bool cmp(node x,node y){return x.a>y.a;}
int main()
{	scanf("%d",&n);
for(int i=1;i<=n;i++)scanf("%d",&v[i].s);
for(int i=1;i<=n;i++)scanf("%d",&v[i].a);
sort(v+1,v+1+n,cmp);//按疲劳排序
for(int i=1;i<=n;i++)sum[i]=sum[i-1]+v[i].a;
for(int i=1;i<=n;i++)q[i]=max(q[i-1],2*v[i].s);//前i个最大值
for(int i=n;i>=1;i--)h[i]=max(h[i+1],2*v[i].s+v[i].a);//后i个最大值
for(int i=1;i<=n;i++)printf("%d\n",max(sum[i]+q[i],sum[i-1]+h[i]));
return 0;
}


*/






//#include <iostream>
//#include <cstring>
//#include <functional>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 3e4 + 20;
//#include <set>
//
//typedef long long ll;
//
////unsigned long long a[N];
//int n;
//int l[N];
//int r[N];
//long long c[N];
//long long va[N];
//
//
//struct node
//{
//	long long val;
//	int order;
//}a[N];
//
//bool cmp(node& a, node& b)
//{
//	return a.val < b.val;
//}
//int lowbit(ll x)
//{
//	return x&(-x);
//}
//
//void add(ll x, ll y)
//{
//	while (x <= n)
//	{
//		c[x] += y;
//		x += lowbit(x);
//	}
//}
//long long get_sum(ll x)
//{
//
//	ll ans = 0;
//	while (x)
//	{
//		ans += c[x];
//		x -= lowbit(x);
//	}
//	return ans;
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i].val;
//		a[i].order = i;
//	}
//
//	sort(a + 1, a + 1 + n, cmp);
//
//	for (int i = 1; i <= n; i++)
//	{
//		if (a[i].val != a[i - 1].val)
//			va[a[i].order] = i; //离散化
//		else
//			va[a[i].order] = va[a[i - 1].order];
//	}
//	memset(c, 0, sizeof c);
//
//	for (int i = 1; i <= n; i++) // 求左边有多少个数比它小
//	{
//		l[i] = get_sum(va[i] - 1);
//		add(va[i], 1);
//
//	}
//	memset(c, 0, sizeof c);
//	for (int i = n; i >= 1; i--) //求右边有多少数比它大
//	{
//		r[i] = get_sum(n) - get_sum(va[i]);
//		add(va[i], 1);
//	}
//
//	long long ans = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		ans += (l[i] * r[i]);
//	}
//	cout << ans << endl;
//	system("pause");
//}


#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll cmax = 310000;
ll sqt[cmax];
ll a[cmax], a1[cmax];
ll m;
ll l[cmax], r[cmax];
void read(ll &x)
{
	x = 0;
	ll f;
	f = 1;
	char c;
	c = getchar();
	while ((c<'0' || c>'9') && (c != '-'))
	{
		c = getchar();
	}
	if (c == '-')
	{
		f = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
	{
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	x = x*f;
}
inline ll lowbit(ll x)
{
	return x&(-x);
}
void add(ll x, ll val)
{
	while (x <= cmax)
	{
		sqt[x] += val;
		x += lowbit(x);
	}
}
ll query(ll x)
{
	ll ans;
	ans = 0;
	while (x>0)
	{
		ans += sqt[x];
		x -= lowbit(x);
	}
	return ans;
}
inline ll Q(ll val)
{
	int k = lower_bound(a1 + 1, a1 + 1 + m, val) - a1;
	return k;
}
int main()
{
	ll n, i;
	read(n);
	for (i = 1; i <= n; i++)
	{
		read(a[i]);
		a1[i] = a[i];
	}
	sort(a1 + 1, a1 + 1 + n);
	m = unique(a1 + 1, a1 + 1 + n) - (a1 + 1);
	for (i = 1; i <= n; i++)
	{
		l[i] = query(Q(a[i]) - 1);
		add(Q(a[i]), 1);
		
		
		
	}
	memset(sqt, 0, sizeof(sqt));
	for (i = n; i >= 1; i--)
	{
		add(Q(a[i]), 1);
		r[i] = n - i + 1 - (query(Q(a[i])));
		
		
	}
	ll ans;
	ans = 0;
	for (i = 2; i<n; i++)
	{
		ans += l[i] * r[i];
	}
	printf("%lld", ans);
	system("pause");
	return 0;
}



