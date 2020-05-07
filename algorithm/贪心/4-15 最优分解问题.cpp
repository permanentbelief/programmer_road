#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		int i = 2;
		vector<int> v;
		
		// 9 2 7 3 4 4
		while (n >= i)
		{
			n -= i;
			v.push_back(i);
			i++;
		}

		int dif = n;
		int index = 0;
		for (int i = v.size() - 1; i >= 0; i--)
		{
			v[i]++;
			index++;
			if (index == dif)
				break;
			if (i == 0)
				i = v.size();
		}

		int count = 1;
		for (int i = 0; i < v.size(); i++)
		{
			count *= v[i];
		}
		cout << count << endl;
	}

}