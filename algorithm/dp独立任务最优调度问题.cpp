//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//
#define _CRT_SECURE_NO_WARNINGS 1 



#include<algorithm>
#include<string.h>
#include<iostream>
#include<stdlib.h>

using namespace std;
int c[201], b[201];
int n;
int dp[202][10000];
int main() {
	cin >> n;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += c[i];
		for (int j = 0; j <= sum; j++) {
			dp[i][j] = dp[i - 1][j] + b[i];  // b所花费的时间
			if (j >= c[i]) dp[i][j] = min(dp[i - 1][j] + b[i], dp[i - 1][j - c[i]]);
		}
	}
	int ans = 999999;
	for (int i = 0; i <= sum; i++)ans = min(ans, max(dp[n][i], i));
	cout << ans << endl;
	system("pause");
}
///*
//6
//2 5 7 10 5 2
//3 8 4 11 3 4
//*/