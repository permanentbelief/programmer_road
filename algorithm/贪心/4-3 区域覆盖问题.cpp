#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


int main()
{
	int n = 0;
	int windows = 0;
	while (cin >> n >> windows)
	{
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int widths = v[n - 1] - v[0] + 1;
		int outs = 0;
		if (widths % windows == 0)
		{
			outs = widths / windows;
		}
		else
		{
			outs = widths / windows + 1;
		}
		cout << outs  << endl;
	}

	system("pause");
}