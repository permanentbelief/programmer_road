#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int N = 1e4;
int f[N];
int d[N];
void init(){
	for (int i = 1; i < N; i++) f[i] = i;
}
int find(int x){
	if (x == f[x])
		return x;
	return
		f[x] = find(f[x]);
}
void add(int a, int b){
	int u = find(a);
	int v = find(b);
	f[u] = v;
}


//class Solution {
//public:
//	int firstMissingPositive(vector<int>& nums) {
//
//		for (int i = 0; i < nums.size(); i++){
//			while (nums[i]  > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]){
//				swap(nums[i], nums[nums[i] - 1]);
//			}
//		}
//		for (int i = 0; i < nums.size(); i++){
//			cout << nums[i] << " ";
//		}
//		cout << endl;
//
//		for (int i = 0; i < nums.size(); i++){
//			if (nums[i] != i){
//				// i + ; 
//				return i + 1;
//			}
//		}
//		return nums.size();
//	}
//};


// ��Ԫ���� ��Ԫ��
//
//class Base
//{
//public:
//	Base(int c = 2) :_c(c){}
//public:
//	int _c;
//};
//class Derived :public Base
//{
//public:
//	int _d;
//	int _e;
//};
//int main(void)
//{
//	// dynamic_cast
//	// ֻ����������֮��ת��ʱ��ʹ��dynamic_cast��type-id��������ָ�룬�����û���void*
//
//	//Ҫ��
//	//1. ����������麯����	��Ϊdynamic_cast��Ҫ�����ǽ������ͼ�飬�����Ϣ�Ǵ洢���麯�����еģ�ֻ��һ���ඨ�����麯�������麯����
//	//2. ��������ת����dynamic_cast�ǰ�ȫ��(�����Ͳ�һ��ʱ���������ǿ�ָ��)����static_cast�ǲ���ȫ��(�����Ͳ�һ��ʱ�����������������ָ��)��
//	int tempA = 2;
//	int tempB = 3;
//	Base base;
//
//	/*1.�ޱ���澯������Σ�ղ�����Ʃ��˵����drvPtrA->_d����ɲ���Ԥ֪�ĺ��*/
//	Derived *drvPtrA = static_cast<Derived *>(&base);
//	
//	// ��ɲ���Ԥ֪�ĺ�� ������Χ��ջ ���ƻ�
//	//drvPtrA->_d = 4;
//	//drvPtrA->_e = 5;
//	//cout << drvPtrA->_e << endl;
//	//cout << drvPtrA->_d << endl;
//
//	///*2.���:tempAΪ5��tempBΪ4,���ڴ��ˣ�������Ϣ��32λubuntu��������clang++��*/
//	//cout << tempA << endl;
//	//cout << tempB << endl;
//
//	///*3.Base��û���麯�����޷��鿴����ʱ��Ϣ�����벻��*/
//	//Derived *drvPtrB = dynamic_cast<Derived *>(base);
//
//	system("pause");
//	return 0;
//}

/*
�ڻ��������໥��ת��ʱ����Ȼstatic_cast���ڱ�������ɣ�Ч�ʸ��ߣ����ǲ���ȫ�������о�ʾ����һ�����ڴ�����ӡ�
���֮����Ϊdynamic_cast���Բ鿴����ʱ��Ϣ���������Base�����麯������ôdrvPtrB����һ����ָ�루��ɱȲ��ڴ�ʲô�ĺö��ˣ������ܲ���Derived��_d�����ݴӶ���֤��ȫ�ԣ�����Ӧ������ʹ��dynamic_cast��



*/


class BaseA
{
public:
	BaseA(int c = 2) :_c(c){}
	int _c;
};
class BaseB 
{
public:
	BaseB(int d = 3) :_d(d){}
	int _d;
};

void func(const int& a){
	int &b = const_cast<int&>(a);
	b++;
	return;
}
//int main(void)
//{
//	//BaseA baseA;
//	///*1.���벻��*/
//	//BaseB *baseB = static_cast<BaseB*>(&baseA); //static_cast��ȻҲ����һ�־��԰�ȫ��ת������������ת��ʱ�����ǻ���б�Ҫ�ļ�⣨����ָ��Խ����㣬���ͼ�飩
//	///*2.���κα���澯������ͨ��,��������*/
//	//BaseB *baseC = reinterpret_cast<BaseB *>(&baseA);
//	//cout << baseC->_d << endl;
//
//
//	//const_cast
//
//	/*
//	   ������������ǳ�������õ�Ȩ���ǺϷ��ģ� ��������ǳ�����ʹ��const_cast��д�ĺ����δ����ġ�
//	*/
//	// �����۵����� a b��ַһ��������ֵ��һ�� δ������Ϊ 
//	//const int a = 1;  // ���������ǳ���
//	//int &b = const_cast<int&>(a);
//	//b = 2;
//	//cout << a << endl;
//	//cout << b << endl;
//	//cout << a << endl;
//	//cout << &a << endl;
//	//cout << &b << endl;
//	system("pause");
//	return 0;
//}


