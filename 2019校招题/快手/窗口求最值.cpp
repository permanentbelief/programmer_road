#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


#include <deque>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int x;
	vector<int>res(n);
	for (int i = 0; i<n; i++)
	{
		cin >> x;
		res[i] = x;
	}
	int w;
	cin >> w;
	deque<int>dq;
	vector<int>ans;
	for (int j = 0; j<n; j++)
	{
		if (!dq.empty())
		{
			if (j >= dq.front() + w)
				dq.pop_front();
			while (!dq.empty() && res[j] >= res[dq.back()])
				dq.pop_back();
		}
		dq.push_back(j);
		if (j + 1 >= w)
			ans.push_back(res[dq.front()]);
	}
	for (int d = 0; d<ans.size(); d++)
	{
		cout << ans[d] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}