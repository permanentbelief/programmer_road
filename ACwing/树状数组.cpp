#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int lowbit(int x)
{
	return x&-x;
}
//�����ѯ

void add(int x, int k)
{
	for (; x <= n; x += x&-x)
	{
		t[x] += k;
	}
}

void ask(int x)
{
	int ans = 0;
	for (; x; x -= x&-x)
	{
		ans += t[x];
	}
	return ans;
}
void ask(int x)
{

}

int main()
{
	
	system("pause");
}