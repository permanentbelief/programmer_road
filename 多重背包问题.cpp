#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;



//int main()
//{
//	int n = 0, v = 0;
//	cin >> n; cin >> v;
//
//	vector<int> m(n);
//	vector<int> w(n);
//	vector<int> s(n);
//	vector<int> dp(v + 1);
//	for (int i = 0; i<n; i++)
//		cin >> m[i] >> w[i] >> s[i];
//
//	for (int i = 0; i<n; i++) {
//		for (int j = v; j >= w[i]; j--) {
//			for (int k = 0; k <= m[i] && k*w[i] <= j; k++) {
//				dp[j] = max(dp[j], dp[j - k*w[i]] + k* s[i]);
//			}
//		}
//	}
//
//	cout << dp[v] <<endl;
//}


int countWays(int n) {
	// write code here
	int cur = 1;
	int cur1 = 2;
	for (int i = 3; i <= n; i++)
	{
		int sum = (cur1 + cur) % 1000000007;
		cur = cur1;
		cur1 = sum;
	}
	return cur1;
}
int main()
{
	vector<int> v = { 5, 10, 25, 1 };
	cout << countWays(10) << endl;
	system("pause");
}