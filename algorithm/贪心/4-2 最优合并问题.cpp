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
	int  n = 0;
	while (cin >> n)
	{
		vector<int> lens(n);
		for (int i = 0; i < n; i++)
		{
			cin >> lens[i];
		}
		sort(lens.begin(), lens.end());
		int min_ = 0;
		int max_ = 0;
		int sums = lens[0];
		for (int i = 1; i < lens.size(); i++)
		{
			sums += lens[i];
			min_ += sums - 1;
		}
		sums = lens[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			sums += lens[i];
			max_ += sums - 1;
		}
		cout << max_ << " " << min_ << endl;
	}
	system("pause");
}
/*
4
5 12 11 2
*/