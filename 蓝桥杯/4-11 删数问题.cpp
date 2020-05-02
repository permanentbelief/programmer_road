#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#include <map>

//int main()
//{
//	int n = 0;
//	int k = 0;
//	while (cin >> n >> k)
//	{
//		string str = to_string(n);
//
//		//map<int,char> mymap;
//		//for (int i = 0; i < str.size(); i++)
//		//{
//		//	mymap[i] = str[i];
//		//}
//
//
//		string tmp = str;
//		sort(tmp.begin(), tmp.end());
//
//		vector<bool> books(tmp[tmp.size()-1] - '0' + 1);
//		for (int i = 0; i < str.size() - k;i++) // 1 3 4 5 6
//		{
//			books[tmp[i] - '0'] = true;
//		}
//
//		string outs;
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (books[str[i] - '0'] == true)
//			{
//				outs += str[i];
//			}
//		}
//		cout << stoi(outs) << endl;
//	}
//	system("pause");
//}