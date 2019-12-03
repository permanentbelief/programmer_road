#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int minCut(string s) {
		if (s.empty()) return 0;
		int len = s.size();
		vector<int> cut;
		// F(i)��ʼ��
		// F(0��= -1����Ҫ����û����һ������ص��ַ�����aaaaa�����������Ľ��
		for (int i = 0; i < 1 + len; ++i) {
			cut.push_back(i - 1);
		}
		for (int i = 1; i < 1 + len; ++i) {
			for (int j = 0; j < i; ++j) {
				// F(i) = min{F(i), 1 + F(j)}, where j<i && j+1��i�ǻ��Ĵ�
				// ������жϣ�����ӵ�j+1��iΪ�����ַ���
				// ���ټ�һ�ηָ��1��j��j+1��i���ַ���ȫ���ֳ��˻����ַ���
				if (isPalindrome(s, j, i - 1)) {
					cut[i] = min(cut[i], 1 + cut[j]);
				}
			}
		}
		return cut[len];
	}
	//�ж��Ƿ���Ĵ�
	bool isPalindrome(string s, int i, int j){
		while (i<j) {
			if (s[i] != s[j]){
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
};