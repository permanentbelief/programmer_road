#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

double d[10]; // 距离
double pi[10]; // 花费
int main()
{
	double d1, c, d2, p, pmin = 1000, l = 0, pz = 0; // l是指邮箱中的油量，pz是花钱总数，初始值为0
	int n;
	cin >> d1 >> c >> d2 >> p >> n;
	d[0] = 0;
	double d0 = 0;
	pi[0] = p;
	double x = c * d2; // 加满油能最多走到的距离
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i] >> pi[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] - d[i - 1] > x)
		{
			cout << "No Solution" << endl;
			return 0;
		}
	}

	int ii = 0; // 此处到达的地方 ---最优解 

	while (d1 - d0) //d1总的路程，d0 当前移动的距离（距离源点的距离）
	{

		// x加满油 能最多走的路程
		for (int i = ii + 1; d[i] - d0 <= x && i <= n; i++)
		{
			if (pi[i] < pmin) // 找到最低的费用
			{
				pmin = pi[i];
				ii = i;     //记录最优解的下标
			}
		}
		if (pmin <= p) // 范围内的加油站 ii点比自己便宜 
		{
			pz += ((d[ii] - d0) / d2 - l) * p;
			l = (d[ii] - d0) / d2; // 邮箱中的油量直接加满到ii点的
		}
		else if (d1 - d0 > x) // 直接加满， 此处最便宜而且没有办法直接一次叨叨终点
		{
			pz += (c - 1) * p;
			l = c;
		}
		else  // 此处最便宜，一次到达终点
		{
			pz += ((d1 - d0) / d2 - l)* p;
			break;
		}
		l = l - (d[ii] - d0) / d2; // 邮箱中剩余的油量
		d0 = d[ii]; // 更细移动距离(移动到更 正确的点上)
		p = pmin; // 更新p,方便下次进行比较
		pmin = 1000; // 下次搜索最小值
	}
	printf("%.2lf", pz);
	return 0;
}