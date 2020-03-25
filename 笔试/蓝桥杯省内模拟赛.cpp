#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Valid(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
	{
		return true;
	}
	return false;
}

int main()
{
	string str;
	cin >> str;
	bool flag = true;

	int count = 0;
	for (int i = 0; i < str.size();)
	{
		bool flag1 = false;
		bool flag2 = false;
		while (i < str.size() && !Valid(str[i]))
		{
			i++;
			flag2 = true;
		}
		if (flag2 == true)
		{
			count++;
		}
		else
		{
			flag = false;
			break;
		}
		while (i < str.size() && Valid(str[i]))
		{
			flag1 = true;
			i++;
		}
		if (flag1 == true)
		{
			count++;
		}
		else{
			flag = false;
			break;
		}


	}
	if (flag == false || count != 4)
	{
		cout << "no" << endl;
	}
	else
		cout << "yes" << endl;


}

//
////#include <iostream>
////#include <string>
////#include <vector>
////#include <set>
////using namespace std;
////
////int main()
////{
////	int n = 0;
////	cin >> n;
////	vector<int> v(n, 0);
////	for (int i = 0; i < n; i++)
////	{
////		cin >> v[i];
////	}
////	int count = 0;
////	set<int> s;
////	if (n < 3)
////		cout << count << endl;
////	else
////	{
////		int min_ = v[0];
////		for (int i = 1; i < v.size(); i++)
////		{
////			 min_ = min_ < v[i] ? min_ : v[i];
////			for (int j = i + 1; j < v.size(); j++)
////			{
////				
////				if (min_ < v[i] && v[i] < v[j])
////				{
////					s.insert(i);
////				}
////					
////			}
////		}
////		cout << s.size() << endl;
////	}
////	system("pause");
////}
//
//
////bool Count(int k)
////{
////	int temp1 = 0;
////	int temp2 = 0;
////	int x = k;
////	while (x > 0) // 35
////	{
////		temp1 = x % 10;
////		x /= 10;
////		temp2 = x % 10;
////		if (temp2 > temp1)
////		{
////			return false;
////		}
////	}
////	return true;
////}
////int main()
////{
////	int n = 0;
////	cin >> n;
////	
////		int count = 0;
////		for (int i = 1; i <= n; i++)
////		{
////			if (Count(i))
////				count++;
////		}
////		cout << count << endl;
////	
////	
////}
//
////#include <iostream>
////#include <vector>
////#include <queue>
////using namespace std;
////
////int main()
////{
////	int n = 0;
////	int m = 0;
////	cin >> n >> m;
////	vector<vector<char>>vvc(n, vector<char>(m));
////	for (int i = 0; i < n; i++)
////	{
////		for (int j = 0; j < m; j++)
////		{
////			cin >> vvc[i][j];
////		}
////	}
////	int k = 0;
////	cin >> k;
////	queue<pair<int, int>> q;
////	for (int i = 0; i < n; i++)
////	{
////		for (int j = 0; j < m; j++)
////		{
////			if (vvc[i][j] == 'g')
////			{
////				q.push(make_pair(i, j));
////			}
////		}
////	}
////
////		static int pos[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
////	
////		while (k--)
////		{
////			int i = 0;
////			int size = q.size();
////			while (i < size)
////			{
////				pair<int, int> ptop = q.front();
////				for (int i = 0; i < 4; i++)
////				{
////					if (ptop.first + pos[i][0] >= n || ptop.first + pos[i][0] < 0
////						|| ptop.second + pos[i][1] >= m || ptop.second + pos[i][1] < 0)
////					{
////						continue;
////					}
////					else
////					{
////						q.push(make_pair(ptop.first + pos[i][0], ptop.second + pos[i][1]));
////						vvc[ptop.first + pos[i][0]][ptop.second + pos[i][1]] = 'g';
////					}
////				}
////				i++;
////				q.pop();
////			}
////		}
////
////	for (int i = 0; i < n; i++)
////	{
////		for (int j = 0; j < m; j++)
////		{
////			cout << vvc[i][j];
////		}
////		cout << endl;
////	}
////	
////}
//
////
////#include <iostream>
////#include <vector>
////#include <cmath>
////using namespace std;
////
////
////int main()
////{
////	long long count = 1200000;//96
////	vector<int> v;
////	for (int i = 2; i <= sqrt(count); i++)
////	{
////		if (count% i == 0)
////		{
////			v.push_back(i);
////		}
////	}
////	cout << v.size() << endl;
////	system("pause");
////}
//
//
////void back(vector<vector<int>>& vv, vector<int> tmp)
////{
////	vv.push_back(tmp);
////	for (int i = 1; i < abs(tmp[tmp.size() - 1] - tmp[tmp.size() -2]); i++)
////	{
////		tmp.push_back(i);
////		back(vv, tmp);
////		tmp.pop_back();
////	}
////}
////int main()
////{
////	int n = 0;
////	cin >> n;
////	vector<vector<int>> vv;
////	n = n % 10000;
////	vector<int> tmp(1, n);
////	for (int i = 1; i <= n; i++)
////	{
////		vector<int> tep(tmp);
//// 		tep.push_back(i);
////		back(vv, tep);
////	}
////	for (auto e : vv)
////	{
////		for (auto ee : e)
////		{
////			cout << ee << " ";
////		}
////		cout << endl;
////	}
////	system("pause");
////}
//
//
//
////#include <iostream>
////#include <vector>
////#include <queue>
////#include <map>
////using namespace std;
////struct Compare
////{
////	bool operator()(int a, int b)
////	{
////		return a < b;
////	}
////};
////int main()
////{
////	int n = 0;
////	int m = 0;
////	cin >> n >> m;
////	vector<int> v(n, 0);
////	for (int i = 0; i < n; i++)
////	{
////		cin >> v[i];
////	}
////	priority_queue < int, vector<int>, Compare> pq;
////	map<int, int> mymap;
////	vector<int> outcome(m);
////	for (int i = 0; i < n; i++)
////	{
////		pq.push(v[i]);
////	}
////	for (int i = 0; i < m; i++)
////	{
////		mymap[pq.top()]++;
////		pq.pop();
////	}
////	int k = 0;
////	for (int i = 0; i < v.size(); i++)
////	{
////		if (mymap.find(v[i]) != mymap.end())
////		{
////			outcome[k++] = v[i];
////			mymap.erase(v[i]);
////		}
////	}
////	for (int i = 0; i < outcome.size(); i++)
////	{
////		if (i != m - 1)
////		{
////			cout << outcome[i] << " ";
////		}
////		else
////			cout << outcome[i] << endl;
////	}
////	system("pause");
////}
////
//
//