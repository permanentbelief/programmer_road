#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// ʳ����  ���鼯 3�� ����� ���鼯


using namespace std;

const int N = 1e6;
int n, m, x, y, op;

int f[N];

int find(int x)
{
	if (x == f[x])
		return x;
	return f[x] = find(f[x]);
}
void merge(int a, int b)
{
	int aa = find(a);
	int bb = find(b);
	f[aa] = bb;
}
bool check(int a, int b)
{
	return find(a) == find(b);
}

int main()
{
	cin >> n >> m;

	int cnt = 0;
	for (int i = 1; i <= 3 * n; i++)
	{
		f[i] = i;
	}
	while (m--)
	{
		cin >> op >> x >> y;
		if (x > n || y > n)
		{
			cnt++;
			continue;
		}

		if (op == 1) // ���
		{
			if (find(x) == find(y + n) || find(y) == find(x + n))
			{
				cnt++;
			}
			else
			{
				f[find(x)] = find(y);
				f[find(x + n)] = find(y + n);
				f[find(x + 2 * n)] = find(y + 2 * n);
			}
		}
		else if (op == 2)
		{                           //A��2  ����� B�� 4��ͬ��
			if (find(x) == find(y) || find(x) == find(y + n))
				//B��2    ��A��4 ͬ��
				cnt++;
			else
			{
				//B��2 �� A�� 4
				f[find(x + n)] = find(y);
				//C��2 �� A�� 4
				f[find(x + n + n)] = find(y + n);
				//A��2 �� B��4
				f[find(x)] = find(y + n + n);
			}
		}

	}
	cout << cnt << endl;
}