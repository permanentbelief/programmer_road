#define _CRT_SECURE_NO_WARNINGS 1 

#include <string>
#include <iostream>
#include <vector>
using namespace std;

using namespace std;

string s;
vector<string> v;
int l;

void DFS(string t, int p){
	if (p == l){
		v.push_back(t);
		return;
	}
	char c = 'a' + s[p] - '1';
	if (!(p + 1<l && s[p + 1] == '0'))      //第二位0的情况
		DFS(t + c, p + 1);
	if (p + 1<l && (s[p] == '1' || (s[p] == '2' && s[p + 1] <= '6'))){ //当前位p和 p+1 有效 且
		if (!(p + 2<l && s[p + 2] == '0')){  // p+2 不等于0  
			c = 'a' + 10 * (s[p] - '0') + (s[p + 1] - '1');
			DFS(t + c, p + 2);
		}
	}
}

int main(){
	while (cin >> s){
		l = s.length();
		v.clear();
		string t = "";
		DFS(t, 0);
		for (int i = 0; i<v.size(); i++){
			if (i == v.size() - 1)
				cout << v[i] << endl;
			else
				cout << v[i] << " ";
		}
	}
	return 0;
}