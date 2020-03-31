#define _CRT_SECURE_NO_WARNINGS 1 
链接：https://www.nowcoder.com/questionTerminal/ac61207721a34b74b06597fe6eb67c52
来源：牛客网

#include <iostream>
using namespace std;
int main(){
	string s = "", table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	while (m){
		if (m<0){
			m = -m;
			cout << "-";
		}
		s = table[m%n] + s;
		m /= n;
	}
	cout << s << endl;
	system("pause");
	return 0;
}