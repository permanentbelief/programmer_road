#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//
//using namespace std;
//
//const int M = 1e5 + 100;
//const int N = 2e4 + 200;
//
//int n;
//int cnt[M];
//int son[M][26];
//char str[N];
//int idx;
//
//void insert()
//{
//	int p = 0;
//	for (int i = 0; str[i]; i++)
//	{
//		int& s = son[p][str[i] - 'a'];
//		if (!s) s = ++idx;
//		p = s;
//	}
//	cnt[p]++;
//}
//int query()
//{
//	int res = 0;
//	int p = 0;
//	for (int i = 0; str[i]; i++)
//	{
//		int &s = son[p][str[i] - 'a'];
//		if (!s) break;
//		p = s;
//		res += cnt[p];
//
//	}
//	return res;
//}
//int main()
//{
//	cin >> n;
//	getchar();
//	while (n--)
//	{
//
//			char tmp;
//			cin >> tmp;
//		if (tmp == 'I')
//		{
//			scanf("%s\n", str);
//			insert();
//		}
//		else
//		{
//			printf("%d\n", query());
//		}
//	}
//}

/*
using namespace std;

const int N = 1e5 + 200;

const int M = N * 32;

int a[M][2];

int n;
int cnt;
int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
int t[N];

void add(int a, int b, int c)
{
	e[idx] = b;
	ne[idx] = h[a];
	w[idx] = c;
	h[a] = idx++;
}

void dfs(int u, int father, int sum)
{
	t[u] = sum;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (j != father)
		{
			dfs(j, u, sum ^ w[j]);
		}
	}
}
void insert(int x)
{
	int p = 0;
	for (int i = 30; ~i; i--)
	{
		int &c = a[p][n >> i & 1];
		if (!c) c = ++cnt;
		p = cnt;
	}
}
int query(int n)
{
	int p = 0;
	int res = 0;
	for (int i = 30; ~i; i--)
	{
		int c = n >> i & 1;
		if (a[p][!c])
		{
			res += 1 << i;
			p = a[p][!c];
		}
		else
		{
			p = a[p][c];
		}
	}
	return res;
}
int main()
{
	cin >> n;
	memset(h, -1, sizeof(h));
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	dfs(0, -1, 0);
	for (int i = 1; i <= n; i++)
	{
		insert(t[i]);

	}
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res = max(res, query(t[i]));
	}
	cout << res << endl;

	system("pause");
}


*/







/*
#include <bits/stdc++.h>


using namespace std;

const int N = 1e6 +200;
const int M = 1e5 + 200;

char str[1000001];
int idx;
int son[N][26];
int cnt[1000001];

int insert()
{
int p = 0;
for(int i = 0; str[i]; i++)
{
int &s = son[p][str[i]- 'a'];
if(!s) s = ++idx;
p = s;
// if(cnt[p] == 0)
}
cnt[p] = 1;

// if(flag1 == false) return
}
int check()
{
long long sum = 0;
int p = 0;
for(int i = 0; str[i]; i++)
{
int s = son[p][str[i] - 'a'];
if(!s)
{
return 2;
}
p = s;
}
if(cnt[p] == 1)
{
cnt[p] = 2;
return 0;
}
return 1;

}

int main()
{
int n;
scanf("%d",&n);
for(int i=1;i<=n;i++){
scanf("%s",str);
insert();
}
int m;
scanf("%d",&m);
for(int i=1;i<=m;i++){
scanf("%s",str);
int cx=check();
if(cx==2)
printf("WRONG");
else if(cx==1)
printf("REPEAT");
else
printf("OK");
printf("\n");//每一次输出要换行
}
return 0;
}
*/
//#include <bits/stdc++.h>
//
//
//using namespace std;
//
//const int N = 5e4 + 1000;
//const int M = 5e5 + 1000;
//int size1;
//int n, m, cnt[M];
//int idx;
//int a[M];
//int son[M][10];
//int sums[M];
//
//
//void insert()
//{
//	int p = 0;
//	for (int i = 0; i < size1; i++)
//	{
//		int& s = son[p][a[i]];
//		if (s == -1) s = ++idx;
//		p = s;
//		sums[p]++; // 经过该节点的字符串个数
//	}
//	cnt[p]++; // 以p结尾的字符串个数
//}
//
//int query()
//{
//	int sum = 0;
//	int p = 0;
//	for (int i = 0; i < size1; i++)
//	{
//		int s = son[p][a[i]];
//		if (s == -1) return sum;
//
//		p = s;
//		sum += cnt[p];
//	}
//	return sum + sums[p] - cnt[p]; //加上前缀相同，且长度比他长的字符串个数
//}
//int main()
//{
//	cin >> n >> m;
//	memset(son, -1, sizeof(son));
//	while (n--)
//	{
//		cin >> size1;
//		for (int i = 0; i < size1; i++)
//		{
//			cin >> a[i];
//
//		}
//		insert();
//	}
//	while (m--)
//	{
//		cin >> size1;
//		for (int i = 0; i < size1; i++)
//		{
//			cin >> a[i];
//		}
//		cout << query() << endl;
//	}
//
//	return 0;
//}
//
//
//

