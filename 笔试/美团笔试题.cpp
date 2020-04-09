#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

//int main()
//{
//	int k = 0;
//	while (cin >> k)
//	{
//		int  out_ = 0;
//		if (k < 3 || k == 4)
//		{
//			out_ = 0;
//		}
//		if (k == 3)
//		{
//			out_ = 6;
//		}
//		else{
//			out_ = pow(3, k);
//			out_ %= 1000000007;
//		}
//		cout << out_ << endl;
//	}
//}


// T3
//int main()
//{
//	int n = 0;
//	int k = 0;
//	while (cin >> n >> k) // 10 3
//	{
//		int flag = 0;
//		int count = 1;
//		int tmp = n;
//		while (1)
//		{
//			int tmp = pow(k, count);
//			if ( (n / tmp ) > 0)
//			{
//				count++;
//			}
//			else
//			{
//				break;
//			}
//		}
//
//		// 
//		//int sum = 0; 
//		int out_come = 0;
//		for (int i = 1; i < 1000; i++)
//		{
//			int flag = 0;
//			for (int j = 0; j < 3; j++)
//			{
//				flag += i/pow(k, j);
//			}
//			if (flag == n)
//			{
//			    out_come = i;
//				break;
//			}  
//		}
//		cout << out_come << endl;
//
//	
//	}
//}

// T2
int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> start(n);
		vector<int> ends(n);
		for (int i = 0; i < n; i++)
		{
			cin >> start[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> ends[i];
		}
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (start[i] == ends[n-1])
			{
				count = n - 1 - i;
				break;
			}
		}
		cout << count << endl;

	}
}
/*
5
5 3 1 4 2
2 4 5 1 3



*/


// T1
//int main()
//{
//	int x = 0;
//	string str;
//	int n = 0;
//	while (cin >> x >> str >> n)
//	{
//
//
//
//		int out_x = 0;
//		string out;
//		int a[2] = { 0 };
//		int k = 0;
//		for (int i = 0; i < str.size(); i++)
//		{
//			int sum = 0;
//			while (i < str.size() && str[i] != ':')
//			{
//				sum = sum * 10 + str[i] - '0';
//				i++;
//			}
//			a[k++] = sum;
//		}
//		int hour = a[0];
//		int second = a[1];
//
//		int sum_ = hour * 60 + second;
//		if (sum_ - n >= 0)
//		{
//			out_x = x;
//			int hour_ = 0;
//			int second_ = 0;
//			hour_ = (sum_ - n) / 60;
//			second_ = (sum_ - n) % 60;
//			
//			out += hour_ < 10 ? ("0" + to_string(hour_)) : to_string(hour_);
//			out += ":";
//			out += second_ < 10 ? ("0" + to_string(second_)) : to_string(second_);
//		}
//		else
//		{
//			
//			if ( ((n - sum_) / 60 )> 24)
//			{
//				int outs = 0;
//				int days_ = ((n - sum_) / 60) / 24;
//				for (int i = 0; i < days_ + 1; i++)
//				{
//					if (x == 1)
//					{
//						
//						x = 7;
//					}
//					else
//					{
//						x = x - 1;
//					}
//				}
//				out_x = x;
//				outs = (n - sum_) % 1440;
//				int hour_ = 23 - outs / 60;
//				int second_ = 60 - outs % 60;
//				out += hour_ < 10 ? ("0" + to_string(hour_)) : to_string(hour_);
//				out += ":";
//				out += second_ < 10 ? ("0" + to_string(second_)) : to_string(second_);
//			}
//			else
//			{
//				out_x = x == 1 ? 7 : x - 1;
//				int n_ = n - sum_; //
//				int hour_ = 0;
//				int second_ = 0;
//				hour_ = 23 - n_ / 60;
//				second_ = 60 - n_ % 60;
//				out += hour_ < 10 ? ("0" + to_string(hour_)) : to_string(hour_);
//				out += ":";
//				out += second_ < 10 ? ("0" + to_string(second_)) : to_string(second_);
//			}
//			
//			
//			
//		}
//		cout << out_x << endl;
//		cout << out << endl;
//	}
//	
//}