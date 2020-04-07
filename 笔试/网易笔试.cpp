#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	int s = 0;
//	while (cin >> n >> m >> s)
//	{
//		map<int, int> mymap;
//		int ans = 0;
//		bool flag = false;
//		for (int i = 0; i < m; i++)
//		{
//			int a = 0;
//			int b = 0;
//			cin >> a >> b;
//			if (flag == false && a == 0 && b == s)
//			{
//				ans = i + 1;
//				flag = true;
//			}
//			if (flag == false && (a == s || b == s))
//			{
//				if (mymap.find(s) != mymap.end())
//				{
//					ans = i + 1;
//					flag = true;
//				}
//				else
//				{
//					if (flag == false && a == s)
//					{
//						mymap[a] = b;
//					}
//					else if (flag == false && b == s)
//					{
//						mymap[b] = a;
//					}
//				}
//
//			}
//			if (!flag)
//				ans++;
//		}
//		if (flag == false && ans == m )
//		{
//			ans = 0;
//		}
//		cout << ans << endl;
//	}
//}

//#include <iostream>
//#include <vector>
//#include <unordered_set>
//
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	int f = 0;
//
//	while (cin >> n >> m >> f)
//	{
//		//set<int> s;
//		unordered_set<int> s_;
//		s_.insert(f);
//		int q = 0;
//		for (int i = 0; i < m; i++)
//		{
//			cin >> q;
//			vector<int> v(q);
//			bool flag = false;
//			for (int j = 0; j < q; j++)
//			{
//				cin >> v[j];
//				if (s_.find(v[j]) != s_.end())
//				{
//					flag = true;
//				}
//			}
//			if (flag)
//			{
//				for (int k = 0; k < q; k++)
//				{
//					s_.insert(v[k]);
//				}
//			}
//
//		}
//		cout << s_.size() << endl;
//	}
//}

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int stoi(string& str)
{
	stringstream s;
	int tmp;
	s << str;
	s >> tmp;
	return tmp;
}
int check(string tmp, int k)
{
	//int a1 = 0;
	//int a2 = 0;
	long long a1 = 0;
	long long a2 = 0;
	int count = 0;
	for (int i = 0; i < tmp.size(); i++)
	{
		for (int j = 1 ; j <= tmp.size()- i; j++)
		{
			if (stoi(tmp.substr(i, j)) % k == 0)
				count++;
		}
	}
	if (count == ( tmp.size()* (tmp.size() + 1))/2 )
		return 1;
	return 0;
}
void DFS(string tmp, long long& ans, int n, int& k)
{
	if (tmp.size() >= 2)
	{
		if (tmp.size() == n)
		{
			ans += check(tmp, k);
			return;
		}
		else
		{
			ans += check(tmp, k);
			ans += 1;
		}
	}

	for (int i = 1; i <= 9; i++)
	{
		tmp.push_back(i + '0');
		DFS(tmp, ans, n, k);
		tmp.pop_back();
	}
}
int main()
{
	int m = 0;

	while (cin >> m)
	{
		int n = 0;
		int k = 0;
		for (int i = 0; i < m; i++)
		{
			cin >> n >> k;
			string str;
			long long ans = 0;
			DFS("", ans, n, k);
			cout << ans % 1000000007 << endl;
		}
	}
}


//1 4 2