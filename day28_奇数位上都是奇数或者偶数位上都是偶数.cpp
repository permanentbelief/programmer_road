//#define _CRT_SECURE_NO_WARNINGS 1 
//
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//void oddInOddEvenInEven(vector<int> arr) {
//
//	/* //与题中答案的顺序不服
//	int begin = 0;
//	int end = 1;
//	while (begin < arr.size() && end < arr.size())
//	{
//	while(begin < arr.size() && arr[begin] % 2 == 0)
//	begin += 2;
//	while (end < arr.size() && arr[end] % 2 != 0)
//	end += 2;
//	if (begin < arr.size() && end < arr.size())
//	swap(arr[begin], arr[end]);
//
//	}
//	*/
//	int i = 0, j = 1;
//	while (i< arr.size() && j< arr.size()){
//		if (arr[i] % 2 != 0 && arr[j] % 2 == 0){
//			swap(arr[i], arr[j]);
//		}
//		if (arr[i] % 2 == 0)
//			i += 2;
//		if (arr[j] % 2 != 0)
//			j += 2;
//	}
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	oddInOddEvenInEven({ 7, 7, 9, 5, 1, 6, 7, 9, 3, 2, 6 });
//
//
//	/*vector<vector<int>> ret = getFirstUnFormedNum({ 1, 2, 3 });
//	for (auto e : ret)
//	{
//	for (auto i : e)
//	{
//	cout << i << " ";
//	}
//	cout << endl;
//	}*/
//	system("pause");
//}
//
