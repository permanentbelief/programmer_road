#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;




string minWindow(string s, string t) {
	// ��¼����Ӵ��Ŀ�ʼλ�úͳ���
	int start = 0, minLen = INT_MAX;
	int left = 0, right = 0;
	unordered_map<char, int> window;
	unordered_map<char, int> needs;
	for (char c : t) needs[c]++;
	int match = 0;
	while (right < s.size()) {
		char c1 = s[right];
		if (needs.count(c1)) {
			window[c1]++;
			if (window[c1] == needs[c1])
				match++;
		}
		right++;
		while (match == needs.size()) {
			if (right - left < minLen) {
				// ������С�Ӵ���λ�úͳ���
				start = left;
				minLen = right - left;
			}
			char c2 = s[left];
			if (needs.count(c2)) {
				window[c2]--;
				if (window[c2] < needs[c2])
					match--;
			}
			left++;
		}
	}
	return minLen == INT_MAX ?
		"" : s.substr(start, minLen);
}


vector<int> findAnagrams(string s, string t)
{
	vector<int> res;
	int left = 0;
	int right = 0;
	unordered_map<char, int> sm;
	unordered_map<char, int> tm;
	int match = 0;

	for (auto e : t)
	{
		tm[e]++;
	}
	while (right < s.size())
	{
		if (tm.count(s[right]))
		{
			sm[s[right]]++;
			if (sm[s[right]] == tm[s[right]])
			{
				match++;
			}
		}
		right++;
		while (match == tm.size())
		{
			if (right - left == t.size())
				res.push_back(left);

			if (tm.count(s[left]))
			{
				sm[s[left]]--;
				if (sm[s[left]] < tm[s[left]])
				{
					match--;
				}
			}
			
			left++;
		}
	}
	return res;
}

int LengthOfLongestSubstring(string s)
{
	int left = 0;
	int right = 0;
	unordered_map<char, int> window;
	int res = 0; //��¼����

	while (right < s.size())
	{
		char c1 = s[right];
		window[c1]++;
		right++;
		//���window�г����ظ��ַ�
		//��ʼ�ƶ�left��С����
		while (window[c1] > 1)
		{
			char c2 = s[left];
			window[c2]--;
			left++;
		}
		res = max(res, right - left);
	}
	return res;
}
//int main()
//{
//	//cout << minWindow("EBBANCF", "ABC");
//	vector<int> res = findAnagrams("cbaebabacd", "abc");
//	for (auto e : res)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	system("pause");
//}
