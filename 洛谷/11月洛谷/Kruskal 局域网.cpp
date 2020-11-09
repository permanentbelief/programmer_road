#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


const int N = 5e4 + 20;
int f[N];

map<string, int> m;
map<int, string> intos;

int find(int x)
{
	if (x == f[x])
		return f[x];
	return f[x] = find(f[x]);
}

int main()
{
	string res;
	string str;
	int i = 1;

	for (int j = 1; j <= N; j++)
	{
		f[j] = j;
	}
	while (cin >> str, str != '$')
	{
		if (str[0] == '#')
		{
			str = str.substr(1);
			res = str;
			if (!m.count(str))
			{
				m[str] = i;
				intos[i] = str;
			}
		}
		else if (str[0] == '+')
		{
			str = str.substr(1);
			if (!m.count(str))
			{
				m[str] = i;
				intos[i] = str;
			}
			int one = find(m[str]);
			int two = find(m[res]);
			if (find(one) != find(two))
			{
				f[find(one)] = find(two);
			}
		}
		else
		{
			str = str.substr(1);
			cout << str << " " << intos[find(m[tmp])];
		}
		i++;
	}
	return 0;
}