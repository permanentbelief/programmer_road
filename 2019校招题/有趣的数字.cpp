#define _CRT_SECURE_NO_WARNINGS 1 


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;



int main()
{
	int n = 0;
	while (cin >> n)
	{
		map<int, int> um;
		vector<int> v(n, 0);
		int max_ = INT_MIN;
		int min_ = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			um[v[i]]++;
		}
		sort(v.begin(), v.end());

		if (v[0] == v[n - 1])
		{
			int tmp = (n*(n - 1)) / 2;
			cout << tmp << " " << endl;
			continue;
		}

		int minres = 0;
		if (n == um.size())
		{
			int min_ = v[1] - v[0];
			for (int i = 1; i < n - 1; i++)
			{
				int tmp = v[i] - v[i - 1];
				if (tmp <= min_)
				{
					if (tmp == min_)
					{
						minres++;
					}
					else
					{
						min_ = tmp;
						minres = 1;
					}
				}
			}

		}
		else
		{
			for (auto e : um)
			{
				if (e.second > 1)
				{
					minres += (e.second * (e.second - 1)) / 2;

				}
			}
		}
		int maxres = 0;
		int val1 = um[v[v.size() - 1]];
		int val2 = um[v[0]];
		maxres = (val1 * val2);
		cout << minres << " " << maxres << endl;

	}
}



