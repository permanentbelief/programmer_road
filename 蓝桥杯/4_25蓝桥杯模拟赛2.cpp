#define _CRT_SECURE_NO_WARNINGS 1 

/*
��������
����С����������һ��ȥ����ֲ�������Ǵ���һЩ���Լ�ʵ���Ҿ����о�����С���硣
  ����С����������һ���� n ���ˣ����Ǿ���������ѡ����һ��յ���ÿ������ѡ��һ���ʺ�ֲ����λ�ã��ܹ� n ��������׼�����Լ��������綼ֲ��ȥ��
	����Ȼ��������������һ�����ѣ��е�����Ƚϴ󣬶��е�λ�ð�̫��������������ֲ��ȥ���ײ��һ��
	  �������ǽ�������һ��Բ��Բ���������ҵ�λ���ϡ������������Ӧ��Բ�ཻ�����������Ͳ��ʺ�ͬʱֲ�£����в���Ӱ�죩����Ϊ��������ͻ��
		����С���������Ǿ����Ⱥϼƺϼƣ�ֻ�����е�һ������ֲ��ȥ����֤û�л����ͻ����������ͬʱϣ����Щ�����ܸ��ǵ�����ͣ�Բ����ͣ����
		  �����ʽ
		  ��������ĵ�һ�а���һ������ n ����ʾ��������׼��ֲ����λ������
			���������� n �У�ÿ���������� x, y, r����ʾһ�����ڿյ��ϵĺᡢ������Ͱ뾶��
			  �����ʽ
			  �������һ�а���һ����������ʾ�ڲ���ͻ�¿���ֲ��������͡�����ÿ�������������Բ���ʵ���������������𰸳���Բ���ʺ��ֵ��Ӧ����һ����������
				��������
				6
				1 1 2
				1 4 2
				1 7 2
				4 1 2
				4 4 2
				4 7 2
				�������
				12
				����������ģ��Լ��
				�������� 30% ������������1 <= n <= 10��
				  �������� 60% ������������1 <= n <= 20��
					����������������������1 <= n <= 30��0 <= x, y <= 1000��1 <= r <= 1000��
*/

