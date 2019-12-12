#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main(int argc, char** argv){
	string str;
	while (cin >> str){
		int len = str.size();
		vector<int> temp(26, 0);    //表示小写字母个数，-1表示已经使用过
		for (int i = 0; i < len; i++){
			temp[str[i] - 'a']++;
		}
		string ans = "";
		int cur = 0;        //表示当前第一个要选择字母
		while (cur < 26 && temp[cur] == 0) cur++;
		for (int i = 0; i < len; i++){
			if (str[i] - 'a' == cur){
				temp[str[i] - 'a'] = -1;
				ans += str[i];
				while (cur < 26 && temp[cur] == -1){
					cur++;
				}
				if (cur == 27)
					break;

			}
			else{
				if (temp[str[i] - 'a'] == 1){
					ans += str[i];
					temp[str[i] - 'a'] = -1;
				}
				else
					temp[str[i] - 'a']--;
			}
		}
		cout << ans << endl;
	}
	system("pause");
	return 0;
}