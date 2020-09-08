#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

using namespace std;


const int N = 15;
int a[N];
int main()
{

	vector<string>vs = { "6", "K", "Q" };

	vector<string> vvs;
	



	cout << '0' << endl;
	cout << 'K' - '0'<< endl;
	cout << '10' << endl; 



	for (int i = 0; i < vs.size(); i++)
	{
		// vs[i][0]  // K; K 13
		// cout << vs[i][0]  - '0' << endl;

		if (vs[i][0] - '0' >= '0' && vs[i][0] - '0'<= '10') 
		{
			a[vs[i][0] - '0']++;
		}

		else if (vs[i][0] == 'J')
		{
			a[11]++;
		}
		else if (vs[i][0] == 'Q')
		{
			a[12]++;
		}
		else
		{
			a[13]++;
		}

	}
	for (int i = 1; i <= 10; i++)
	{
		while (a[i])
		{
			vvs.push_back(to_string(i));
			a[i]--;
		}
	}
	// J Q K
	while (a[11])
	{
		vvs.push_back("J");
		a[11]--;
	}
	while (a[12])
	{
		vvs.push_back("Q");
		a[12]--;
	}
	while (a[13])
	{
		vvs.push_back("K");
		a[13]--;
	}
	
	for (auto e : vvs)
	{
		cout << e << endl;
	}
	
	system("pause");
}