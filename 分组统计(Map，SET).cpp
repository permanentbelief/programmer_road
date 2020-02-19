#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int num = 0;
	
	//vector<int> v1;
	//vector<int> v2;
	set<int> s1;
	set<int> s2;
	

	cin >> num;
	while (num--)
	{
		int n = 0;
		cin >> n;
		vector<int> v1(n, 0);
		for (int i = 0; i < n; i++)
		{
			/*int temp = 0;
			cin >> temp;
			v1.push_back(temp);*/
			//s1.insert(temp);
			cin >> v1[i];
		}
		set<int> s1(v1.begin(), v1.end());
		vector<int> v2(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> v2[i];
			/*int temp = 0;
			cin >> temp;
			v2.push_back(temp)*/;
			//s2.insert(temp);
		}
		set<int> s2(v2.begin(), v2.end());
		map<int, int> mp[10000];
		for (set<int>::iterator it2 = s2.begin(); it2 != s2.end(); it2++)
		{
			for (set<int>::iterator it1 = s1.begin(); it1 != s1.end(); it1++)
			{
				mp[*it2][*it1] = 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			mp[v2[i]][v1[i]]++;
		}
		int count = 0;
		for (set<int>::iterator it2 = s2.begin(); it2 != s2.end(); it2++)
		{
			cout << *it2 << "={";
			count = 0;
			for (map<int, int>::iterator it = mp[*it2].begin(); it != mp[*it2].end(); it++)
			{
				count++;
				cout << it->first << "=" << it->second;
				if (count != s1.size())
					printf(",");
			}
			cout << "}" << endl;
			mp[*it2].clear();
		}

		/*int count = 0;
		for (auto it = s2.begin; it != s2.end(); it++)
		{
			count++;
			cout << *it << "=" << "";
			cout << m[*it].first << "=" << m[*it].second;
			if (count < s1.size())
				cout << "*"
			if (count == s1.size())
				cout << '}' << endl;
		}*/
	}
}

//#include<map>
//#include<vector>
//#include<iostream>
//#include<set>
//using namespace std;
//int main(int argc, char const *argv[])
//{
//	int num, n;
//	std::vector<int> v1;
//	std::vector<int> v2;
//	set<int> s1;
//	set<int> s2;
//	map<int, int> mp[10000];
//	while (scanf("%d", &num) != EOF)
//	{
//		while (num--)
//		{
//			scanf("%d", &n);
//			int temp, count;
//			for (int i = 0; i < n; ++i)
//			{
//				scanf("%d", &temp);
//				v1.push_back(temp);//将第一组数存入vector
//				s1.insert(temp);//将第一组数存入set
//			}
//			for (int i = 0; i < n; ++i)
//			{
//				scanf("%d", &temp);
//				v2.push_back(temp);//将第二组数存入vector
//				s2.insert(temp);//将第二组数存入set
//			}
//			for (set<int>::iterator it2 = s2.begin(); it2 != s2.end(); it2++)//初始化
//			{
//				for (set<int>::iterator it1 = s1.begin(); it1 != s1.end(); it1++)
//				{
//					mp[*it2][*it1] = 0;//初始化map
//				}
//			}
//			for (int i = 0; i < n; ++i)//计算个数
//			{
//				mp[v2[i]][v1[i]]++;
//			}
//			for (set<int>::iterator it2 = s2.begin(); it2 != s2.end(); it2++)
//			{
//				cout << *it2 << "={";
//				count = 0;
//				for (map<int, int>::iterator it = mp[*it2].begin(); it != mp[*it2].end(); it++)
//				{
//					count++;
//					cout << it->first << "=" << it->second;
//					if (count != s1.size())
//						printf(",");
//				}
//				cout << "}" << endl;
//				mp[*it2].clear();
//			}
//			v1.clear();
//			v2.clear();
//			s1.clear();
//			s2.clear();
//		}
//	}
//	return 0;
//}