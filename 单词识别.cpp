#define _CRT_SECURE_NO_WARNINGS 1 



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;


struct CompareByValue
{
	bool operator()(const pair<int, string> &a, const pair<int, string>&b) //>    
	{
		/*if (l.first != r.first)
		{
			return l.first < r.first;
		}
		else
		{
			for (int i = 0; i < min(l.second.size(), r.second.size()); i++)
			{
				if (l.second[i] == r.second[i])
					continue;
				return l.second[i] > r.second[i];
			}
		}*/
		if (a.first != b.first){
			return a.first<b.first;
		}
		else return a.second>b.second;

	}
};
int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<string> vs;
		for (int i = 0; i < str.size(); i++)
		{
			string s;
			while (i < str.size() && str[i] != ' ' && str[i] != '.'  && str[i] != ',')
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
				{
					str[i] += 32;
				}
				s += str[i];
				i++;
			}
			if (!s.empty())
			vs.push_back(s);
		}
		map<string, int> m;
		for (auto e : vs)
		{
			m[e]++;
		}
		priority_queue<pair<int, string>, vector<pair<int, string>>, CompareByValue> pq;
		for (auto e : m)
		{
			pq.push(pair<int, string>(e.second, e.first));
		}
		int n = pq.size();
		for (int i = 0; i < n; i++)
		{
			cout << pq.top().second << ":" << pq.top().first << endl;
			pq.pop();
		}
		

	}
}