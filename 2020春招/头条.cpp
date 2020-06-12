#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


//int main()
//{
//	int n = 0;
//	int m = 0;
//	cin >> n;
//	cin >> m;
//	long long count = 0;
//	vector<int> v(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	int left = 0;
//	int right = 0;
//	while (right < n)
//	{
//		while (right < n && v[right] - v[left] <= m)
//		{
//			right++;
//		}
//		int dif = right - left;
//		if ( dif >= 3)
//		{
//			count += (dif)*(dif - 1)*(dif - 2) / 6;
//			dif = 0;
//		}
//		if (right >= n)
//			break;
//		if (v[right] - v[left] > m)
//		{
//			left++;
//		}
//	}
//	cout << count << endl;
//	system("pause");
//}

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	virtual void func()
	{
		cout << "A::func()" << endl;
	}
};

class B
{
public:
	B()
	{
		cout << "B()" << endl;
	}
	void func()
	{
		cout << "B::func()" << endl;
	}

};

int c = []()
{
	cout << "a" << endl;
	return 0;
}();


#include <list>

#include <unordered_map>
//
//class Solution1{
//public:
//	vector<int> findSubstring(string s, vector<string>& words) {
//		vector<int> ret;
//		if (words.size() == 0)//判断words为空,因为下面用到了words[0]
//			return ret;
//
//		int word_size = words[0].size();
//		int word_num = words.size();
//
//		unordered_map<string, int> m1;//构造hashmap
//		for (int i = 0; i<word_num; i++)
//			m1[words[i]]++;
//
//		unordered_map<string, int> m2;
//		for (int i = 0; (i + word_size * word_num) <= s.size(); i++){//截取的s符合题意
//			int j = 0;
//			for (j = i; j < (i + word_size * word_num); j = j + word_size){//分段判断
//				string temp_str = s.substr(j, word_size);
//				if (m1[temp_str] == 0){//m1中没有截取的串，直接跳出
//					break;
//				}
//				else{
//					m2[temp_str]++;
//					if (m1[temp_str] < m2[temp_str])//重复次数过多，也跳出
//						break;
//				}
//			}
//
//			if (j == (i + word_size * word_num))//每一段都符合，则加入答案
//				ret.push_back(i);
//
//			m2.clear();//清空m2
//		}
//		return ret;
//	}
//};


int wiggleMaxLength(vector<int>& nums) {
	vector<int> dp(nums.size(), 1);
	int max_ = 1;

	if (nums.size() == 0)
		return 0;
	else if (nums.size() == 1)
		return 1;

	dp[1] = nums[0] == nums[1] ? 1 : 2;

	for (int i = 2; i < nums.size(); i++)
	{
		if ((nums[i] - nums[i - 1])*(nums[i - 1] - nums[i - 2])<0) dp[i] = dp[i - 1] + 1;
		else dp[i] = dp[i - 1];
	}

	return dp[dp.size() - 1];
}
int main()
{
	
	vector<int> A = { 3, 3, 3, 2, 5 };
	cout << wiggleMaxLength(A) << endl;
	system("pause");


	
}