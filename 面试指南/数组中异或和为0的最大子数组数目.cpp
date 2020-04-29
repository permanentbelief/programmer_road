#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;


int mostEOR(vector<int>& arr)
{
	int ans = 0;
	int xor = 0;
	vector<int> dp(arr.size());
	map<int, int> mymap;
	mymap[0] = -1;
	for (int i = 0; i < arr.size(); i++)
	{
		xor ^= arr[i];
		if (mymap.find(xor) != mymap.end())
		{
			int pre = mymap[xor];
			dp[i] = (pre == -1 ? 1 : dp[pre] + 1);
		}
		if (i > 0)
		{
			dp[i] = max(dp[i - 1], dp[i]);
		}
		mymap[xor] = i;
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main()
{
	vector<int> v = { 0, 1, 2, 3, 0, 1, 2, 3 };
	cout << mostEOR(v) << endl;

	system("pause");
}