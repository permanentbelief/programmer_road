//#define _CRT_SECURE_NO_WARNINGS 1 
//#include <iostream>
//#include <vector>
//using namespace std;
//void DFS(int curIdx, vector<int>&box, vector<int>&used, int n)
//{
//	if (curIdx == n)
//	{
//		for (auto &e : box)
//		{
//			cout << e << " ";
//		}
//		cout << endl;
//		return;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		if (used[i] == 0)
//		{
//			box[curIdx] = i;
//			used[i] = 1;
//			//������
//			//����ÿһ�ſ��õ���
//			DFS(curIdx + 1, box, used, n);
//			//���յ�ǰ���ӵ���
//			used[i] = 0;
//		}
//	}
//	
//}
//int main()
//{
//	int n = 2;
//	vector<int>used(n + 1, 0);
//	vector<int>box(n, 0);
//	DFS(0, box, used, n);
//	system("pause");
//	return 0;
//
//}