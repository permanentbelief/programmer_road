#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#include <map>
class Solution {
public:
	int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
		map<int, int> mymap;
		for (int i = 0; i < arr.size(); i++)
		{
			mymap[arr[i]]++;
		}
		if (k == 0)
			return mymap.size();
		vector<int> v;
		for (auto e : mymap)
		{
			v.push_back(e.second);
		}
		sort(v.begin(), v.end());

		int i = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (k - v[i] >= 0)
				k -= v[i];
			else
			{
				break;
			}
		}

		return v.size() - i;
	}
};
int main()
{
	vector<int> v = { 4, 3, 1, 1, 3, 3, 2 };
	Solution s;
	cout << s.findLeastNumOfUniqueInts(v, 3) <<endl;
	system("pause");
}