#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//int main()
//{
//	int N = 0;
//	cin >> N;
//	string str;
//	vector<string> vs(N);
//	getchar();
//	for (int i = 0; i < N; i++)
//	{
//		getline(cin, str);
//		vs[i] = str;
//	}
//	
//	vector<vector<pair<int, int>>> vp(N);
//	for (int i = 0; i < vs.size(); i++)
//	{
//		vector<int> v;
//		
//		for (int j = 2; j < vs[i].size(); j++)
//		{
//			int sum = 0;
//			while (j < vs[i].size() && vs[i][j] != ' ')
//			{
//				sum = sum * 10 +  (vs[i][j] - '0');
//				j++;
//			}
//			v.push_back(sum);
//		}
//		for (int k = 0; k < v.size(); k+= 2)
//		{
//			vp[i].push_back(make_pair(v[k],v[k+1]));
//		}
//	}
//
//	int sum = 0;
//	cin >> sum;
//	vector<int> vsum(sum);
//	for (int k = 0; k < sum; k++)
//	{
//		cin >> vsum[k];
//		int a = vsum[k];
//		int max_ = 0;
//		int max_index = 1;
//		for (int i = 0; i < vp.size(); i++)
//		{
//			for (int j = 0; j < vp[i].size()- 1; j++)
//			{
//				if (a < vp[i][j].second)
//				{
//					if ((vp[i ][j].second - a)*vp[i][j].first > max_)
//					{
//						max_ = (vp[i][j].second - a)*vp[i][j].first;
//						max_index = vs[i][0];
//					}
//				}
//			}
//		}
//		cout << max_index << endl;
//	}
//
//	
//	system("pause");
//}

/*
1
3 0 50 1 1 10000 2

for (int i = 0; i < vs.size(); i++)
{
vector<pair<int, int>> ap;
for (int j = 2; j < vs[i].size(); j++)
{

int count = 0;
int a = 0;
int b = 0;
while (j < vs[i].size() && count != 2)
{
if (count != 2 && vs[i][j] != ' ')
{
if (count == 0)
{
a = vs[i][j] - '0';
count++;
}
else
{
b = vs[i][j] - '0';
count++;
}
}
j++;
}

ap.push_back(make_pair(a,b));
}
}
*/

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
////С�� �ڹ�����
//using namespace std;
//
//int main()
//{
//	int Q = 0;
//	cin >> Q;
//	while (Q--)
//	{
//		int n = 0;
//		int m = 0;
//		cin >> n >> m;
//		vector<vector<int>> vv(n, vector<int>(m, 0));
//		for (int i = 0; i < n; i++)
//		{
//			vv[i][0] = vv[i][m - 1] = 1;
//		}
//		for (int i = 0; i < m; i++)
//		{
//			vv[0][i] = vv[n - 1][i] = 1;
//		}
//		int X = 0;
//		int Y = 0;
//		int W = 0;
//		int Z = 0;
//		cin >> X >> Y >> W >> Z;
//		X = X - 1;
//		Y = Y - 1;
//		//vv[X][Y] = 2;
//		int tmp = 2;
//		for (int i = 0; i < Z; i++)
//		{
//			if (W == 0) // ���Ϸ�  X - 1 , Y - 1
//			{
//				//X -= 1;
//				//Y -= 1;
//				if (X  - 1 == 0 && Y - 1 == 0)
//					tmp += 2, W = 2;
//				else if (Y - 1 == 0 && X - 1 != 0)
//					tmp++,W = 3,X-=1;
//				else if (X - 1 == 0 && Y - 1 != 0)
//					tmp++, W = 1,Y-=1;
//				else
//				{
//					X -= 1;
//					Y -= 1;
//					continue;
//				}
//					
//
//			}
//			else if (W == 1)  // ���Ϸ� X - 1 Y + 1
//			{
//				//X -= 1;
//				//Y += 1;
//				if (X - 1== 0 && Y + 1 == m - 1)
//					tmp += 2, W = 3;
//				else if (Y + 1== m  && X - 1 != 0)
//					tmp++,X -= 1, W = 0;
//				else if (X  - 1== 0 && Y + 1 != m - 1)
//					tmp++, Y += 1,W = 2;
//				else
//				{
//					X -= 1;
//					Y += 1;
//					continue;
//				}
//					
//
//			}
//			else if (W == 2)// ���·�  X + 1 Y + 1
//			{
//
//				if (X  + 1== n - 1 && Y + 1== m - 1)
//					tmp += 2, W = 0;
//				else if (Y + 1 == m - 1 && X + 1!= n - 1)
//					tmp++, X+= 1, W = 1;
//				else if (X +1 == n - 1 && Y + 1!= m - 1)
//					tmp++, Y += 1,W = 3;
//				else
//				{
//					X += 1;
//					Y += 1;
//					continue;
//				}
//					
//
//			}
//			else if (W == 3) //���·� X + 1 Y - 1
//			{
//
//				if (X + 1== n - 1 && Y - 1== 0)
//					tmp += 2, W = 1;
//				else if (Y - 1 == 0 && X + 1!= n - 1)
//					tmp++,    W = 2;
//				else if (X + 1 == n - 1 && Y - 1 != 0)
//					tmp++, W = 0;
//				else
//				{
//					X += 1;
//					Y -= 1;
//					continue;
//
//				}
//
//			}
//		
//		}
//		cout << tmp << endl;
//	}
//	system("pause");
//}



