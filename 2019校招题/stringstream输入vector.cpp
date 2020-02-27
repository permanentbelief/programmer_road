#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;


int main()
{
	int num;
	string s;
	vector<int>v;
	getline(cin, s);
	stringstream input(s);
	while (input >> num)
		v.push_back(num);
	int len = v.size();
	int flag = 0;
	if (len <= 1)
	{
		cout << 1 << endl;
		return 0;
	}
	for (int i = 1; i<len; i++)
	{
		if (v[i]<v[i - 1])
			flag++;
	}
	if (flag <= 1)
		cout << 1 << endl;
	else
		cout << -1 << endl;


	return 0;
}