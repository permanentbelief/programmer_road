#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// O(N*lgN)
vector<int> getdp2(vector<int>& arr)
{
	vector<int> dp(arr.size());
	vector<int> ends(arr.size());
	ends[0] = arr[0];
	dp[0] = 1;
	int right = 0;
	int l = 0;
	int r = 0;
	int m = 0;
	for (int i = 1; i < arr.size(); i++)
	{
		l = 0;
		r = right;
		while (l <= r)
		{
			m = (l + r) / 2;
			if (arr[i]  > ends[m])
				l = m + 1;
			else
			{
				r = m - 1;
			}
		}
		right = max(right, l);
		ends[l] = arr[i];
		dp[i] = l + 1;
	}
	return dp;
}
int main()
{
	vector<int> arr = { 2, 1, 5, 3, 6, 4, 8, 9, 7 };
	vector<int> out = getdp2(arr);
	for (auto & e : out)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
}

//int main()
//{

	//普通的N*N
	//int n = 0;
	//while (cin >> n)
	//{
	//	vector<int> v(n);
	//	for (int i = 0; i < n; i++)
	//	{
	//		cin >> v[i];
	//	}
	//	int mmax = 1;
	//	vector<int> dp(n, 1);
	//	for (int i = 0; i < n; i++)
	//	{
	//		for (int j = 0; j < i; j++)
	//		{
	//			if (v[j] < v[i])
	//				dp[i] = max(dp[i], dp[j] + 1);
	//		}
	//		mmax = max(mmax, dp[i]);
	//	}

	/*	返回整个递增数组
		int len = 0;
		int index = 0;
		for (int i = 0; i < dp.size(); i++)
		{
			if (dp[i] > len)
			{
				len = dp[i];
				index = i;
			}
		}
		vector<int> list(len, 0);
		list[--len] = v[index];
		for (int i = index; i >= 0; i--)
		{
			if (v[i] < v[index] && dp[i] == dp[index] - 1)
			{
				list[--len] = v[i];
				index = i;
			}
		}
		return list;
		*/


//	}
//}