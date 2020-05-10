#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <vector>
#include <string>
#include  <algorithm>

using namespace std;

int main()
{
	int n = 0;
	vector<int> v;
	while (cin >> n)
	{
		int temp = n;
		for (int i = 2; i <= n; i++)
		{
			while (i <= n && n % i == 0)
			{
				n = n / i;
				v.push_back(i);
			}
		}
		string str = to_string(temp) + " =";
		for (int i = 0; i < v.size(); i++)
		{
			if (i != v.size() - 1)


			{
				str += " ";
				str += v[i] + '0' ;
				str += " *";
			}
			else
			{
				str += " ";
				str += v[i] + '0';
			}

		}
		cout << str << endl;
	}

}