/*

5
6 5
4 3 0 42
10 6
5 3 1 46
5 5
3 3 1 7
5 5
3 3 1 6
7 7
4 5 2 9
*/


//
//
//#include <map>
//int main()
//{
//	//�ڹ�����
//	int n;
//	cin >> n;
//	vector<map<int, int>> date;
//	for (int i = 0; i<n; i++)
//	{
//		int mi;
//		cin >> mi;
//		map<int, int> TandV;
//		while (mi--)
//		{
//			int t, v;
//			cin >> t >> v;
//			TandV[t] = v;
//		}
//		date.push_back(TandV);
//	}
//	//dp;
//	vector<vector<int>> dp(n, vector<int>(10001, 0));
//	for (int i = 0; i < n; i++)
//	{
//		int v = date[i][0];
//		dp[i][0] = v * 1; //��״̬
//		for (int j = 1; j <= 10000; j++)
//		{
//			v = date[i][j] == 0 ? v : date[i][j];
//			dp[i][j] = dp[i][j - 1] + v;
//		}
//	}
//	int q;
//	cin >> q;
//	while (q--)
//	{
//		int qi;
//		cin >> qi;
//		int maxX = dp[0][qi];
//		int who = 0;
//		for (int i = 1; i < n; i++) //ȡ���ڹ�����λ��
//		{
//			if (maxX < dp[i][qi - 1]) {
//				maxX = dp[i][qi - 1];
//				who = i;
//			}
//		}
//		cout << who + 1 << endl;
//	}
//	return 0;
//}
//

//
////�����������ٶȷֽ�  ���Էֽ�Ϊˮƽ����ֱ�������������������������ͺ��ˡ�
//int ChangeColorTimes(int row, int x, int w, int t)
//{
//	int count = 0;
//	count = t / (row - 3);
//	int rest;
//	if (w == 1 || w == 2)   //������ʵ���ǿ������˶���������ֵ����ķ����Ǽ�С�ķ���д���е�����ˣ����ܿ�������ע��һ��
//		rest = row - 1 - x;
//	else
//	{
//		rest = x - 2;
//	}
//	if (t % (row - 3) >= rest)
//		count++;
//	return count;
//}
//int main() {
//	int q;
//	cin >> q;
//	for (int i = 0; i < q; i++)
//	{
//		int row, col;
//		cin >> row >> col;
//		int x, y, w, t;
//		cin >> x >> y >> w >> t;
//		int count = 0;
//		count += ChangeColorTimes(col, y, w, t);//ˮƽ
//		if (w == 0 || w == 1)
//			count += ChangeColorTimes(row, x, 3, t);//��ֱ
//		else
//		{
//			count += ChangeColorTimes(row, x, 1, t);//��ֱ
//		}
//		cout << count << endl;
//	}
//
//}


#include <unordered_map>
class A
{
public:
	A()
	{
		count++;
	}
	void Print()
	{
		cout << Get() << endl;
		cout << "hello" << endl;
	}
	static int Get()
	{
		return count;
	}
	static int count;

};

int A::count = 0;
int main()
{
	A a;
	a.Print();
	

	// ��һ�����α������������Ͷ���ֵ
	// ʵ�ʱ������������2019����һ������������������������d1������и�ֵ
	
	system("pause");
}