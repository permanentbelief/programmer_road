//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//#include <map>
//
//using namespace std;
//
////class Solution {
////public:
////	struct CompareBV
////	{
////		bool operator()(const pair<string, int>& l, const pair<string, int>& r)
////		{
////			return l.second > r.second;
////		}
////	};
////	vector<string> topKFrequent(vector<string>& words, int k) {
////		vector<string> vs;
////		if (words.empty())
////			return vs;
////		map<string, int> m;
////		for (int i = 0; i < words.size(); i++)
////		{
////			m[words[i]]++;
////		}
////		sort(m.begin(), m.end(), CompareBV());
////		for (int i = 0; i < k; i++)
////		{
////			vs.push_back();
////		}
////		return vs;
////	}
////};
//
//
//struct CmpByValue
//{
//	bool operator() (const pair<string, int>&l, const pair<string, int>& r)
//	{ 
//		if (l.second == r.second)
//			return l.first < r.first;
//		else
//			return l.second > r.second;
//	}
//};
//class Solution {
//public:
//	//��⣺��map����ǰ׺��
//	vector<string> topKFrequent_1(vector<string>& words, int k) {
//		if (words.empty() || k == 0)return{};
//		map<string, int> record_1;//����->�õ��ʳ��ֵĸ���
//		vector<string> result;
//		for (const auto& word : words){
//			record_1[word]++;
//		}
//		//����map��֧��value��sort�������Ա��뽫mapת��Ϊvector���ܽ���sort�Զ�������
//		vector<pair<string, int>> record_2(record_1.begin(), record_1.end());
//		//sort�ĵ�����������lambda���ʽ����ʵ�ʹ���ͨ����һ����sort�ĵ�����������֧�ֶ�Ԫν�ʵ�
//		/*sort(record_2.begin(), record_2.end(),
//			[](const pair<string, int>& a, const pair<string, int>& b)
//			{
//			if (a.second == b.second)return a.first < b.first;
//			else return a.second > b.second;
//		}
//		);*/
//		sort(record_2.begin(), record_2.end(), CmpByValue());
//		
//		//��vector��ǰk��Ԫ����ӵ�result��
//		for (const auto& r : record_2)
//		{
//			if (k-- == 0 ) break;
//			result.push_back(r.first);
//		}
//		return result;
//	}
//};
//
////���ȼ�����
//int main()
//{
//	vector<string> vvvs = { "i", "love", "leetcode", "i", "love", "coding" };
//	int k = 2;
//	vector<string> vs;
//	Solution s;
//	vs = s.topKFrequent_1(vvvs, k);
//	system("pause");
//}