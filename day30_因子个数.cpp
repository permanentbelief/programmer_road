#define _CRT_SECURE_NO_WARNINGS 1 
// write your code here cpp
#include <iostream>
using namespace std;


// ���� �㷨���Ӷ�̫�� �ܲ���  6 ��Ӧ���Ϊ 2 �������Ҳ�ԣ�ֻ������ i < num  δ���ڹ涨ʱ���ڽ�������
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
//		for (int i = 2; i < sqrt(n); i++) // ����տ�ʼ i = 2 ��С�� n�Ŀ����� �ͽ���ȥѭ��
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
//		if (n != 1) //������ �ۺ�������� һ����һ��ʼû�н���ѭ���� ��һ���ǽ���ѭ�� ����count��û�мӼӵģ�Ҳ����countΪ0�� count==0 ˵������1����û������������
//			//�������� ���������� �൱��Ҳ�������n���������ǽ�ȥ n!=1 && n������ ����count++ , �൱�ڰ��Լ��ӽ�ȥ�ˡ������־��� ����ѭ��֮��count++�ˣ� n��ֵҲ���ˣ���������
//  ���벻��ѭ�����棬������ i<sqrt(n)������, ����ʱn��=0�� Ҳ���벻��ѭ������
//			count++; //���������ﻻ���� ���� conut == 0 �Ͳ��ԡ� ֻ�ۺϿ�����һ����� û�н���forѭ���� �����ǽ�����forѭ���� count++��һ�Σ�count��=0 ������i++������<sqrt(n)������ ��6 ��Ӧ���Ϊ2�� ������Ϊ1
//		cout << count << endl;
//
//
//	}
//	system("pause");
//}