/*
��������
����2015�꣬ȫ�й�ʵ���˻���ͨ�硣��Ϊһ�����������ߣ�С�����ڰ���һ��һ·�ϵĹ���ͨ�硣
  ������һ�Σ�С��Ҫ���� n ����ׯͨ�磬���� 1 �Ŵ�ׯ���ÿ��Խ���һ������վ�������ĵ��㹻���д�ׯʹ�á�
	�������ڣ��� n ����ׯ֮�䶼û�е���������С����ҪҪ�����Ǽ������������Щ��ׯ��ʹ�����д�ׯ��ֱ�ӻ��ӵ��뷢��վ��ͨ��
	  ����С�����������д�ׯ��λ�ã����꣩�͸߶ȣ����Ҫ����������ׯ��С����Ҫ����������ׯ֮������������ϸ߶Ȳ��ƽ������ʽ������Ϊ����Ϊ (x_1, y_1) �߶�Ϊ h_1 �Ĵ�ׯ������Ϊ (x_2, y_2) �߶�Ϊ h_2 �Ĵ�ׯ֮�����ӵķ���Ϊ
		����sqrt((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2))+(h_1-h_2)*(h_1-h_2)��
		  ��������ʽ�� sqrt ��ʾȡ�����ڵ�ƽ��������ע�����ŵ�λ�ã��߶ȵļ��㷽ʽ���������ļ��㷽ʽ��ͬ��
			�������ھ������ޣ������С������������Ҫ���Ѷ��ٷ��ò���ʹ�� n ����ׯ��ͨ�硣
			  �����ʽ
			  ��������ĵ�һ�а���һ������ n ����ʾ��ׯ��������
				���������� n �У�ÿ���������� x, y, h���ֱ��ʾһ����ׯ�ĺᡢ������͸߶ȣ����е�һ����ׯ���Խ�������վ��
				  �����ʽ
				  �������һ�У�����һ��ʵ�����������뱣�� 2 λС������ʾ�𰸡�
					��������
					4
					1 1 3
					9 9 7
					8 8 6
					4 5 4
					�������
					17.41
					����������ģ��Լ��
					�������� 30% ������������1 <= n <= 10��
					  �������� 60% ������������1 <= n <= 100��
						����������������������1 <= n <= 1000��0 <= x, y, h <= 10000��


						  ��������
						  �������һ�����е��������ǰһ���ż�����ǰһ��С�����Ϊһ���ڶ����С��� a[2i]<a[2i-1], a[2i+1]>a[2i]��
							����С����֪��������Ϊ m��ÿ�������� 1 �� n ֮����������İڶ�����һ���ж��ٸ���
							  �����ʽ
							  ��������һ�а����������� m��n��
								�����ʽ
								�������һ����������ʾ�𰸡��𰸿��ܴܺ�������𰸳���10000��������
								  ��������
								  3 4
								  �������
								  14
								  ����˵��
								  ���������Ƿ���Ҫ��İڶ����У�
									����2 1 2
									  ����2 1 3
										����2 1 4
										  ����3 1 2
											����3 1 3
											  ����3 1 4
												����3 2 3
												  ����3 2 4
													����4 1 2
													  ����4 1 3
														����4 1 4
														  ����4 2 3
															����4 2 4
															  ����4 3 4
																����������ģ��Լ��
																�������� 20% ������������1 <= n, m <= 5��
																  �������� 50% ������������1 <= n, m <= 10��
																	�������� 80% ������������1 <= n, m <= 100��
																	  ����������������������1 <= n, m <= 1000��
*/
/*

��������
��������һ�� n �� m �еı�����ǿ���ʹ�������ķ�ʽ������������������������ǳ���õı��Ϊһ����������
  �������磬һ�� 4 �� 5 �е������������£�
	����1 2 3 4 5
	  ����14 15 16 17 6
		����13 20 19 18 7
		  ����12 11 10 9 8
			�����ʽ
			��������ĵ�һ�а����������� n, m���ֱ��ʾ���������������������
			  �����ڶ��а����������� r, c����ʾҪ����кź��кš�
				�����ʽ
				�������һ����������ʾ���������е� r �е� c �е�Ԫ�ص�ֵ��
				  ��������
				  4 5
				  2 2
				  �������
				  15
				  ����������ģ��Լ��
				  �������� 30% ������������2 <= n, m <= 20��
					�������� 70% ������������2 <= n, m <= 100��
					  ����������������������2 <= n, m <= 1000��1 <= r <= n��1 <= c <= m��
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

//double Values(vector<pair<int, int>>& vp, vector<int>& heights, int i, int j)
//{
//	return (sqrt((vp[i].first - vp[j].first)*(vp[i].first - vp[j].first) + (vp[i].second
//		- vp[j].second)*(vp[i].second - vp[j].second)) + (heights[i] - heights[j])
//		*(heights[i] - heights[j]));
//}
//
//double min_ = INT_MAX;
//
//void dfs(vector<pair<int,int>>& vp,vector<int>& heights, int i, vector<bool>&books,double sum,int n,
//	vector<int> v)
//{
//	if (v.size() == n)
//	{
//		min_ = min(min_, sum);
//		return;
//	}
//	for (int i = 1; i < n; i++)
//	{
//		if (books[i] == false)
//		{
//			books[i] = true;
//			double c =  Values(vp, heights,v.back(),i);
//			v.push_back(i);
//			sum += c;
//			dfs(vp, heights, i, books, sum, n, v);
//			sum -= c;
//			v.pop_back();
//			books[i] = false;
//		}
//
//	}
//}
//
//
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		int x = 0;
//		int y = 0;
//		int h = 0;
//
//		vector<pair<int, int>> vp(1001);
//		vector<int> heights(1001);
//		vector < vector<double>> values(n,vector<double>(n)); // ��i��j�ļ�ֵ
//		for (int i = 0; i < n; i++)
//		{
//			cin >> x >> y >> h;
//			vp[i] = make_pair(x, y);
//			heights[i] = h;
//		}
//		for (int i = 1; i < n; i++)
//		{
//			values[0][i] = Values(vp, heights, 0, i);
//		}
//		double sum = 0.0;
//		for (int i = 1 ; i < n; i++)
//		{
//			sum += values[0][i];
//		}
//		vector<bool> books(n);
//		double sums = 0.0;
//		vector<int> v = { 0 };
//		dfs(vp, heights, 1, books, sums, n, v);
//		double min_sum = INT_MAX;
//		min_sum = min(sum, min_);
//		printf("%.2lf\n", min_sum);
//	}
//}
//


//bool Valid(pair<int,int>& a,pair<int,int>&b, int& c) // ������((a-b)��ƽ�� + 
//{ 
//	int count1 = (a.first - b.first)*(a.first - b.first);
//	int count2 = (a.second - b.second)*(a.second - b.second);
//
//	if (sqrt(count1 + count2) >= c)
//	{
//		return true;
//	}
//	return false;
//}
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		int x = 0;
//		int y = 0;
//		int r = 0;
//		vector<pair<int, int>> vp;
//		vector<int> vr;
//		vector<int> books(n, -1);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> x >> y >> r;
//			vp.push_back(make_pair(x,y));
//			vr.push_back(r);
//		}
//
//		for (int j = 0; j < n - 1; j++)
//		{
//			for (int i = j + 1; i < n ; i++)
//			{
//				if (books[i] != 0 && books[j] != 0)
//				{
//					int c = vr[i] + vr[j];
//					if (Valid(vp[i], vp[j], c))
//					{
//						if (books[i] != 0)
//							books[i] = 1;
//						if (books[j] != 0)
//							books[j] = 1;
//					}
//					else
//					{
//						if (vr[i] <= vr[j])
//						{
//							books[j] = 1;
//							books[i] = 0;
//						}
//
//						else
//						{
//							books[i] = 1;
//							books[j] = 0;
//						}
//
//					}
//				}
//					
//
//			}
//			
//		}
//	
//		long long sum = 0;
//		for (int i = 0; i < n; i++)
//		{
//			if (books[i] == 1)
//				sum += (vr[i] * vr[i]);
//		}
//		cout << sum << endl;
//	}
//
//}
//void dfs(vector<int> v, int m, int n,int& count2)
//{
//	if (v.size() == m)
//	{
//		count2++;
//		count2 %= N;
//		return;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (v.empty())
//		{
//			v.push_back(i);
//			dfs(v, m, n,count2);
//			v.pop_back();
//		}
//		else if (v.size() % 2 == 1 && i < v.back())
//		{
//			v.push_back(i);
//			dfs(v, m, n, count2);
//			v.pop_back();
//		}
//		else if (v.size() % 2 == 0 && i > v.back())
//		{
//			v.push_back(i);
//			dfs(v, m, n, count2);
//			v.pop_back();
//		}
//	}
//}
//int main()
//{
//	int m = 0; // m�ǰڶ�����λ��
//	int n = 0; // [1,n]
//
//	while (cin >> m >> n)
//	{
//		vector<int> v;
//		int count2 = 0;
//		dfs(v, m, n, count2);
//		cout << count2 << endl;
//	}
//
//}

//int main()
//{
//	int n = 0;
//	int m = 0;
//	int r = 0;
//	int c = 0;
//	while (cin >> n >> m >> r >> c)
//	{
//		vector<vector<int>>(n, vector<int>(m, 0));
//
//	}
//}
//int main()
//{
//	static string dicts = "abcdefghijklmnopqrstuvwxyz";
//	map<char, int> mymap;
//	for (int i = 0; i < dicts.size(); i++)
//	{
//		if (i < 23)
//			mymap[dicts[i]] = i + 3;
//		else
//			mymap[dicts[i]] = (i + 3) % 26;
//	}
//	string str;
//	while (cin >> str)
//	{
//		
//		//cout << (char)(str[0] + 3) << endl;
//		for (int i = 0; i < str.size(); i++)
//		{
//			str[i] = mymap[str[i]] + 'a' ;
//		}
//		cout << str << endl;
//	}
//
//}

//int main()
//{
//	int n = 0;
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	cin >> n;
//	cin >> a >> b >> c;
//	int count2 = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (i % a != 0 && i % b != 0 && i%c != 0)
//		{
//			cout << i << " ";
//			count2++;
//		}
//	}
//
//	cout << count2 << endl;
//	//cout << 1%3 << endl;
//	system("pause");
//}


int count1 = 0;
//char c1 = "(";
//char c2 = ")";
//void dfs(vector<char>& v, int left, int right)
//{
//	if (left == 0 && right == 0)
//	{
//		count1++;
//		return;
//	}
//	
//	if (left > 0)
//	{
//		v.push_back('(');
//		dfs(v, left - 1, right);
//	}
//	
//	if (right > left)
//	{
//		v.push_back(')');
//		dfs(v, left, right - 1);
//	}
//		
//
//}

//#include <set>
//int main()
//{
//	//vector<char>v;
//	//dfs(v, 4, 4);
//	//cout << count1 << endl;
//	string str = "LANQIAO";
//	set<vector<int>> ss;
//	sort(str.begin(), str.end());
//	vector<int> v = { 1, 1, 2, 3, 4, 5, 6 };
//	int count2 = 0;
//	//do
//	//{
//	//	ss.insert(str);
//	//	count2++;
//
//	//} while (next_permutation(str.begin(), str.end()));
//	do
//	{
//		ss.insert(v);
//		count2++;
//	} while (next_permutation(v.begin(), v.end()));
//	cout << count2 << endl;
//	cout << ss.size() << endl;
//	system("pause");
//}


int count2 = 0;
void Print(vector<vector<int>>&v, int tR, int tC, int dR, int dC,int r, int c)
{
	if (tR == dR )
	{
		for (int i = tC; i <= dC; i++)
		{
			if(tR == r && i == c)
			{
				cout << count2 << endl;
				return;
			}
				

		}
	}
	else if (tC == dC )
	{
		for (int i = tR; i <= dR; i++)
		{
			if (tC == c && i == r)
			{
				cout << count2 << endl;
				return;
			}
		}
	}
	else
	{
		int curC = tC;
		int curR = tR;
		while (curC != dC)
		{
			
			count2++;
			if (curR == r && curC == c)
			{
				cout << count2 << endl;
				return;
			}
			curC++;
		}
		while (curR != dR)
		{
			
			count2++;
			if (curR == r && curC == c)
			{
				cout << count2 << endl;
				return;
			}
			curR++;
		}
		while (curC != tC)
		{
			
			count2++;
			if (curR == r && curC == c)
			{
				cout << count2 << endl;
				return;
			}
			curC--;
		}
		while (curR != tR)
		{
			
			count2++;
			if (curR == r && curC == c)
			{
				cout << count2 << endl;
				return;
			}
			curR--;
		}
	}
}
//int main()
//{
//	int n = 0;
//	int m = 0;
//	int r = 0;
//	int c = 0;
//	while (cin >> n >> m >> r >> c)
//	{
//		vector<vector<int>> v(n, vector<int>(m));
//		int tR = 0;
//		int tC = 0;
//		int dR = n - 1;
//		int dC = m - 1;
//		while (tR <= dR && tC <= dC)
//		{
//			Print(v, tR++, tC++, dR--, dC--, r - 1, c - 1);
//		}
//
//		count2 = 0;
//	}
//}