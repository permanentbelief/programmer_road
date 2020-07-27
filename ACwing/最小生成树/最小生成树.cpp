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
//typedef pair<int, int> PII;
//
//
//const int  N = 1e4 + 100;
//const int M = 1e5 + 20;
//int f[N];
//PII a[N];
//int u, v, w, n, m;
//int q[N];
//
//struct edges
//{
//	int u, v;
//	double w;
//	bool operator<(edges& e)
//	{
//		return w < e.w;
//	}
//}e[M];
//int idx;
//
//
//int find(int x)
//{
//	if (x == f[x])
//		return f[x];
//	return f[x] = find(f[x]);
//}
//double dis(PII& a, PII&b)
//{
//		return (double)sqrt((double)(a.first - b.first)*(a.first - b.first) + (double)(a.second - b.second)
//			*(a.second - b.second));
//}
//int main()
//{
//	cin >> n >> m;
//	double sum = 0.0;
//	for (int i = 1; i <= n; i++)
//	{
//		f[i] = i;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i].first >> a[i].second;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j < i; j++)
//		{
//			double d = dis(a[i], a[j]);
//			e[++idx].u = i;
//			e[idx].v = j;
//			e[idx].w = d;
//		}
//	}
//
//
//	for (int i = 1; i <= m; i++)
//	{
//		int a = 0, b = 0;
//		cin >> a >> b;
//		e[++idx].u = a;
//		e[idx].v = b;
//		e[idx].w = 0.0;
//	}
//	int cnt = 0;
//	sort(e + 1, e + idx + 1);
//
//	for (int i = 1; i < idx; i++)
//	{
//		int s = e[i].u;
//		int en = e[i].v;
//		int find_e = find(en);
//		int find_s = find(s);
//		if (find_e != find_s)
//		{
//			f[find_e] = find_s;
//			sum += e[i].w;
//			cnt++;
//		}
//		if (cnt == n - 1)
//			break;
//	}
//	printf("%lf\n", sum);
//	system("pause");
//}




using namespace std;

typedef pair<int, int> PII;


const int  N = 1e4 + 100;
const int M = 1e5 + 20;
int f[N];
PII a[N];
int u, v, w, n, m;
int q[N];

struct edges
{
	int u, v;
	double w;
	bool operator<(edges& e)
	{
		return w < e.w;
	}
}e[M];
int idx;


int find(int x)
{
	if (x == f[x])
		return f[x];
	return f[x] = find(f[x]);
}
double dis(PII a, PII b)
{
	return sqrt((double)(a.first - b.first)*(a.first - b.first) + (double)(a.second - b.second)
		*(a.second - b.second));
}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		f[i] = i;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> q[i];
//	}
//	cin >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int c = 0, b = 0;
//		cin >> c >> b;
//		a[i + 1].first = c;
//		a[i + 1].second = b;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j < i; j++)
//		{
//			e[++idx].u = i;
//			e[idx].v = j;
//			double d = dis(a[i], a[j]);
//			e[idx].w = d;
//		}
//	}
//
//	int ans = 0;
//	double tmp;
//	sort(e + 1, e + idx + 1);
//	for (int i = 1; i <= idx; i++)
//	{
//		int a = find(e[i].u);
//		int b = find(e[i].v);
//		if (a != b)
//		{
//			f[a] = b;
//			ans++;
//		}
//		if (ans == n - 1)
//		{
//			tmp = e[i].w;
//			break;
//		}
//	}
//	ans = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (q[i] >= tmp)
//		{
//			ans++;
//		}
//	}
//	cout << ans << endl;
//	system("pause");
//}







 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string str;
		queue<TreeNode*> q;
		q.push(root);
		while (q.size())
		{
			int sz = q.size();
			while (sz--)
			{
				auto node = q.front();

				if (node == nullptr)
					str += "null,";
				else
				{
					str += to_string(node->val);
					str += ",";
					q.push(node->left);
					q.push(node->right);
				}
				q.pop();
			}

		}
		//  cout << str << endl;
		return str;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		vector<string> nodes = split(data);
		if (nodes.empty() || nodes[0] == "null")
			return nullptr;

		queue<TreeNode*> re;
		TreeNode* node = new TreeNode(stoi(nodes.front()));
		re.push(node);


		// 10  下标是9
		// 10  下标是 i+1 < 10 i < 9  i能取到8
		for (int i = 0; i < nodes.size() - 1;)
		{
			if (nodes[++i] != "null")
			{
				re.front()->left = new TreeNode(stoi(nodes[i]));
				re.push(re.front()->left);
			}
			if (nodes[++i] != "null")
			{
				re.front()->right = new TreeNode(stoi(nodes[i]));
				re.push(re.front()->right);
			}
			re.pop();
		}

		return node;
	}
	vector<string> split(const string& str) {
		vector<string> result;
		size_t begin = 0;
		size_t end = 0;
		while (1) {
			end = str.find(',', begin);
			if (end == string::npos) {
				break;
			}
			result.emplace_back(str.substr(begin, end - begin));
			begin = end + 1;
		}
		return result;
	}


};

//class Solution {
//public:
//	vector<int> exclusiveTime(int m, vector<string>& logs) {
//		vector<pair<int, int>> vp(logs.size() / 2);
//		for (int i = 0; i < logs.size(); i++)
//		{
//			auto indx = find(logs[i].begin(), logs[i].end(), ':') - logs[i].begin();
//			
//			int id = stoi(logs[i].substr(0, indx));
//
//			indx = find(logs[i].rbegin(), logs[i].rend(), ':') - logs[i].begin();
//				int tim = stoi(logs[i].substr(indx + 1));
//			indx = find(logs[i].begin(), logs[i].end(), "start") - logs[i].begin();
//			if (idx == -1)
//			{
//				vp[id].second = tim;
//			}
//			else
//				vp[id].first = tim;
//
//		}
//		for (auto e : vp)
//		{
//			cout << e.first << " " << e.second << endl;
//		}
//
//		return vector<int>();
//	}
//};

class A
{
public:
	void func()
	{
		cout << "dada" << endl;
	}
	void func1()
	{
		_c = 20;
	}
public:
	int _c = 10;
};

int main()
{
	cout << sizeof(A) << endl;
	A* ptr = nullptr;
	ptr->func1();
	cout << sizeof(ptr) << endl;
	vector<int> v = { 1, 3, 5, 4 };
	vector<int> index(v.size());
	for (int i = 0; i < v.size(); i++)
	{
		index[i] = v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << index[i] << endl;
	}

	cout << index[0] << endl;
	//int tim = stoi(str.substr(indx + 1)); 
	
	system("pause");
}