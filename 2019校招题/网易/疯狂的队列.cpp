#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;


int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int max_ = v[n - 1];
		int min_ = v[0];
		int diff = max_ - min_;
		int minIndex = 1;
		int maxIndex = n - 2;
		while (minIndex < maxIndex)
		{
			diff += max_ - v[minIndex];
			diff += v[maxIndex] - min_;
			min_ = v[minIndex++];
			max_ = v[maxIndex--];
		}
		diff += max(v[maxIndex] - min_, max_ - v[minIndex]); //如果这里有四个的话， 1        2        6         9
																//                 min_                        max_          
		cout << diff << endl;                                   //                        minIndex   maxIndex
	}														    //                   (min_)maxIndex (max_)minIndex

	system("pause");
}