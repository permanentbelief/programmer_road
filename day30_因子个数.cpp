#define _CRT_SECURE_NO_WARNINGS 1 
// write your code here cpp
#include <iostream>
using namespace std;


// 代码 算法复杂度太高 跑不过  6 对应输出为 2 这个方法也对！只不过是 i < num  未能在规定时间内结束运行
int  main()

{
	int n = 0;
	while (cin >> n)
	{
		int count = 0;
		int num = n;
		for (int i = 2; i < num; i++)
		{
			int flag = 0;
			while (n % i == 0)
			{
				n /= i;
				flag = 1;
			}
			if (flag == 1)
				count++;

		}
		if (count == 0)
			count++;
		cout << count << endl;
	}
	system("pause");
}

//#include <iostream>
//#include <math.h>
//using namespace std;
//
//int  main()
//
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		int count = 0;
//		int num = n;
//		for (int i = 2; i < sqrt(n); i++) // 如果刚开始 i = 2 不小于 n的开根号 就进不去循环
//		{
//			int flag = 0;
//			if (n%i == 0)
//			{
//				while (n % i == 0)
//				{
//					n /= i;
//				}
//				count++;
//			}
//			
//		}
//		if (n != 1) //在这里 综合两种情况 一种是一开始没有进入循环， 另一种是进入循环 但是count并没有加加的，也就是count为0， count==0 说明除了1以外没有其他因数，
//			//是质数， 所以在这里 相当于也把输入的n是质数考虑进去 n!=1 && n是质数 所以count++ , 相当于把自己加进去了。第三种就是 进入循环之后count++了， n的值也变了，接下来就
//  进入不到循环里面，不满足 i<sqrt(n)的条件, 但此时n！=0， 也进入不到循环里面
//			count++; //但是在这里换条件 换成 conut == 0 就不对。 只综合考虑了一种情况 没有进入for循环， 或者是进入了for循环， count++了一次，count！=0 ，但是i++后不满足<sqrt(n)的条件 如6 对应输出为2， 你的输出为1
//		cout << count << endl;
//
//
//	}
//	system("pause");
//}