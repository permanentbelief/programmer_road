#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <functional>
using namespace std;




#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <climits>
using namespace std;
const int N = 1e5 + 20;
struct Node
{
	string name;
	vector<string> children;
	bool operator < (Node a) const
	{
		return name > a.name;
	}
}node[N];
map<string, Node> sN;
map<string, int> mymap;
bool vis[N];
vector<string> outs;
map<string, int> counts;
vector<string> vs;
vector<string> splits(string str)
{
	vector<string> vs;
	int start = 1;
	string res;
	bool flag = false;
	while (1)
	{
		int k = str.find(",");
		if (k == -1)
		{
			if (flag == false)
				vs.push_back(str.substr(1, str.size() - 2));
			else
			{
				vs.push_back(str.substr(0, str.size() - 1));
			}
			break;
		}
		flag = true;
		vs.push_back(str.substr(start, k - 1));
		str = str.substr(k + 1);
		start = k;
	}
	return vs;
}
int main()
{
	int n = 0;
	cin >> n;
	string str;
	getchar();
	for (int i = 1; i <= n; i++)
	{
		getline(cin, str);
		int index = 0;
		for (int k = 0; k < str.size(); k++)
		{
			if (str[k] == '(')
			{
				index = k;
				break;
			}
		}
		string src = str.substr(0, index);
		vs = splits(str.substr(index));
		if (!mymap.count(src))
		{
			mymap[src] = 0;
		}
		for (int i = 0; i < vs.size(); i++)
		{
			if (vs[i] != "NULL")
			{
				mymap[vs[i]]++;
			}
			else
				break;
		}
		node[i].children = vs;
		node[i].name = src;
		sN[src] = node[i];
	}
	priority_queue<Node> q;
	for (int i = 1; i <= n; i++)
	{
		if (mymap[node[i].name] == 0)
		{
			q.push(node[i]);
		}
	}

	while (q.size())
	{
		auto tmp = q.top();
		q.pop();
		outs.push_back(tmp.name);
		for (int i = 0; i < tmp.children.size(); i++)
		{
			mymap[tmp.children[i]]--;
			if (mymap[tmp.children[i]] == 0)
			{
				q.push(sN[tmp.children[i]]);
			}
		}
	}
	for (auto e : outs)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
}