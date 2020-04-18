//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include<iostream>
//#include<algorithm>
//#include<string>
//#include <map>
//#include <vector>
//#include <set>
//using namespace std;
//
////保存图,如果字符i在字符j前，那么存在i到j的路径，即map[i][j]=  1
//vector<vector<int>> mymap(26, vector<int>(26));
//// 保存每个节点的入度
//vector<int> indegree(26);
//
////记录出现过的字符
//vector<bool> flag(26);
//set<char> myset;
//
////保存结果
//vector<char> ans;
//
//
//void build(vector<string>& vs)
//{
//	//找到两个相邻的字符串，第一个不相同的字符就可以确定字符的顺序
//	// 如找到wrt和wrf就可以找到 t->f
//	string pre = vs[0];
//	for (auto c : pre)
//	{
//		myset.insert(c);
//	}
//	for (int i = 1; i < vs.size(); i++)
//	{
//		string cur = vs[i];
//		for (char c : cur)
//		{
//			myset.insert(c);
//		}
//		for (int j = 0; j < min(pre.size(), cur.size()); j++)
//		{
//			if (pre[j] == cur[j]) //相同则继续
//				continue;
//			if (mymap[pre[j] - 'a'][cur[j] - 'a'] == 1) //如果有这条路径,不用添加直接break
//				break;
//			mymap[pre[j] - 'a'][cur[j] - 'a'] = 1; // 从i有到j的路径
//			indegree[cur[j] - 'a'] += 1; //节点的入度 +1
//			flag[pre[j] - 'a'] = true; // 标志这个字符出现过
//			flag[cur[j] - 'a'] = true; // 标志这个字符出现过
//			break; //因为字典序比较的是第一个比他大的，所以遇到第一个不同的字符就要break
//		}
//		pre = cur;
//	}
//}
//
//void topology()
//{
//	while (ans.size() < myset.size())
//	{
//		//是否在一个遍历中找到入度为0的节点，如果没有找到，就要break.
//		//如果一次遍历找到两个入度为0的点，是无法确认顺序的
//		int cnt = 0;
//		for (int i = 0; i < indegree.size(); i++)
//		{
//			if (indegree[i] == 0 && flag[i])  //节点入度为0 且节点存在，在有向图中删除这个节点和从这个节点出发的边
//				cnt++;
//		}
//		if (cnt != 1)
//			break;
//
//		//找没有入度的节点加入序列，在有向图中删除这个节点和从这个节点出发的边
//
//		for (int i = 0; i < indegree.size(); i++)
//		{
//			if (indegree[i] == 0 && flag[i])
//			{
//				ans.push_back((char)(i + 'a'));
//				flag[i] = false; //删除节点，标记处未出现过
//				for (int j = 0; j < 26; j++) // 删除从这个节点出发的边
//				{
//					if (mymap[i][j] == 0)
//						continue;
//					indegree[j]--;
//					mymap[i][j] = 0;
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		vector<string>vs;
//
//		for (int i = 0; i < str.size(); i++)
//		{
//			string tmp;
//			while (i < str.size() && str[i] != ' ')
//			{
//				tmp += str[i];
//				i++;
//			}
//			vs.push_back(tmp);
//		}
//
//		int maxLen = 0; //有可能用不上
//
//
//		// 创建有向图
//		build(vs);
//
//		// 找拓扑结构
//		topology();
//
//		if (ans.size() == myset.size())
//		{
//			for (auto e : ans)
//			{
//				cout << e << " ";
//			}
//			cout << endl;
//		}
//		else
//		{
//			cout << "Invalid" << endl;
//		}
//		//mymap.clear();
//		mymap.swap(vector<vector<int>>(26, vector<int>(26)));
//		//indegree.clear();
//		indegree.swap(vector<int>(26));
//		//flag.clear();
//		flag.swap(vector<bool>(26));
//		//myset.clear();
//		myset.swap(set<char>());
//		//ans.clear();
//		ans.swap(vector<char>());
//	}
//}