//struct data{
//	int x, y, z;
//};
//data f[100005];
//
//int n, m, a[20005], b[20005];
//int i;
//bool cmp(data a, data b){
//	return a.z > b.z;
//}
//
//inline int find(int x)
//{
//	if (a[x] == x) return x;
//	a[x] = find(a[x]);
//	return a[x];
//}
//inline void ad(int x, int y)//�ϲ�
//{
//	x = find(a[x]);
//	y = find(a[y]);
//	a[x] = y;
//}
//inline bool check(int x, int y)//����
//{
//	x = find(x);
//	y = find(y);
//	if (x == y) return true;
//	return false;
//}
//
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for (i = 1; i <= n; i++) a[i] = i;
//	for (i = 1; i <= m; i++)
//		scanf("%d%d%d", &f[i].x, &f[i].y, &f[i].z);
//	sort(f + 1, f + m + 1, cmp);//c������Խ��~
//	for (i = 1; i <= m + 1; i++)//Ϊʲôm+1�أ�������е�m+1�����0������Ϊʲô��
//	{
//		if (check(f[i].x, f[i].y)) { printf("%d", f[i].z); break; }//��������ﷸ�Ѿ���ͬһ��������� �����˳�
//		else
//		{
//			if (!b[f[i].x]) b[f[i].x] = f[i].y;//��ǡ����ˡ�
//			else { ad(b[f[i].x], f[i].y); }//�����˵ĵ��˺ϲ�
//			if (!b[f[i].y]) b[f[i].y] = f[i].x;
//			else { ad(b[f[i].y], f[i].x); }
//		}
//	}
//	return 0;
//}



//class Singleton{
//public:
//	static Singleton& Get(){
//		return _sInt;
//	}
//private:
//	Singleton(){
//
//	}
//	Singleton(const Singleton&) = delete;
//	static Singleton _sInt;
//};
//
//Singleton Singleton::_sInt;

//class Singleton{
//public:
//	static Singleton& Get(){
//
//	}
//}
//int main(){
//
//}

struct p{
	int a;
	int b;
};
class P{
public:
	P(int xx = 0) { x = xx; }
	P(const P& p){ x = p.x; }
	int Getx(){
		return x;
	}
	void show2() { cout << x << endl; }
	static void show3(P& q) { cout << q.x << endl; }


private:
	void show1() { cout << x << endl; }
	int x;
};


//template <class T>
//void f1(T t){
//	cout << t << endl;
//}
//template <class T>
//void f1(T* t){
//	cout << t << endl;
//}


//int main(){

	//int B = 10;
	//f1(B);
	//f1(&B);

	//struct p p1[] = {1,92,3,94,5,96};
	//struct p *ptr = p1;
	//int x = sizeof(p1) / 5;
	//if (x == 3){
	//	cout << "yes" << endl;
	//}

	//P A(5);
	////A.show1();
	//A.show2();
	//A.show3(A);

	//P::show2();
	//P::show3(A);

	//int a[10];
	//memset(a, 0, sizeof(a));
	//int i = 0;
	////int main(){
	//	int s = 0;
	//	while (cin >> a[i++]);
	//	for (int j = 0; j < i; j++){
	//		s += a[j];
	//	}
	//	cout << s * pow(2, i - 2) << endl;
	////}
	//	system("pause");
//}




#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int k, a[1000005];



struct Name{
	string c, s;
	int id;
}name[50005];
inline bool cmp(Name x, Name y){
	return x.c>y.c;
}
inline void work();

int main(){
	//in;out;

	string s = "acasddadadadadadadada";
	//cout << sizeof(s) << endl;
	//system("pause");
	work();
	return 0;
}

inline void work(){
	scanf("%d %d", &n, &m);
	string c1;
	

	for (int i = 1; i <= n; i++){
		cin >> c1;
		int l = c1.size();
		name[i].c = c1;
		for (int j = 0; j<l; j++){
			if (c1[j] <= 'Z'&&c1[j] >= 'A')c1[j] = c1[j] - 'A' + 'a';
			else c1[j] = c1[j];
		}
		
		name[i].s = c1;
		name[i].id = i;
	}
	sort(name + 1, name + 1 + n, cmp);
	for (int i = 1, x, y; i <= m; i++){
		scanf("%d %d", &x, &y);
		int j = 1;
		while (1){
			if (name[j].id >= x&&name[j].id <= y) break;
			j++;
		}
		cout << name[j].c << endl;
	}
	system("pause");
}

/*
5 5
aBsi
HAnsbug
Lzn
Kkk
YYy
1 5
1 1
1 2
2 3
4 4


*/
//int main(){
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];	
//	sort(a + 1, a + n + 1);
//
//	for (int i = 1; i <= m; i++){
//		int x = 0;
//		cin >> x;
//		int index = lower_bound(a + 1, a + 1 + n, x) - a;
//		if (a[index] == x){
//			cout << index << " ";
//		}
//		else{
//			cout << -1 << " ";
//		}
//	}
//
//	system("pause");
//	return 0;
//}