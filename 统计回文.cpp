//#define _CRT_SECURE_NO_WARNINGS 1 
//#include <iostream>
//#include <string>
//using namespace std;
//bool Is_(string &s)
//{
//	int i = 0;
//	for (int i = 0; i < s.size() / 2; i++)
//	{
//		if (s[i] != s[s.size() - i - 1])
//			return false;
//	}
//	return true;
//}
//int main()
//{
//	string a;
//	string b;
//	getline(cin, a);
//	getline(cin, b);
//	int count = 0;
//	for (int i = 0; i < a.size(); i++)
//	{
//		string ret(a);
//		if (Is_(ret.insert(i, b)))
//			count++;
//	}
//	if (Is_(a += b))
//		count++;
//	cout << count << endl;
//	system("pause");
//}