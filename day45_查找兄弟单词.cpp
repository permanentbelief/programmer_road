#define _CRT_SECURE_NO_WARNINGS 1 


// 10%
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool isBrother(string str, string s)
{
	if (str.size() == s.size())
	{
		if (str == s)
		{
			return false;
		}
	
	sort(str.begin(), str.end());
	sort(s.begin(), s.end());
	if (str == s)
		return true;
	}
	return false;
}

int main(){
	int num;
	while (cin >> num){
		string str;
		string word, s;
		int index;
		vector<string> vs;
		for (int i = 0; i < num; ++i){
			cin >> str;
			vs.push_back(str);
		}
		sort(vs.begin(), vs.end());  // ��Ϊ���ֵ䣬һ��Ҫ���򣡣�
		cin >> word;
		cin >> index;
		int counts = 0;

		for (int i = 0; i < num; ++i){
			if (isBrother(word, vs[i])){
				counts++;
				if (counts == index)
					s = vs[i];
			}
		}
		if (!vs.empty())
			cout << counts << endl;
		if (counts >= index)
			cout << s << endl;
		 
	}
	return 0;
}