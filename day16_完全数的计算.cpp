// #define _CRT_SECURE_NO_WARNINGS 1 
// 方法一
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n = 1;
//	
//		/*if (n <= 0 || n > 500000)
//		{
//			cout << -1 << endl;
//			break;
//		}*/
//		int count = 0;
//		int sum = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			sum = 0;
//			for (int k = i - 1; k > 0; k--) // 计算所有的约数和，
//			{
//				if (i%k == 0)
//					sum += k;
//			}
//			if (sum == i)
//				count++;
//
//		}
//		cout << count << endl;
//	
//	system("pause");
//}


/*  方法二
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num = 0;
	while (cin >> num)
	{
		vector<int> v;
		int count = 0;
		int k = 1; //必须是1
		while (k < num)
		{
			int sum = 0;
			for (int i = 1; i < k; i++)
			{

				if (k % i == 0)
					sum += i;

			}
			if (sum == k)
			{
				count++;
				v.push_back(k);
			}
				
			k++;
		}
		cout << count << endl;
		cout << endl;
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << endl;
		}
	}
	system("pause");

}*/