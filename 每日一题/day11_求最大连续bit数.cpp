#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	vector<int> v(32, 0);
	int k = 31;
	for (int i = 0; i < 32; i++)
	{
		if (n % 2 == 1)
		{
			v[k] = 1;
			k--;
		}
		else
		{
			k--;
		}
		n /= 2;
	}
	int max = 0;
	for (int i = 0; i < 32; i++)
	{
		int count = 0;
		while (i<32 &&v[i] == 1)
		{
			i++;
			count++;
		}
		if (count > max)
			max = count;
	}
	cout << max << endl;
	system("pause");
}