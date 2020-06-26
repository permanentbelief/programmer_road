#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

const int N = 1e5 + 20;

int a[N];
int n, m;
pair<int, int> vp[N];
pair<int, int> min_p[N];

int main()
{
	int index = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
	int min_v = INT_MAX;
	//pair<int, int> min_p;
	int index1 = 0;

	for (int i = 1, j = 1; i <= n; i++)
	{
		//i是向右走的，j是后面的
		while (i <= n && j <= i && a[i] - a[j - 1] >= m)
		{
			if (a[i] - a[j - 1] >= m)
			{
				if (a[i] - a[j - 1] - m < min_v)
				{
					index1 = 0;
					min_v = a[i] - a[j - 1] - m;
					min_p[index1++] = { j, i };
				}
				else if (a[i] - a[j - 1] - m == min_v)
				{
					min_p[index1++] = { j, i };
				}
				j++;

			}
			else // ==
			{
				vp[index++] = { j, i };
				j++;
			}
		}
	}
	if (index == 0)
	for (int i = 0; i < index1; i++)
		cout << min_p[i].first << "-" << min_p[i].second << endl;
	else
	for (int i = 0; i < index; i++)
	{
		cout << vp[i].first << "-" << vp[i].second << endl;
	}
	system("pause");
	return 0;
}


