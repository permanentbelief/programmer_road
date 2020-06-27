#define _CRT_SECURE_NO_WARNINGS 1 

//#include <iostream>
//#include <string>
//using namespace std;
//
//
////2的n次方 模板
//
//string pow(int n)
//{
//	string res = "1";
//	for (int i = 0; i < n; i++)
//	{
//		int carry = 0;
//		int mult = 0;
//		for (int j = res.size() - 1; j >= 0; j--)
//		{
//			int tmpNum = res[j] - '0';
//			mult = (tmpNum << 1) + carry;
//			carry = mult / 10;
//			res[j] = mult % 10 +  '0';
//		}
//		if (carry > 0)
//		{
//			res.insert(res.begin(), carry + '0');
//		}
//	}
//	return res;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	cout << pow(n) << endl;
//	system("pause");
//
//}