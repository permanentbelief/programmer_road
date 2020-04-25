#define _CRT_SECURE_NO_WARNINGS 1 

/*
问题描述
　　小明和朋友们一起去郊外植树，他们带了一些在自己实验室精心研究出的小树苗。
  　　小明和朋友们一共有 n 个人，他们经过精心挑选，在一块空地上每个人挑选了一个适合植树的位置，总共 n 个。他们准备把自己带的树苗都植下去。
	　　然而，他们遇到了一个困难：有的树苗比较大，而有的位置挨太近，导致两棵树植下去后会撞在一起。
	  　　他们将树看成一个圆，圆心在他们找的位置上。如果两棵树对应的圆相交，这两棵树就不适合同时植下（相切不受影响），称为两棵树冲突。
		　　小明和朋友们决定先合计合计，只将其中的一部分树植下去，保证没有互相冲突的树。他们同时希望这些树所能覆盖的面积和（圆面积和）最大。
		  输入格式
		  　　输入的第一行包含一个整数 n ，表示人数，即准备植树的位置数。
			　　接下来 n 行，每行三个整数 x, y, r，表示一棵树在空地上的横、纵坐标和半径。
			  输出格式
			  　　输出一行包含一个整数，表示在不冲突下可以植树的面积和。由于每棵树的面积都是圆周率的整数倍，请输出答案除以圆周率后的值（应当是一个整数）。
				样例输入
				6
				1 1 2
				1 4 2
				1 7 2
				4 1 2
				4 4 2
				4 7 2
				样例输出
				12
				评测用例规模与约定
				　　对于 30% 的评测用例，1 <= n <= 10；
				  　　对于 60% 的评测用例，1 <= n <= 20；
					　　对于所有评测用例，1 <= n <= 30，0 <= x, y <= 1000，1 <= r <= 1000。
*/

/*
问题描述
　　2015年，全中国实现了户户通电。作为一名电力建设者，小明正在帮助一带一路上的国家通电。
  　　这一次，小明要帮助 n 个村庄通电，其中 1 号村庄正好可以建立一个发电站，所发的电足够所有村庄使用。
	　　现在，这 n 个村庄之间都没有电线相连，小明主要要做的是架设电线连接这些村庄，使得所有村庄都直接或间接的与发电站相通。
	  　　小明测量了所有村庄的位置（坐标）和高度，如果要连接两个村庄，小明需要花费两个村庄之间的坐标距离加上高度差的平方，形式化描述为坐标为 (x_1, y_1) 高度为 h_1 的村庄与坐标为 (x_2, y_2) 高度为 h_2 的村庄之间连接的费用为
		　　sqrt((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2))+(h_1-h_2)*(h_1-h_2)。
		  　　在上式中 sqrt 表示取括号内的平方根。请注意括号的位置，高度的计算方式与横纵坐标的计算方式不同。
			　　由于经费有限，请帮助小明计算他至少要花费多少费用才能使这 n 个村庄都通电。
			  输入格式
			  　　输入的第一行包含一个整数 n ，表示村庄的数量。
				　　接下来 n 行，每个三个整数 x, y, h，分别表示一个村庄的横、纵坐标和高度，其中第一个村庄可以建立发电站。
				  输出格式
				  　　输出一行，包含一个实数，四舍五入保留 2 位小数，表示答案。
					样例输入
					4
					1 1 3
					9 9 7
					8 8 6
					4 5 4
					样例输出
					17.41
					评测用例规模与约定
					　　对于 30% 的评测用例，1 <= n <= 10；
					  　　对于 60% 的评测用例，1 <= n <= 100；
						　　对于所有评测用例，1 <= n <= 1000，0 <= x, y, h <= 10000。


						  问题描述
						  　　如果一个序列的奇数项都比前一项大，偶数项都比前一项小，则称为一个摆动序列。即 a[2i]<a[2i-1], a[2i+1]>a[2i]。
							　　小明想知道，长度为 m，每个数都是 1 到 n 之间的正整数的摆动序列一共有多少个。
							  输入格式
							  　　输入一行包含两个整数 m，n。
								输出格式
								　　输出一个整数，表示答案。答案可能很大，请输出答案除以10000的余数。
								  样例输入
								  3 4
								  样例输出
								  14
								  样例说明
								  　　以下是符合要求的摆动序列：
									　　2 1 2
									  　　2 1 3
										　　2 1 4
										  　　3 1 2
											　　3 1 3
											  　　3 1 4
												　　3 2 3
												  　　3 2 4
													　　4 1 2
													  　　4 1 3
														　　4 1 4
														  　　4 2 3
															　　4 2 4
															  　　4 3 4
																评测用例规模与约定
																　　对于 20% 的评测用例，1 <= n, m <= 5；
																  　　对于 50% 的评测用例，1 <= n, m <= 10；
																	　　对于 80% 的评测用例，1 <= n, m <= 100；
																	  　　对于所有评测用例，1 <= n, m <= 1000。
*/
/*

问题描述
　　对于一个 n 行 m 列的表格，我们可以使用螺旋的方式给表格依次填上正整数，我们称填好的表格为一个螺旋矩阵。
  　　例如，一个 4 行 5 列的螺旋矩阵如下：
	　　1 2 3 4 5
	  　　14 15 16 17 6
		　　13 20 19 18 7
		  　　12 11 10 9 8
			输入格式
			　　输入的第一行包含两个整数 n, m，分别表示螺旋矩阵的行数和列数。
			  　　第二行包含两个整数 r, c，表示要求的行号和列号。
				输出格式
				　　输出一个整数，表示螺旋矩阵中第 r 行第 c 列的元素的值。
				  样例输入
				  4 5
				  2 2
				  样例输出
				  15
				  评测用例规模与约定
				  　　对于 30% 的评测用例，2 <= n, m <= 20。
					　　对于 70% 的评测用例，2 <= n, m <= 100。
					  　　对于所有评测用例，2 <= n, m <= 1000，1 <= r <= n，1 <= c <= m。
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
//		vector < vector<double>> values(n,vector<double>(n)); // 从i到j的价值
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


//bool Valid(pair<int,int>& a,pair<int,int>&b, int& c) // 根号下((a-b)的平方 + 
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
//	int m = 0; // m是摆动序列位数
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