#define _CRT_SECURE_NO_WARNINGS 1 
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;

//内存超限
//struct op
//{
//	bool operator()(const pair<int, int>&l, const pair<int, int>& r)
//	{
//		if (l.first == r.first)
//		{
//			return l.second <= r.second;
//		}
//		return l.first < r.first;
//	}
//};
//int main()
//{
//	int n = 0;
//	vector<pair<int, int>> vp;
//	while (cin >> n)
//	{
//		int first = 0;
//		int second = 0;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> first;
//			cin >> second;
//			vp.push_back(make_pair(first, second));
//		}
//		sort(vp.begin(), vp.end(), op());
//
//		int count = 0;
//		for (int i = 0; i < vp.size() - 1; i++)
//		{
//			if (vp[i].first <= vp[i + 1].first && vp[i].second <= vp[i + 1].second)
//			{
//				count++;
//			}
//		
//		}
//		if (count != 0)
//			count += 1;
//		cout << count << endl;
//	}
//}




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b)
{
	return a.first<b.first;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<pair<int, int>> vp;
		int first = 0;
		int second = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> first;
			cin >> second;
			vp.push_back(make_pair(first, second));
		}

		sort(vp.begin(), vp.end(),cmp);
		vector<int> v(n);
		for (int i = 0; i < vp.size(); i++)
		{
			v[i] = vp[i].second;
		}
		int len = 1;

		vector<int> dp(n+1);
		dp[1] = v[0];
		for (int i = 1; i <n; i++)
		{
			if (v[i] >= dp[len])
			{
				dp[++len] = v[i];
			}
			else
			{

			}
		}
		cout << len << endl;
	}
}
int main(){
	//输入数据存入pair,第一个元素为积木宽w，第二个元素为积木长l
	
	int i = 0;
	int j = 0;
	int n;
	cin >> n;
	int k1 = 0;
	int k2 = 0;
	vector<int> a(n, 0);
	vector<int> dp(100001, 0);
	vector<pair<int, int>> vec;
	for (i = 0; i<n; i++){
		cin >> k1;
		cin >> k2;
		vec.push_back({ k1, k2 });
	}
	//与cmp函数配合实现以pair的第一个元素顺序升序排列
	sort(vec.begin(), vec.end(), cmp);
	for (i = 0; i<vec.size(); i++){
		a[i] = vec[i].second;
	}

	int len = 0;
	//二分+dp求最长上升子序列
	dp[1] = a[0];
	int len = 1;
	for (int i = 1; i<n; i++)
	{
		if (a[i] >= dp[len])
			dp[++len] = a[i];
		else
		{
			int j = lower_bound(dp.begin(), dp.end() ,a[i]) - dp.begin();
			dp[j] = a[i];
		}
	}
	cout << len << endl;
	return 0;
}