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


// 友元函数 友元类
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
//	// 只有在派生类之间转换时才使用dynamic_cast，type-id必须是类指针，类引用或者void*
//
//	//要求：
//	//1. 基类必须又虚函数，	因为dynamic_cast需要运行是进行类型检查，这个信息是存储到虚函数表中的，只有一个类定义了虚函数才有虚函数表，
//	//2. 对于下行转换，dynamic_cast是安全的(当类型不一致时，传来的是空指针)，而static_cast是不安全的(当类型不一致时，传来的是无意义的指针)，
//	int tempA = 2;
//	int tempB = 3;
//	Base base;
//
//	/*1.无编译告警，但是危险操作，譬如说调用drvPtrA->_d会造成不可预知的后果*/
//	Derived *drvPtrA = static_cast<Derived *>(&base);
//	
//	// 造成不可预知的后果 变量周围的栈 被破坏
//	//drvPtrA->_d = 4;
//	//drvPtrA->_e = 5;
//	//cout << drvPtrA->_e << endl;
//	//cout << drvPtrA->_d << endl;
//
//	///*2.输出:tempA为5，tempB为4,踩内存了（机器信息：32位ubuntu，编译器clang++）*/
//	//cout << tempA << endl;
//	//cout << tempB << endl;
//
//	///*3.Base中没有虚函数，无法查看运行时信息，编译不过*/
//	//Derived *drvPtrB = dynamic_cast<Derived *>(base);
//
//	system("pause");
//	return 0;
//}

/*
在基类派生类互相转换时，虽然static_cast是在编译期完成，效率更高，但是不安全，上例中就示范了一个踩内存的例子。
相比之下因为dynamic_cast可以查看运行时信息，上例如果Base含有虚函数，那么drvPtrB就是一个空指针（这可比踩内存什么的好多了），不能操作Derived中_d的数据从而保证安全性，所以应该优先使用dynamic_cast。



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
//	///*1.编译不过*/
//	//BaseB *baseB = static_cast<BaseB*>(&baseA); //static_cast虽然也不是一种绝对安全的转换，但是它在转换时，还是会进行必要的检测（诸如指针越界计算，类型检查）
//	///*2.无任何编译告警，编译通过,正常运行*/
//	//BaseB *baseC = reinterpret_cast<BaseB *>(&baseA);
//	//cout << baseC->_d << endl;
//
//
//	//const_cast
//
//	/*
//	   如果常量本身不是常量，获得的权限是合法的， 如果本身是常量，使用const_cast再写的后果是未定义的。
//	*/
//	// 常量折叠问题 a b地址一样，但是值不一样 未定义行为 
//	//const int a = 1;  // 常量本身是常量
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
//inline void ad(int x, int y)//合并
//{
//	x = find(a[x]);
//	y = find(a[y]);
//	a[x] = y;
//}
//inline bool check(int x, int y)//查找
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
//	sort(f + 1, f + m + 1, cmp);//c党的优越感~
//	for (i = 1; i <= m + 1; i++)//为什么m+1呢？如果运行到m+1会输出0，想想为什么。
//	{
//		if (check(f[i].x, f[i].y)) { printf("%d", f[i].z); break; }//如果两个罪犯已经在同一监狱就输出 ，并退出
//		else
//		{
//			if (!b[f[i].x]) b[f[i].x] = f[i].y;//标记“敌人”
//			else { ad(b[f[i].x], f[i].y); }//将敌人的敌人合并
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