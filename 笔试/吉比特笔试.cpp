#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;


//void DFS(string& str, string tmp, int& count, vector<bool>& books, int M)
//{
//	if (tmp.size() == str.size())
//	{
//		//for (auto e : tmp)
//		//{
//		//	cout << e << " ";
//		//}
//		//cout << endl;
//		if (stoi(tmp) % M == 0)
//		{
//			count++;
//		}
//	}
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (books[i] == false)
//		{
//			books[i] = true;
//			tmp += str[i];
//			DFS(str, tmp, count,books, M);
//			books[i] = false;
//			tmp.pop_back();
//		}
//	}
//}


//string itos(int i)
//{
//	stringstream s;
//	string tmp;
//	s << i;
//	s >> tmp;
//	return tmp;
//}
//long long stoi(string& str)
//{
//	stringstream s;
//	long long i = 0;
//	s << str;
//	s >> i;
//	return i;
//}
//int main()
//{
//
//
//
//	long long S = 0;
//	int M = 0;
//
//	while (cin >> S >> M)
//	{
//	   
//		int count = 0;
//
//		string str = stoi(S);
//		sort(str.begin(), str.end());
//		do
//		{
//			if (itos(str) % M == 0)
//			{
//				count++;
//			}
//
//		} while (next_permutation(str.begin(),str.end()));
//
//		cout << count << endl;
//	}
//}


bool Prime(int n)
{
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	cout << n << endl;
	return true;
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		int min_ = n;
		int flag = 0;
		int count = 0;
		for (int i = 3; i <= n; i++)
		{
			if (Prime(i))
			{
				count++;
			}
			//if (Prime(i) && abs(i - n) <= min_)
			//{
			//	if (abs(i - n) == min_)
			//	{
			//		min_ = abs(i - n);
			//	}
			//	else
			//	{
			//		min_ = abs(i - n);
			//		flag = i;
			//	}
			//}
		}
		cout << endl;
		cout << count << endl;
	}
}


/*

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
const int N = 200000;
int prime[N] = {0}, num_prime = 0;
int isNotPrime[N] = {1, 1};

int main(){
for(int i = 2 ; i < N ; i ++){
if(!isNotPrime[i])
prime[num_prime++]=i;
for(int j = 0 ; j < num_prime && i * prime[j] <  N ; j ++){
isNotPrime[i * prime[j]] = 1;
if( !(i % prime[j] ))
break;
}
}


*/