#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int N = 1e6;
int a[N];
int f[N];
string s[N];
map<int, string> idtoname;
map<string, int> nametoid;

string father;
string son;
int idx;

void init()
{
	for (int i = 1; i < N; i++)
	{
		f[i] = i;
	}
}
int find(int x)
{
	if (x == f[x])
		return x;
	return f[x] = find(f[x]);
}
int main()
{
	string buf;
	init();
	while (getline(cin, buf) && buf != "$")
	{
		if (buf[0] == '#')
		{
			father = buf = buf.substr(1);

			if (!nametoid.count(buf))
			{
				idtoname[idx] = buf;
				nametoid[buf] = idx++;
			}
			else
				idx++;

		}
		else if (buf[0] == '+')
		{
			son = buf = buf.substr(1);

			// idtoname[idx] = buf;
			// nametoid[buf] = idx++;


			if (!nametoid.count(buf))
			{
				nametoid[buf] = idx;
				idtoname[idx++] = buf;

			}
			else
				idx++;
			int fs = find(nametoid[son]);
			int ff = find(nametoid[father]);
			if (fs != ff)
				f[fs] = ff;
		}
		else
		{
			buf = buf.substr(1);
			cout << buf << " " << idtoname[find(nametoid[buf])] << endl;
		}
	}
}