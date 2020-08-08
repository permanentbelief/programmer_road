#define _CRT_SECURE_NO_WARNINGS 1 


using namespace std;
#include <queue>
#include "Hash.h"
#include <string>
#include <vector>



using namespace std;

const int M = 1e4 + 10, N = 1e5 + 10;

int m, n;
char p[M], s[N];
int ne[M];
//

int main() {
	cin >> m >> p + 1 >> n >> s + 1;

	//求ne数组
	for (int i = 2, j = 0; i <= m; i++) {
		while (j && p[i] != p[j + 1]) j = ne[j];
		if (p[i] == p[j + 1]) j++;
		ne[i] = j;
	}

	//kmp匹配
	for (int i = 1, j = 0; i <= n; i++) {
		while (j && s[i] != p[j + 1]) j = ne[j];
		if (s[i] == p[j + 1]) j++;
		if (j == m) {
			j = ne[j]; //当匹配成功时继续往下匹配
			printf("%d ", i - m);
		}
	}

	return 0;
}
int main()
{

	cout << endl;
	system("pause");
}