#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;



/*
1
8 1 100
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;



/*

import java.util.Arrays;
import java.util.Scanner;

public class Ȧ������ {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] nums = new int[n];
		for (int i = 0; i < n; i++) {
			nums[i] = in.nextInt();
		}
		int res = angleEnable(nums);
		System.out.println(res);

	}


	public static int angleEnable(int[] nums) {
		//����߳���2���϶�����ʵ��
		if (nums == null || nums.length <= 2) return -1;


		//������ n-1�ߵĺʹ�����ߣ�������ɷ�ն����

		int sum = 0; //ǰN����֮��
		int max = 0;//ǰN�����е����ֵ
		for (int i = 0; i < nums.length; i++) {
			sum += nums[i];
			max = max > nums[i] ? max : nums[i];
			//���i > 1�����������1��˵��ֻ��2���ߣ�������ζ����ɲ��˵ģ�
			//����sum - max > max����ǰN���в���Max��ֵ֮�ʹ���Max��˵���ҵ��ˣ�ֱ�ӷ���
			//���ע�� + 1 ����Ϊi��0��ʼ
			if (i > 1 && sum > 2 * max) return i + 1;
		}
		//���������ж���������˵��������
		return -1;
	}

*/


int main()
{
	int q = 0;
	while (cin >> q)
	{
		for (int j = 0; j < q; j++)
		{
			long long k, l, r = 0;
			cin >> k >> l >> r;
			vector<long long> v(r - l + 1); //[0,r-l]
			long long max_ = INT_MIN;
			long long  flag = 0;
			for (long long i = l; i <= r; i++)
			{
				long long count = 0;
				long long temp = i;
				while (temp > 0)
				{
					if (temp % k == k - 1)
					{
						count++;
					}
					temp /= k;
				}
				v[i - l] = count;
				if (count > max_)
				{
					max_ = count;
					flag = i - l;
				}
			}
			long long t = flag + 1;
			cout << t << endl;
		}
	}
}