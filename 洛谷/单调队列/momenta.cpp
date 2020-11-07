#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

#include <memory>

using namespace std;



/*
unique_ptr独享 被管理对象指针所有权的 智能指针
unoque_ptr对象 包装一个原始的指针，并负责生命周期。当对象被销毁时，会在析构函数中删除关联的原始指针
unique_ptr 具有->和* 运算符重载 因此可以像普通指针一样使用

无法复制 unique_ptr对象,只能移动，每一个unique_ptr都是原始指针的唯一所有者

*/

//struct Task
//{
//	int mid;
//	Task(int id)
//		:mid(id)
//	{
//		cout << "Constructor" << endl;
//	}
//	~Task()
//	{
//		cout << "Destructor" << endl;
//	}
//};
//
//
//void testm()
//{
//	unique_ptr<Task> taskPtr(new Task(23));
//	cout << taskPtr.get() << endl;
//	int id = taskPtr->mid;
//	cout << id << endl;
//
//}
//int main()
//{
//
//	// testm();
//	//unique_ptr<int> ptr1;
//	//if (!ptr1)
//	//{
//	//	cout << "ptr1 is empty" << endl;
//	//}
//	//else
//	//{
//	//	cout << "isn't empty" << endl;
//	//}
//	//unique_ptr<Task> ptr2(new Task(22));
//	//ptr2.reset();
//	//if (!ptr2)
//	//{
//	//	cout << "ptr2 is empty" << endl;
//	//}
//	//else
//	//{
//	//	cout << "ptr2 isn't empty" << endl;
//	//}
//
//	unique_ptr<Task> ptr2(new Task(22));
//	cout << ptr2.get() << endl;
//
//	unique_ptr<Task> ptr3(move(ptr2));
//
//	cout << ptr2.get() << endl;
//	cout << ptr3.get() << endl;
//
//	system("pause");
//	return 0;
//}

// douglas 算法


// 单调队列  牛奶排队
//using namespace std;
//
//
//const int N = 5e4 + 100;
//const int M = 1e9 + 10;
//
//
//int a[N];
//int lefts[N];
//int rights[N];
//long long sums[N];
//int n, m;
//struct node
//{
//	int x, h;
//	bool operator<(const node& n) const
//	{
//		return x < n.x;
//	}
//}e[N];
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> e[i].x >> e[i].h;
//	}
//	sort(e + 1, e + 1 + n);
//
//
//	/*
//	for (int i = 1; i <= n; i++)
//	{
//	cout << e[i].h << " ";
//	}
//	cout << endl;
//	*/
//
//	deque<int> dq;
//	//m 距离内  向右看 有没有身高是当前i的两倍的
//	for (int i = 1; i <= n; i++)
//	{
//		while (dq.size() && e[i].h > e[dq.back()].h) // 维护递减的单调队列
//			dq.pop_back();
//		dq.push_back(i);
//		while (dq.size() && e[i].x - e[dq.front()].x > m) // 不合法的出队。
//			dq.pop_front();
//		if ( e[dq.front()].h >= e[i].h * 2) lefts[i] = 1;
//
//
//
//	}
//	dq.clear();
//	for (int i = n; i >= 1; i--)
//	{
//		while (dq.size() && e[i].h > e[dq.back()].h)  // 维护递减的单调队列
//			dq.pop_back();
//		dq.push_back(i);
//		while (dq.size() && e[dq.front()].x - e[i].x > m) // 不合法的出队
//			dq.pop_front();
//		if (e[dq.front()].h >= e[i].h * 2) rights[i] = 1;
//
//	}
//
//	/*
//	for (int i = 1; i <= n; i++)
//	{
//	cout << lefts[i] << " ";
//	}
//	cout << endl;
//	for (int i = 1; i <= n; i++)
//	{
//	cout << rights[i] << " ";
//	}
//	cout << endl;
//	*/
//
//	int ans = 0;
//	for (int i = 1; i <= n; i++) if (rights[i] && lefts[i]) ans++;
//
//
//	cout << ans << endl;
//	system("pause");
//}


using namespace std;




//单调栈_ 选择数字
typedef long long ll;
ll p[100010];
ll q[100010];
ll f[100010];
ll ans;
ll n, k;
ll d;
int main()
{
	deque<ll> dq;
	scanf("%lld %lld", &n, &k);

	dq.push_back(0); // 必须push_back(0), 要不然[0, k - 1] 取 f的时候，就会出错
	for (int i = 1; i <= n; i++)
	{

		scanf("%lld", &q[i]);
		d = q[i];
		ans += d;                                                          // 1 2 3 4 5    k = 2
		// !     i
		f[i] = dq.front() + 1ll * d; // f[]是指 去掉f[i]时，所花费的多少，  f[i] = f[i] + f[i - k - 1] + f[i - 2k - 1] - ...; 
		while (dq.size() && dq.back() >= f[i])
		{
			dq.pop_back();
		}
		dq.push_back(f[i]);
		p[dq.back()] = i; // 不用记录 是否超过， dq.front()就是 记录了已经

		while (dq.size() && i - k > p[dq.front()])
		{
			dq.pop_front();
		}

	}
	long long s = 0;
	for (int i = n - k; i <= n; i++)
	{
		s = max(s, ans - f[i]);
	}
	printf("%lld\n", s);
}