#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


#include <iostream>
#include <vector>
using namespace std;


int main()
{

	vector<long long> v(100001, 0);
	v[0] = 1;
	v[1] = 1;
	int i = 2;
	for (; i < 100001; i++)
	{
		v[i] = v[i - 1] % 1000000 + v[i - 2] % 1000000;
		v[i] = v[i] % 1000000;
	}
	
	int n = 0;
	while (cin >> n)
	{
		if (n >= 25)
			printf("%06d\n", v[n]);
		else
			printf("%d\n", v[n]);
	}
}
