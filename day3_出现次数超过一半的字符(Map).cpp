#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>

#include <map>
#include <vector>
using namespace std;


int MoreThanHalfNum_Solution(vector<int> numbers) {
		map<int, int> map_;
		for(int i = 0; i <numbers.size(); i++)
		{
			++map_[numbers[i]];
		}
		for(auto e : map_)
		{
			if (e.second >= numbers.size() / 2)
			{
				return e.first;
			}
		}
		return 0;
	}

int main()
{

	vector<int> v = { 1, 1, 1, 2, 2 };
	cout << MoreThanHalfNum_Solution(v) << endl;
	system("pause");
}