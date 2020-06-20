//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//#include <iostream>
//#include <string>
//#include <unordered_map>
//
//using namespace std;
//
//int father[10005];
////       借助两个unordered_map 来对int 和string的转换
//unordered_map<string, int> name2idx;
//unordered_map<int, string> idx2name;
//
//string Data;
//string cur_f, cur_son;
//
//int find_father(int x)
//{
//	if (x != father[x])
//	{
//		father[x] = find_father(father[x]);
//	}
//	return father[x];
//
//}
//int main()
//{
//	int idx = 1;
//	while (1)
//	{
//		cin >> Data;
//		if (Data[0] == '#')
//		{
//			cur_f = string(Data.begin() + 1, Data.end());
//			if (name2idx.count(cur_f) == false)
//			{
//				father[idx] = idx;
//				name2idx[cur_f] = idx;
//				idx2name[idx] = cur_f;
//				idx++;
//			}
//		}
//
//		if (Data[0] == '+')
//		{
//			cur_son = string(Data.begin() + 1, Data.end());
//			if (name2idx.count(cur_son) == false)
//			{
//				name2idx[cur_son] = idx;
//				idx2name[idx] = cur_son;
//				idx++;
//			}
//
//			father[name2idx[cur_son]] = name2idx[cur_f];
//		}
//		if (Data[0] == '?')
//		{
//			string cur(Data.begin() + 1, Data.end());
//			cout << cur << " ";
//			cout << idx2name[find_father(name2idx[cur])] << endl;
//		}
//		if (Data[0] == '$')
//			return 0;
//	}
//	return 0;
//}