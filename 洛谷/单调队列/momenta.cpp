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
unique_ptr���� ���������ָ������Ȩ�� ����ָ��
unoque_ptr���� ��װһ��ԭʼ��ָ�룬�������������ڡ�����������ʱ����������������ɾ��������ԭʼָ��
unique_ptr ����->��* ��������� ��˿�������ָͨ��һ��ʹ��

�޷����� unique_ptr����,ֻ���ƶ���ÿһ��unique_ptr����ԭʼָ���Ψһ������

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

// douglas �㷨


// ��������  ţ���Ŷ�
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
//	//m ������  ���ҿ� ��û������ǵ�ǰi��������
//	for (int i = 1; i <= n; i++)
//	{
//		while (dq.size() && e[i].h > e[dq.back()].h) // ά���ݼ��ĵ�������
//			dq.pop_back();
//		dq.push_back(i);
//		while (dq.size() && e[i].x - e[dq.front()].x > m) // ���Ϸ��ĳ��ӡ�
//			dq.pop_front();
//		if ( e[dq.front()].h >= e[i].h * 2) lefts[i] = 1;
//
//
//
//	}
//	dq.clear();
//	for (int i = n; i >= 1; i--)
//	{
//		while (dq.size() && e[i].h > e[dq.back()].h)  // ά���ݼ��ĵ�������
//			dq.pop_back();
//		dq.push_back(i);
//		while (dq.size() && e[dq.front()].x - e[i].x > m) // ���Ϸ��ĳ���
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




//����ջ_ ѡ������
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

	dq.push_back(0); // ����push_back(0), Ҫ��Ȼ[0, k - 1] ȡ f��ʱ�򣬾ͻ����
	for (int i = 1; i <= n; i++)
	{

		scanf("%lld", &q[i]);
		d = q[i];
		ans += d;                                                          // 1 2 3 4 5    k = 2
		// !     i
		f[i] = dq.front() + 1ll * d; // f[]��ָ ȥ��f[i]ʱ�������ѵĶ��٣�  f[i] = f[i] + f[i - k - 1] + f[i - 2k - 1] - ...; 
		while (dq.size() && dq.back() >= f[i])
		{
			dq.pop_back();
		}
		dq.push_back(f[i]);
		p[dq.back()] = i; // ���ü�¼ �Ƿ񳬹��� dq.front()���� ��¼���Ѿ�

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