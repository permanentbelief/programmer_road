#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n = 0;
	string str;
	while (cin >> n >> str)
	{
		int num = 1; 
		int first = 1;
		if (n <= 4)
		{
			for (int i = 0; i < str.size(); i++)
			{
				if (num == 1 && str[i] == 'U') num = n;
				else if (num == n && str[i] == 'D') num = 1;
				else if (str[i] == 'U') num--;
				else num++;
			}
			for (int i = 1; i <= n - 1; i++)
			{
				cout << i << ' ';
			}
			cout << n << endl;
			cout << num << endl;
		}
		else
		{
			for (int i = 0; i < str.size(); i++)
			{
				if (first == 1 && num == 1 && str[i] == 'U')// �������
				{
					num = n;
					first = n - 3;
				}
				else if (first == n - 3 && num == n && str[i] == 'D') //�������
				{
					first = 1;
					num = 1;
				}
				else if (first != 1 && first == num &&str[i] == 'U')
				{
					num--;
					first--;
				}
				else if ( first != n - 3 && num == first + 3 && str[i] == 'D')
				{
					first++;
					num++;
				}
				else if (str[i] == 'U')
				{
					num--;
				}
				else
				{
					num++;
				}
				
					
					
			}
			for (int i = first; i < first + 3; i++)
			{
				cout << i << ' ';
			}
			cout << first + 3 << endl;
			cout << num << endl;
		}
		
	}
		system("pause");
}
