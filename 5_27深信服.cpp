#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//
//int get(char c1, char c2)
//{
//	int res = 0;
//	if (c1 >= '0' && c1 <= '9')
//		res = c1 - '0';
//	if (c1 >= 'a' && c1 <= 'f')
//		res = c1 - 'a' + 10;
//	if (c1 >= 'A' &&  c1 <= 'F')
//		res = c1 - 'A' + 10;
//
//	if (c2 >= '0' && c2 <= '9')
//		res = res * 16 + c2 - '0';
//	if (c2 >= 'a' && c2 <= 'f')
//		res = res * 16 + c2 - 'a' + 10;
//	if (c2 >= 'A' &&  c2 <= 'F')
//		res = res * 16 + c2 - 'A' + 10;
//
//	return res;
//}
//
//const int N = 100010;
//char s[N];
//char skt[N];
//
//
//bool isnum(char x) {
//	return (x >= '0' && x <= '9') || (x >= 'A' && x <= 'F') || (x >= 'a' && x <= 'f');
//}

//int main()
//{
//	
//	int T = 0;
//	cin >> T;
//	while (T--)
//	{
//		cin >> s;
//		int tt = 0;
//		int n = strlen(s);
//		for (int i = 0; i < n; i++)
//		{
//			skt[++tt] = s[i];
//			//满足解压的条件
//			while (tt - 2 && isnum(skt[tt]) && isnum(skt[tt - 1]) && skt[tt - 2] == '%')
//			{
//				int num = get(skt[tt - 1], skt[tt]);
//				char x = num;
//				tt -= 3;
//				skt[++tt] = x;
//			}
//			
//		}
//		for (int i = 1; i <= tt; i++)
//			printf("%c", skt[i]);
//	}
//	system("pause");
//}


//#include <unordered_set>
//#include <unordered_map>
//
//using namespace std;
//const int N = 100010;
//unordered_map<int, int> mp;
//unordered_set<int> s;
//unordered_map<int, int> window;
//int a[N], n, m, tot;
//
//int main() {
//	int T;
//	scanf("%d", &T);
//	while (T--)
//	{
//		cin >> n;
//		vector<int> v(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v[i];
//			if (mp.count(v[i]))
//			{
//				mp[v[i]]++;
//			}
//		}
//		cin >> m;
//		bool flag = true;
//		for (int i = 0; i  < m; i++)
//		{
//			int x = 0;
//			cin >> x;
//			s.insert(x);
//		}
//		int min_len = n;
//		int left = 0;
//		int right = 0;
//		int valid = 0;
//		while (right < n)
//		{
//			int x = v[right++];
//			if (s.find(x) != s.end())
//			{
//				if (!window.count(x))
//				{
//					valid++;
//				}
//				window[x]++;
//			}
//			while (s.size() == valid)
//			{
//				min_len = min(min_len, right - left);
//				int x = v[left++];
//				if (s.find(x) != s.end())
//				{
//					window[x]--;
//					if (window[x] <= 0)
//						valid--;
//				}
//
//			}
//		}
//		printf("%d\n", min_len);
//	}
//	system("pause");
//	return 0;
//}


using namespace std;
const int N = 1e4 + 5;
char s[N];

int main()
{
	string s;
	cin >> s;
	int len = s.size();
	int ans = 0;
	for (int i = 1; i <= len / 2; i++){
		int tmp = 0;
		for (int j = 0; j < len - i; j++){
			if (s[j] == s[j + i]){
				tmp++;
			}
			else{
				tmp = 0;
			}
			if (tmp == i){
				ans = max(ans, 2 * i);
				break;
			}
		}
	}
	
	printf("%d\n", ans);
	system("pause");
	return 0;
}