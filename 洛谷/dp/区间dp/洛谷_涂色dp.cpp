#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;



using namespace std;



//Ϳɫ
char s[52];
int f[52][52];



int main()
{
	int n = 0;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	memset(f, 0x7f, sizeof(f));
	for (int i = 1; i <= n; i++)
	{
		f[i][i] = 1;
	}
	for (int l = 2; l <= n; l++)
	{
		for (int i = 1; i + l - 1 <= n; i++)
		{
			int j = i + l - 1;
			if (s[i] == s[j])
				f[i][j] = min(f[i + 1][j], f[i][j - 1]);
			else
			for (int k = i; k < j; k++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
			}
		}
	}
	printf("%d\n", f[1][n]);
	return 0;
}