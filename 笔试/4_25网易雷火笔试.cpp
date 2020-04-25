#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <sstream>
#include <map>
using namespace std;


#define MOD 1000009



vector<string> Get(string& str)
{
	string tmp;
	string prev;
	for (int i = 0; i < str; i++)
	{
		while (i < str.size() && str[i] != ' ')
		{
			prev += str[i];
			i++;
		}
		if (str[i] == ' ')
			i++;
		tmp += str[i];
	}
	return{ prev, tmp };
}
int main()
{
	int n = 0;
	int m = 0;
	int s = 0;
	cin >> n >> m;
	string str;
	string windowsname;
	string windowstype;
	map<string, string> mymap;
	for (int i = 0; i < n; i++)
	{
		cin >> windowsname >> windowstype;
		mymap[windowsname] = windowstype;
	}
	cin >> s;
	for (int i = 0; i < s; i++)
	{
		getline(cin, str);
		string type = mymap[Get(str)[i]];
		if (type == "NormalWindow")//显示的时候
		{

		}
		else if (type == "FullWindow") //显示的时候吧后面盖住
		{

		}
		else if (type == "PopWindow") //显示最顶层
		{

		}
	}




}

//
//bool Valid(string& str, int X)
//{
//	for (int i = 0; i < str.size() - 2; i++)
//	{
//		
//		int sum = str[i] + str[i + 1] + str[i + 2];
//		if (sum % X != 0)
//			return false;
//	}
//	return true;
//}
//void dfs(vector<string>& vs,string &str, string tmp, int& count, int sum, int& S, int& N, int& X)
//{
//	if (tmp.size() == N)
//	{
//		if (sum == S )
//		{
//			if (Valid(tmp, X))
//			{
//				count++;
//				vs.push_back(tmp);
//				count %= MOD;
//			}
//
//		}
//			
//		return;
//	}
//	for (int i = 0; i < str.size(); i++)
//	{
//		tmp += str[i];
//		sum += str[i] - '0';
//		dfs(vs,str, tmp, count, sum, S, N, X);
//		sum -= str[i] - '0';
//		tmp.pop_back();
//	}
//}
//int main()
//{
//	int N = 0;
//	int S = 0;
//	int X = 0;
//	while (cin >> N >> S >> X)
//	{
//		string str = "0123456789";
//		int count = 0;
//	/*	dfs(str, "", count, 0, S, N, X);
//		cout << count << endl;*/
//		vector<string> vs;
//
//		dfs(vs, str, "", count, 0, S, N, X);
//		cout << count << endl;
//		for (auto e : vs)
//		{
//			cout << e << endl;
//		}
//	}
//}
//


//struct Point
//{
//	int _x;
//	int _y;
//	int _z;
//};
//// lambuda表达式要熟练
//
//
//int main()
//{
//	int N = 0;
//	while (cin >> N)
//	{
//		getchar();
//		int x = 0;
//		int y = 0;
//		int z = 0;
//		vector<Point> vp;
//		//vector<int> X(N);
//		//vector<int> Y(N);
//		//vector<int> Z(N);
//		for (int i = 0; i < N; i++)
//		{
//			scanf("%d %d %d", &x, &y, &z);
//			vp.push_back({ x, y, z });
//		};
//		int count1 = 0;
//		int count2 = 0;
//		int count3 = 0;
//		sort(vp.begin(), vp.end(), [](Point& a, Point&b)
//		{
//			return a._x < b._x;
//		});
//		for (int i = 0; i < N - 1; i++)
//		{
//			for (int j = i + 1; j < N; j++)
//			{
//				if (vp[j]._x == vp[i]._x + 1 && vp[i]._y == vp[j]._y
//					&& vp[j]._z == vp[i]._z)
//				{
//					count1++;
//				}
//			}
//
//		}
//		sort(vp.begin(), vp.end(), [](Point& a, Point&b)
//		{
//			return a._y < b._y;
//		});
//		for (int i = 0; i < N - 1; i++)
//		{
//			for (int j = i + 1; j < N; j++)
//			{
//				if (vp[j]._y == vp[i]._y + 1 && vp[i]._x == vp[j]._x
//					&& vp[j]._z == vp[i]._z)
//				{
//					count2++;
//				}
//			}
//
//		}
//		sort(vp.begin(), vp.end(), [](Point& a, Point&b)
//		{
//			return a._z < b._z;
//		});
//		for (int i = 0; i < N - 1; i++)
//		{
//			for (int j = i + 1; j < N; j++)
//			{
//				if (vp[j]._z == vp[i]._z + 1 && vp[i]._x == vp[j]._x
//					&& vp[j]._y == vp[i]._y)
//				{
//					count3++;
//				}
//			}
//			
//		}
//		long long  outs = (count1 + count2 + count3) * 2;
//		long long out = (long long)N * 6 - outs;
//		cout << out << endl;
//
//	}
//
//}
//


//long long stol(string& str)
//{
//	stringstream ss;
//	long long res = 0;
//	ss << str;
//	ss >> res;
//	res %= MOD;
//	return res;
//	
//}