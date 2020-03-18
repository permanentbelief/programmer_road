//#define _CRT_SECURE_NO_WARNINGS 1 
//
//
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//
////bool isSum(vector<int>&arr, int i, int sum, int aim)
////{
////	if (i == arr.size())
////	{
////		return sum == aim;
////	}
////	return isSum(arr, i + 1, sum, aim) || isSum(arr, i + 1, sum + arr[i], aim);
////
////}
//
//
////bool isSum(vector<int>& arr, int row, int col, int aim)
////{
////	vector<vector<bool>> vv(row + 1, vector<bool>(col + 1, false));
////	if (aim <= col)
////	{
////		vv[row][aim] = true;
////	}
////	for (int i = row - 1; i >= 0; i--)
////	{
////		for (int j = 0; j  <= col - arr[i]; j++)
////		{
////			if (vv[i + 1][j] || vv[i + 1][j + arr[i]])
////					vv[i][j] = true;
////		}
////	}
////	return vv[0][0];
////
////}
//
//
//// µÝ¹é
////int walk(vector<vector<int>>& matrix, int i, int j)
////{
////	if (i == matrix.size() - 1 && j == matrix[0].size() - 1)
////		return matrix[i][j];
////
////	if (i == matrix.size() - 1)
////		return matrix[i][j] + walk(matrix, i, j + 1);
////	if (j == matrix[0].size() - 1)
////		return matrix[i][j] + walk(matrix, i + 1, j);
////
////	int right = walk(matrix, i, j + 1);
////	int down = walk(matrix, i + 1, j);
////	return matrix[i][j] + min(right, down);
////}
//
//
////void test(string& str, int i,string cur)
////{
////	if (i == str.size() )
////	{
////		cout << cur << endl;
////		return;
////	}
////
////	test(str, i + 1, cur + str[i]);
////	test(str, i + 1, cur + " ");
////}
//
//
////´òÓ¡È«ÅÅÁÐ
//
//void process1(string cur, int i)
//{
//	if (i == cur.size())
//		cout << cur << endl;
//	for (int j = i; j < cur.size(); j++)
//	{
//		swap(cur[i], cur[j]);
//		process1(cur, i + 1);
//		//swap(cur[j], cur[i]);
//	}
//}
//void printAllPermutation1(string cur)
//{
//	process1(cur, 0);
//}
//
//int main()
//{
//
//	string str = "abc";
//	printAllPermutation1(str);
//	/*vector<vector<int>> vv{ { 1, 2, 3 }, { 2, 3, 1 }, { 4, 1, 3 } };
//	cout << walk(vv, 0, 0) << endl;*/
//
//
//	//vector<int> arr = { 3,2,5 };
//	//int sum = 0;
//	//for (int i = 0; i < arr.size(); i++)
//	//{
//	//	sum += arr[i];
//	//}
//	//int aim = 0;
//	//while (cin >> aim)
//	//{
//	//	cout << isSum(arr, arr.size(), sum, aim) << endl;
//	//}
//
//	system("pause");
//}
