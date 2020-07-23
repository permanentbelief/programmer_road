#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>


#include <unordered_set>
using namespace std;

//  食物链  记忆化搜索
//#include <bits/stdc++.h>
//
//
//
//
//using namespace std;
//
//typedef long long ll;
//
//const int N = 1e6 + 200;
//const int M = 2e5 + 20;
//int n,m;
//
//int idx;
//int st[N];
//
//struct node
//{
//    int u,v,next;
//}e[M];
//
//
//void add(int x, int y)
//{
//    e[++idx].u = x;
//    e[idx].v = y;
//    e[idx].next = st[x];
//    st[x] = idx; 
//}
//
//
//
//int out[N];
//int in[N];
//
//int dp[N]; //记忆化数组
//
//int ans;
//
//int dfs(int root)
//{
//    if(dp[root]) return dp[root];
//    int ans = 0;
//    if(out[root] == 0) return 1;
//    for(int i= st[root] ; i ; i = e[i].next)
//    {
//        ans += dfs(e[i].v);
//    }
//    dp[root] = ans;
//    return ans;
//}
//int main()
//{
//    cin >> n >> m;
//    for(int i = 1; i <= m; i++)
//    {
//        int a,b;
//        cin >> a >> b;
//        add(a,b);
//        out[a]++;
//        in[b]++;
//        
//    }
//    int sum = 0;
//    for(int i = 1; i <= n; i++)
//    {
//        if(in[i] == 0 && out[i] != 0)
//        {
//            sum += dfs(i);
//        }
//    }
//    cout << sum << endl;
//	return 0;
//}

//int main()
//{
//	Solution s;
//	vector<vector<int>> v = { { 9, 9, 4 }, { 6, 6, 8 }, { 2, 1, 1 } };
//	s.longestIncreasingPath(v);
//
//
//	/*vector<int> v1 = { 1, 2 };
//	vector<int> v2 = { 3,4 };
//	s.findMedianSortedArrays(v1, v2);*/
//	system("pause");
//}



using namespace std;

const int N = 30;
int a[N];

// O(n)的时间复杂度 判断升序数组中 平方和不同的有多少个元素
//int main()
//{
//	vector<int> arr= { -9, -1, -2, 2, 5, 5, 6, 9};
//
//
//	int head = 0;
//	int tail = arr.size() - 1;
//	int lastBig = -1;
//	int count = 0;
//	for (int i = 0; i < arr.size(); i++)
//	{
//		arr[i] = abs(arr[i]);
//	}
//	while (head <= tail)
//	{
//		while (head < arr.size() && arr[head] == lastBig)
//		{
//			head++;
//		}
//		while (tail >= 0 && arr[tail] == lastBig)
//		{
//			tail--;
//		}
//		if (head <= tail)
//		{
//			count++;
//			if (arr[head] > arr[tail])
//			{
//				lastBig = arr[head];
//				head++;
//			}
//			else
//			{
//				lastBig = arr[tail];
//				tail--;
//			}
//		}
//		else
//		{
//			cout << count << endl;
//			break;
//		}
//	}
//	cout << count << endl;
//	system("pause");
//
//
//}

// 先升序 后降序 找不重复元素的个数 时间复杂度O(N)
//int main()
//{
//	vector<int> arr = { 1, 2, 2, 5, 5, 10, 14, 15,15, 10, 9 };
//
//	int l = 0;
//	int r = arr.size() - 1;
//
//	int k = INT_MAX;
//
//	int count = 0; //不同元素的个数
//	int lastBig = -1;
//	while (l <= r)
//	{
//		while (l <= r && arr[l] == lastBig)
//			l++;
//		while (l <= r && arr[r] == lastBig)
//			r--;
//		if (l > r)
//			break;
//			count++;
//			if (arr[l] < arr[r])
//			{
//				lastBig = arr[l];
//				l++;
//			}
//			else
//			{
//				lastBig = arr[r];
//				r--;
//			}
//		
//	}
//	cout << count << endl;
//
//
//	system("pause");
//
//
//}



// 正确的怪兽问题1
//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long ll;
//typedef pair<int, int> pii;
//
//
//int n, y;
//ll res;
//pii monster[N];
//
//int main()
//{
//	scanf("%d %d", &n, &y);
//	for (int i = 0; i < n; i++)
//		scanf("%d %d", &monster[i].first, &monster[i].second);
//	sort(monster, monster + n);
//	for (int i = n - 1; i; i--)
//		monster[i].second -= monster[i - 1].second;
//	for (int i = 0, j = 0; i < n; i++)
//	{
//		while (j < n && monster[j].first - monster[i].first <= 2 * y) j++;
//		if (j < n) monster[j].second += monster[i].second;
//		if (monster[i].second > 0) res += monster[i].second;
//	}
//	printf("%lld\n", res);
//
//	system("pause");
//	return 0;
//
//}


