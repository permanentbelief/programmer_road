#define _CRT_SECURE_NO_WARNINGS 1 



#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


/*
3,6,5,1,8
*/

int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<int> v;
		for (int i = 0; i < str.size(); i++)
		{
			int sum = 0;
			while (i < str.size()&& str[i] >= '0' && str[i] <= '9')
			{
				sum = sum * 10 + (str[i] - '0');
				i++;
			}
			v.push_back(sum);
		}

		int Sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			Sum += v[i];
		}
		if (Sum % 3 == 0)
		{
			Sum = Sum / 3;
			cout << Sum << endl;
		}
		else
		{
			int max_outcome = 0;
			for (int i = 0; i < v.size(); i++)
			{
				int sum = v[i];
				if (sum % 3 == 0)
				{
					max_outcome = max(max_outcome, sum / 3);
				}
				for (int j = i + 1; j < v.size(); j++)
				{
					sum += v[j];
					if (sum % 3 == 0)
					{
						max_outcome = max(max_outcome, sum / 3);
					}
				}
			}
			sort(v.begin(), v.end());
			int _max = 0;

			for (int i = 0; i < v.size(); i++)
			{
				int k = Sum - v[i];
				if (k % 3 == 0)
				{
					_max = max(k / 3, _max);
				}
			}
			// max_outcome = max(Sum / 3, max_outcome);
			cout << max(max_outcome , _max) << endl;
		}


	}
}
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		vector<int> v(n);
//		int Sum = 0;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v[i];
//			Sum += v[i];
//		}
//		if (Sum % 3 == 0)
//		{
//			Sum = Sum / 3;
//			cout << Sum << endl;
//		}
//		else
//		{
//			int max_outcome = 0;
//			for (int i = 0; i < v.size(); i++)
//			{
//				int sum = v[i];
//				if (sum % 3 == 0)
//				{
//					max_outcome = max(max_outcome, sum / 3);
//				}
//				for (int j = i + 1; j < v.size(); j++)
//				{
//					sum += v[j];
//					if (sum % 3 == 0)
//					{
//						max_outcome = max(max_outcome, sum / 3);
//					}
//				}
//			}
//			sort(v.begin(), v.end());
//			int _max = 0;
//			
//			for (int i = 0; i < v.size(); i++)
//			{
//				int k = Sum - v[i];
//				if (k % 3 == 0)
//				{
//					_max = max(k / 3, _max);
//				}
//			}
//			cout << max(max_outcome, _max) << endl;
//		}
//		
//	}
//}


// 75
//#include <map>
//#include <string>
//
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		vector<pair<int, int>> vv;
//		map<int, int> mymap;
//		int k = 0;
//		int k_nums = 0;
//		int outcome = 0;
//		int a = 0;
//		int b = 0;
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (str[i] <= '0' || str[i] >= '9')
//				continue;
//			int sum = 0;
//			while (i < str.size() && str[i] >= '0' && str[i] <= '9')
//			{
//				sum = sum * 10 + (str[i] - '0');
//				i++;
//			}
//			a = sum;
//			sum = 0;
//			i += 1;
//			while (i < str.size() && str[i] >= '0' && str[i] <= '9')
//			{
//				sum = sum * 10 + (str[i] - '0');
//				i++;
//			}
//			b = sum;
//			vv.push_back(make_pair(a, b));
//		}
//		for (int i = 0; i < vv.size(); i++)
//		{
//			if (!mymap.empty())
//			{
//				if (mymap.find(vv[i].second) != mymap.end())
//				{
//					k_nums = vv[i].second;
//					k = i;
//					break;
//				}
//
//			}
//			mymap[vv[i].first] = vv[i].second;
//		}
//		for (int i = 0; i < vv.size(); i++)
//		{
//			if (vv[i].first == k_nums)
//			{
//				outcome = k - i + 1;
//				break;
//			}
//		}
//		cout << outcome << endl;
//	}
//}



//#include  <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//int main()
//{
//
//	int a = 0;
//	int b = 0;
//	vector<pair<int, int>> vv;
//	map<int, int> mymap;
//	int k = 0;
//	int k_nums = 0;
//	int outcome = 0;
//	while (cin >> a >> b)
//	{
//		vv.push_back(make_pair(a, b));
//	}
//	for (int i = 0; i < vv.size(); i++)
//	{
//		if (!mymap.empty())
//		{
//			if (mymap.find(vv[i].second) != mymap.end())
//			{
//				k_nums = vv[i].second;
//				k = i;
//				break;
//			}
//
//		}
//		mymap[vv[i].first] = vv[i].second;
//	}
//	for (int i = 0; i < vv.size(); i++)
//	{
//		if (vv[i].first == k_nums)
//		{
//			outcome = k - i + 1;
//			break;
//		}
//	}
//	mymap.clear();
//	vv.clear();
//	cout << outcome << endl;
//}














//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string str;
//
//	while (getline(cin,str))
//	{
//		vector<int> v;
//		for (int i = 0; i < str.size(); i++)
//		{
//			int sum = 0;
//			while (i < str.size() && str[i] != ',')
//			{
//				sum = sum * 10 + (str[i] - '0');
//				i++;
//			}
//			v.push_back(sum);
//		}
//		vector<int> v1;
//		vector<int> v2;
//		for (int i = 0; i < v.size(); i++)
//		{
//			if (i % 2 == 0)
//			{
//				v1.push_back(v[i]);
//			}
//			else
//			{
//				v2.push_back(v[i]);
//			}
//		}
//		int k = 0;
//		int i = 0;
//		vector<int> v3(v.size());
//		v3[k++] = v1[0] - 30;
//		bool flag = true;
//		while (i < v.size() / 2)
//		{
//			if (i + 1 < v.size() / 2 && v1[i + 1] - v2[i] > 60)
//			{
//				v3[k++] = v2[i] + 30;
//				flag = true;
//			}
//			else
//			{
//				flag = false;
//				i += 1;
//				continue;
//			}
//			if (flag == true)
//			{
//				v3[k++] = v1[i + 1] - 30;
//
//			}
//			i++;
//		}
//		v3[k++] = v2[v2.size() - 1] + 30;
//		for (int i = 0; i < k; i++)
//		{
//			if (i != k - 1)
//				cout << v3[i] << ",";
//			else
//				cout << v3[i] << endl;
//
//		}
//	}
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		vector<int> v1;
//		vector<int> v2;
//		for (int i = 0; i < n; i++)
//		{
//			int a = 0;
//			cin >> a;
//			if (i % 2 == 0)
//			{
//				v1.push_back(a);
//			}
//			else
//			{
//				v2.push_back(a);
//			}
//		}
//		int k = 0;
//		int i = 0;
//		vector<int> v3(n);
//		v3[k++] = v1[0] - 30;
//		bool flag = true;
//		while (i < n/2)
//		{
//			if (i + 1 < n / 2 && v1[i + 1] - v2[i] > 60)
//			{
//				v3[k++] = v2[i] + 30;
//				flag = true;
//			}
//			else
//			{
//				flag = false;
//				i += 1;
//				continue;
//			}
//			if (flag == true)
//			{
//				v3[k++] = v1[i+1] - 30;
//			
//			}
//			i++;
//		}
//		v3[k++] = v2[v2.size() - 1] + 30;
//		for (int i = 0; i < k; i++)
//		{
//			if (i != k - 1)
//				cout << v3[i] << ",";
//			else
//				cout << v3[i] << endl;
//
//		}
//	}
//}