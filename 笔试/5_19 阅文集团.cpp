#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
//using namespace std;
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		vector<int> v;
//		map<int, int> mymap;
//		for (int i = 0; i < str.size(); i++)
//		{
//			int count = 0;
//			while (i < str.size() && str[i] != ' ')
//			{
//				count = count * 10 + (str[i] - '0');
//				i++;
//			}
//			if (mymap.find(count) != mymap.end())
//				v.push_back(count);
//			mymap[count] = 1;
//
//		}
//		for (auto e : v)
//		{
//			cout << e << " ";
//		}
//	}
//}

//#include <iostream>
//
//#include <vector>
//
//
////using namespace std;
//void remove_element(std::vector<int>& vec)
//{
//	int count = 0;
//	for (int i = 0; i < vec.size(); i++)
//	{
//		bool flag = false;
//		if (vec[i] == 10)
//		{
//			for (int j = i + 1; j < vec.size(); j++)
//			{
//				vec[j - 1] = vec[j];
//			}
//			vec.erase(--vec.end());
//			i--;
//		}
//		
//
//	}
//
//}
//int main()
//{
//	std::vector<int> vec = { 3 ,10 ,10, 4, 1 ,10 ,6 };
//	int n = 0;
//
//	remove_element(vec);
//
//	for (auto idx = 0; idx != vec.size(); ++idx)
//	{
//		if (idx > 0)
//			std::cout << " ";
//		std::cout << vec[idx];
//	}
//	std::cout << std::endl;
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<string, string> mymap;
void set(const std::string& key, const std::string& value)
{
	mymap[key] = value;
}
std::string get(const std::string& key)
{
	if (mymap.find(key) == mymap.end())
	{
		return "none";
	}
	else
	{
		return mymap[key];
	}
}

int main()
{
	string str;
	int n = 0;
	cin >> n;
	getchar();
	while (getline(cin, str))
	{
		vector<string> vs;
		for (int i = 0; i < str.size(); i++)
		{
			string cur;
			while (i < str.size() && str[i] != ' ')
			{
				cur += str[i];
				i++;
			}
			vs.push_back(cur);
		}
		if (vs[0] == "set")
		{
			set(vs[1], vs[2]);
		}
		else
		{
			cout << get(vs[1]) <<endl;
		}
	}
}