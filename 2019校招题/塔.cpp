#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

	bool  ComByValue(pair<int, int>&l, pair<int, int>& r)
	{
	
		return l.second > r.second;            //大于 是降序 小于是升序
	}

int main()
{
	int count = 0;
	int k = 0;
	while (cin >> count >> k)
	{
		vector<pair<int, int>> m;
		for (int i = 1; i <= count; i++)
		{
			int temp;
			cin >> temp;
			m.push_back(make_pair(i,temp));
		}
		sort(m.begin(), m.end(),ComByValue);// 降序 按照
	   vector<pair<int, int>> vp;
		int Count = 0;
		while (k--)
		{
			if (m[0].second > m[count - 1].second)
			{
				Count++;
				m[0].second--;
				m[count - 1].second++;
				vp.push_back(make_pair(m[0].first,m[count-1].first));
				sort(m.begin(), m.end(), ComByValue);
			}
			else
			{
				break;
			}
		}
		/*while (left <= right)
		{
			if (Count < k && m[left].second > m[right].second)
			{
				m[left].second--;
				m[right].second++;
				Count++;
				vp.push_back(make_pair(m[left].first, m[right].first));
				sort(m.begin(), m.end(), ComByValue());
				left = 0;
				right = m.size() - 1;
			}
			if (Count == k)
				break;
		}*/
		int height = m[0].second - m[count - 1].second;
		cout << height << " " << Count << endl;

		for (int i = 0; i < m; i++)
		{
			cout << vp[i].first << " " << vp[i].second << endl;
		}
	}
}