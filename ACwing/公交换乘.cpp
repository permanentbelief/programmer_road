#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;



const int N = 100010;
#include <cstdio>

struct Ticket
{
	int time, price;
	bool used;
}tk[N];
int main()
{
	int n = 0;
	scanf("%d", &n);
	int res = 0;
	for (int i = 0, l = 0, r = 0; i < n; i++)
	{
		int type, price, time;
		scanf("%d %d %d", &type, &price, &time);
		if (type == 0) // 地铁
		{
			res += price;
			tk[r++] = { time, price };
		}
		else // type = 1 公交车
		{
			while (l < r && time - tk[l].time > 45)
				l++;
			bool success = false;
			for (int i = l; i <= r; i++)
			{
				if (tk[i].used == false && tk[i].price >= price)
				{
					tk[i].used = true;
					success = true;
					break;
				}
			}

			if (!success)
				res += price;
		}

		cout << res << endl;
	}
	system("pause");
}