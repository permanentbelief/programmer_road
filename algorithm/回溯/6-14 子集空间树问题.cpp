#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;



/*
5 10
6 3 5 4 6
2 2 6 5 4

*/

void dfs(vector<int>& values, vector<int>& weights, int Sum, int weight, int& max_, int cur, int nn)
{

	max_ = max(Sum, max_);
	for (int i = cur; i < values.size(); i++)
	{
		if (weight + weights[i] < nn )
		{
			Sum += values[i];
			dfs(values, weights, Sum, weight + weights[i], max_, i + 1,nn);
			Sum -= values[i];
		}

	}
}

int main()
{
	int n = 0;
	int weight = 0;
	cin >> n >> weight;

	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}
	vector<int> dp(weight + 1);
	int max_ = 0;
	dfs(values, weights, 0, 0,max_, 0, weight);
	cout << max_ << endl;
	system("pause");
}


//int timeOf(int n, int speed) {
//	return (n / speed) + ((n % speed > 0) ? 1 : 0);
//}
//// ʱ�临�Ӷ� O(N)
//bool canFinish(vector<int>& piles, int speed, int H) {
//	int time = 0;
//	for (int n : piles) {
//		time += timeOf(n, speed);
//	}
//	return time <= H;
//}
//
//int getMax(vector<int>& piles) {
//	int _max = 0;
//	for (int n : piles)
//		_max = max(n, _max);
//	return _max;
//}
//int maxEatingSpeed(vector<int>& piles, int H)
//{
//	int left = 1;
//	int right = getMax(piles);
//	while (left < right)
//	{
//		int  mid = (left + right) / 2;
//		if (canFinish(piles, mid, H))
//		{
//			right = mid;
//		}
//		else
//		{
//			left = mid + 1;
//		}
//	}
//	return left;
//}
//
//
//
//bool canFinish(vector<int> & w, int D, int cap) {
//	int i = 0;
//	for (int day = 0; day < D; day++) {
//		int maxCap = cap;
//		while ((maxCap -= w[i]) >= 0) {
//			i++;
//			if (i == w.size())
//				return true;
//		}
//	}
//	return false;
//}
//// Ѱ�����߽�Ķ��ֲ���
//int shipWithinDays(vector<int>& weights, int D) {
//	// ���ؿ��ܵ���Сֵ
//	int left = getMax(weights);
//	// ���ؿ��ܵ����ֵ + 1
//	int right = getSum(weights) + 1;
//	while (left < right) {
//		int mid = left + (right - left) / 2;
//		if (canFinish(weights, D, mid)) {
//			right = mid;
//		}
//		else {
//			left = mid + 1;
//		}
//	}
//	return left;
//}
// �������Ϊ cap���Ƿ����� D ����������



//#include <map>
//class Node
//{
//public:
//	int _key;
//	int _val;
//	Node* _next;
//	Node* _prev;
//public:
//	Node(int key, int val)
//		:_next(nullptr)
//		, _prev(nullptr)
//	{
//		this->_key = key;
//		this->_val = val;
//	}
//};
//
//class NodeList
//{
//public:
//	Node* _head = nullptr;
//public:
//	void addFirst(Node* x)// ������ͷ�����ӽڵ�x
//	{
//		if (_head == nullptr)
//		{
//			_head = x;
//			_head->_prev = _head;
//			_head->_next = _head;
//		}
//		else // _head����
//		{
//			x->_prev = _head->_prev;
//			x->_next = _head;
//			_head->_prev = x;
//			_head = x;
//		}
//	}
//	void remove(Node* x) // ɾ���ڵ�x  x����һ������
//	{
//		if (_head == nullptr)
//		{
//			return;
//		}
//		x->_prev = x->_next;
//		x->_next->_prev = x->_prev;
//		
//		// ɾ���ڵ�
//		x->_next = nullptr;
//		x->_prev = nullptr;
//		delete(x);
//		x = nullptr;
//	}
//	Node* removeLast() // ɾ�����������һ���ڵ�
//	{
//		if (_head == nullptr)
//			return nullptr;
//		if (_head->_next == _head)
//		{
//			Node* cur = _head;
//			_head = nullptr;
//			return cur;
//		}
//		else
//		{
//			Node* deletenode = _head->_prev;
//			_head->_prev = deletenode->_prev;
//			deletenode->_prev->_next = deletenode->_next;
//			return deletenode;
//		}
//	}
//	int size() //����˫������ĳ���
//	{
//		int count = 0;
//		Node* cur = _head;
//		while (cur != nullptr)
//		{
//			count++;
//			cur = cur->_next;
//		}
//		return count;
//	}
//};
//
//class LRU
//{
//private:
//	map<int, Node*> mymap;
//	NodeList DoubleList;
//	int _capacity;
//public:
//	LRU(int capacity)
//	{
//		_capacity = capacity;
//	}
//	void put(int key, int val)
//	{
//		Node* x = new Node(key, val);
//
//		if (mymap.find(key) != mymap.end())
//		{
//			//�������еľɽڵ��Ƴ�
//			DoubleList.remove(mymap[key]);
//			DoubleList.addFirst(x);
//
//			//����map�е�����
//			mymap[key] = x;
//		}
//		else
//		{
//			if (_capacity == DoubleList.size())
//			{
//				//ɾ�������е����һ������
//				Node* last = DoubleList.removeLast();
//				mymap.erase(last->_key);
//			}
//			//ֱ����ӵ�β��
//			DoubleList.addFirst(x);
//			mymap[key] = x;
//		}
//	}
//	int get(int key)
//	{
//		if (mymap.find(key) == mymap.end()) // keyֵ������
//		{
//			return -1;
//		}
//		int val = mymap[key]->_val;
//		// keyֵ���ڽ�(key��val)�ᵽ��ͷ
//		put(key, val);
//		return val;	
//	}
//};
//
//
//
//
//bool isMatch(string A, string B)
//{
//	int m = A.size();
//	int n = B.size();
//	vector<vector<bool>> f(m + 1, vector<bool>(n + 1));
//
//	for (int i = 0; i <= n; i++)
//	{
//		for (int j = 0; j <= m; j++)
//		{
//			if (j == 0)
//				f[i][j] = i == 0;
//			else // j != 0
//			{
//				//�ǿշ�Ϊ���� * �� ��*
//				if (B[j - 1] != '*')
//				{
//					if (i > 0 && A[i - 1] == B[j - 1] || B[j - 1] == '.')
//					{
//						f[i][j] = f[i - 1][j - 1];
//					}
//				}
//				else
//				{
//					if (j >= 2)
//					{
//						f[i][j] = f[i - 1][j - 2];
//					}
//					if (i >= 1 && j >= 2 && A[i - 1] == B[j - 2]
//						|| B[j-2] == '.')
//					{
//						f[i][j] = f[i - 1][j];
//					}
//				}
//			}
//		}
//
//	}
//	return f[m][n];
//}
//
//int main()
//{
//	NodeList list;
//	Node x1(10, 10);
//	Node x2(1, 1);
//	Node x3(3, 3);
//
//	list.addFirst(&x1);
//	list.addFirst(&x2);
//	list.addFirst(&x3);
//
//	//vector<int> v = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
//	//vector<int> vv = { 0, 1, 0 };
//	//trap(vv);
//
//	system("pause");
//}