#include <map>
class Solution {
public:
	struct TreeNode
	{
		TreeNode* next[26];
		int _val;
		TreeNode(int val)
			:_val(val)
		{
			for (int i = 0; i < 26; i++)
			{
				next[i] = nullptr;
			}
		}
	};
	vector<int> cnt;
	map<TreeNode*, string> m;

	TreeNode* root = new TreeNode(-1);
	void insert(string str)
	{
		TreeNode* p = root;
		for (int i = 0; i < str.size(); i++)
		{
			int t = str[i] - 'a';
			if (p->next[t] == nullptr)
				p->next[t] = new TreeNode(-1);
			p = p->next[t];
		}
		//cnt[str[str.size() - 1] - 'a']++;
		m[p] = str;
	}
	string query(string str)
	{
		TreeNode* p = root;
		for (int i = 0; i < str.size(); i++)
		{
			int t = str[i] - 'a';
			if (p->next[t] == nullptr)
			{
				if (m.count(p))
					return m[p];
				else
					return " ";
			}
			p = p->next[t];
		}
		return " ";
	}
	string query1(string str)
	{
		TreeNode* cur = root;
		for (int i = 0; i < str.size(); i++)
		{
			int c = str[i] - 'a';
			if (cur->next[c] == nullptr) return " ";
			// if(cur->next[c].isEnd == true) return str.substr(0,i + 1);
			if (m.count(cur->next[c])) return str.substr(0, i + 1);

			cur = cur->next[c];
		}
		return " ";
	}
	string replaceWords(vector<string>& dict, string sentence) {
		cnt.resize(dict.size());

		for (int i = 0; i < dict.size(); i++)
		{
			insert(dict[i]);
		}
		vector<string> vs;
		for (int i = 0; i < sentence.size(); i++)
		{
			string str;
			while (i < sentence.size() && sentence[i] != ' ')
			{
				str += sentence[i];
				i++;
			}
			vs.push_back(str);
		}
		for (int i = 0; i < vs.size(); i++)
		{
			string str = query1(vs[i]);
			if (str != " ")
				vs[i] = str;
		}

		string result;

		for (int i = 0; i < vs.size(); i++)
		{
			result += vs[i];
			if (i < vs.size() - 1)
				result += ' ';
		}
		return result;
	}
};
int main()
{
	vector<string> dict = { "slsld", "qwyodu", "iyuszyz", "cfqhmg", "ais"};
	string sent = "cgzcbnnoqgfx dhkhuromvh buasablfqcwlfzbfy our isdufv";
	Solution s;
	s.replaceWords(dict, sent);

	system("pause");
}