// 正确的怪兽问题2 
// const int N = 1e5;
//const int M = 1e9;
//
//using namespace std;
//typedef long long ll;
//
//struct node
//{
//	int x, val;
//	bool operator<(const node& n) const
//	{
//		return x < n.x;
//	}
//}e[N];
//
//int n, k; //数量和 范围
//
//int main()
//{
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> e[i].x >> e[i].val;
//	}
//	sort(e + 1, e + 1 + n);
//
//	deque<int> dq;
//	int sum = 0;
//	int max_ = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		while (e[i].val > 0)
//		{
//			int tmp = e[i].val;
//			for (int j = i; j <= n; j++)
//			{
//				if (e[j].x - e[i].x <= 2 * k)
//				{
//					e[j].val -= tmp;
//				}
//			}
//			sum += tmp;
//		}
//		
//	}
//	cout << sum << endl;
//	system("pause");
//}


#include <bitset>
//1亿个正整数,范围是0-42亿。求出现次数是2的数字，空间复杂度 位图做

// bitmap得看一看!!
//int main()
//{
//	vector<int> arr = { 1, 2, 2, 5, 5, 10, 14, 15, 15, 10, 9 };
//	long max_ = 0;
//	long min_ = INT_MAX;
//	for (int i = 0; i < arr.size(); i++)
//	{
//		max_ = max(max_, (long)arr[i]);
//		min_ = min(min_, (long)arr[i]);
//	}
//	const size_t h  = max_ / 8 - min_ / 8 + 1;
//	bitset<100> s;
//	int nums = 0;
//	for (int i = 0; i < arr.size(); i++)
//	{
//		int num = arr[i];
//		int index = num / 8 - min_ / 8;
//		int k = (num - min_) % 8;
//
//		if (s[index] & 1 << k > 0)
//		{
//			nums++;
//		}
//		else
//		{
//			s[index] = s[index] | (1 << k);
//		}
//	}
//	cout << nums << endl;
//
//	system("pause");
//
//
//}


#include <map>
int n, m;

void AdjustDown(int * a , int parent, int n)
{
	int children = parent * 2 + 1;
	while (children < n)
	{
		if (children + 1 < n && a[children] > a[children + 1])
			++children;
		if (a[children] <= a[parent])
		{
			swap(a[children], a[parent]);
			parent = children;
			children = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void heapSort(int* a, int n)
{
	for (int i = (n - 2)/2; i >= 0; i--)
	{
		AdjustDown(a, i, n);
	}


	int end = n - 1;
	while (end > 0)
	{
		swap(a[0], a[end]);
		AdjustDown(a, 0, end);
		end--;
	}
}
//int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//	int n = gas.size();
//	if (n == 0)
//		return 0;
//	for (int i = 0; i < n; i++)
//	{
//		int tmp = i;
//		if (gas[i] < cost[i])
//			continue;
//		int gas_init = gas[tmp];
//		bool flag = false;
//		int j = tmp + 1;
//		while (j % n != tmp)
//		{
//
//			gas_init += gas[j % n] - cost[(j - 1 + n) % n];
//			if (gas_init <= 0)
//			{
//				flag = true;
//				break;
//			}
//			j++;
//		}
//		if (flag == false && (gas_init >= (cost[ (tmp + n - 1) % n])))
//			return i;
//	}
//	return  -1;
//}

//template <class T>
//class ListNode
//{
//public:
//	ListNode<T>* _pre;
//	ListNode<T>* _next;
//	T _value;
//	ListNode<T> (T value)
//	{
//		_value = value;
//	}
//};

//template <class T>
//class Mystack
//{
//public:
//	ListNode<T>* _tail = nullptr;
//	Mystack()
//	{
//
//	}
//
//	ListNode<T>* put(T _val)
//	{
//		ListNode<T>* value = new ListNode<T>(_val);
//		value->_pre = _tail;
//		if (_tail == nullptr)
//			_tail = value;
//		else
//			_tail->_next = value;
//		_tail = value;
//		return value;
//	}
//	ListNode<T>* peek()
//	{
//		return _tail;
//	}
//
//	T pop()
//	{
//		ListNode<T>* p = _tail;
//		if (_tail != nullptr && _tail->_pre != nullptr)
//			_tail = _tail->_pre, _tail->_next = nullptr;
//
//		return p->_value;
//	}
//
//	T operator*()  
//	{
//		return _tail->_value;
//	}
//
//};
//int main()
//{
//
//	Mystack<int> s;
//	s.put(10);
//	s.put(100);
//	cout << s.pop() << endl;
//	cout << s.pop() << endl;
//	cout << s.pop() << endl;
//	//cout << s.operator*() << endl;
//	//cout << s.peek() << endl;
//	system("pause");
//
//}


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int cur = 0;
		int times = 0;
		int sums = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			int j = i;
			times = 1;
			while (j + 1 < nums.size() && nums[j] == nums[j + 1])
			{
				j++;
				times++;
			}
			for (int k = j; times > 2; times--)
			{
				nums[k] = -1;
				cur++;
				k--;
			}
			i = j;

		}

		for (int i = 0, j = 0;i < nums.size() - cur; i++)
		{
			if (nums[i] == -1)
			{
				j = i;
				while (j  < nums.size() && nums[j] == -1)
				{
					j++;
				}

				swap(nums[i], nums[j]);
			}
		}

		//cout << nums.size() << endl;
		//cout <<cur<<endl;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
		return nums.size() - cur;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1,1,1 };

	s.removeDuplicates(v);
}