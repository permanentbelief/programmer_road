//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//
//void DFS(vector<string>& vs, string& str, string temp,vector<bool>& book, int pos)
//{
//	if (temp.size() == str.size())
//	{
//		vs.push_back(temp);
//		return;
//	}
//	for (int i = pos; i < str.size(); i++)
//	{
//		//if (book[i] == 0)
//		//{
//			temp += str[pos];
//			//book[i] = 1;
//			DFS(vs, str, temp, book, i+1);
//			temp.pop_back();
//			//book[i] = 0;
//		//}
//	}
//}
//int main()
//{
//	int numbersize1 = 0;
//	int numbersize2 = 0;
//	int n = 0;
//	while (cin >> numbersize1 >> numbersize2 >> n)
//	{
//		int size = numbersize1 + numbersize2;
//		vector<string> vs;
//		string str;
//		for (int i = 0; i < numbersize1; i++)
//		{
//			str += 'a';
//		}
//		for (int i = 0; i < numbersize2; i++)
//		{
//			str += 'z';
//		}
//		vector<bool> book(str.size());
//		DFS(vs, str, "", book,0);
//		sort(vs.begin(), vs.end());
//		vs.erase(unique(vs.begin(), vs.end()), vs.end());
//		if (n >= vs.size())
//		{
//			cout << "-1" << endl;
//			return 0;
//		}
//		else
//		cout << vs[n] << endl;
//	}
//}
#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//À„∑®∏¥‘”∂»Ã´¥Û
void DFS(vector<string>& vs, string& str, string temp, vector<bool>& book, int pos)
{
	if (temp.size() == str.size())
	{
		vs.push_back(temp);
		return;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (book[i] == 0)
		{
			temp += str[i];
			book[i] = 1;
			DFS(vs, str, temp, book, 0);
			temp.pop_back();
			book[i] = 0;
		}
	}
}
int main()
{
	int numbersize1 = 0;
	int numbersize2 = 0;
	int n = 0;
	while (cin >> numbersize1 >> numbersize2 >> n)
	{
		int size = numbersize1 + numbersize2;
		vector<string> vs;
		string str;
		for (int i = 0; i < numbersize1; i++)
		{
			str += 'a';
		}
		for (int i = 0; i < numbersize2; i++)
		{
			str += 'z';
		}
		vector<bool> book(str.size());
		DFS(vs, str, "", book, 0);
		sort(vs.begin(), vs.end());
		vs.erase(unique(vs.begin(), vs.end()), vs.end());
		if (n >= vs.size())
		{
			cout << "-1" << endl;
			return 0;
		}
		else
			cout << vs[n+1] << endl;
	}
}