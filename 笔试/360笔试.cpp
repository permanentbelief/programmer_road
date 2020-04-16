#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//class B
//{
//public:
//	virtual void f()
//	{
//		cout << "B " << endl;
//	}
//};
//class D : public B
//{
//public:
//	void f()
//	{
//		cout << "D " << endl;
//	}
//};
// 经典第一题，异常+类的继承
//int main()
//{
//	B b;
//	try
//	{
//		//B* bb = new B();
//		//D* rd = dynamic_cast<D*> (bb); // 非法的，dynamic_cast检测出来，就把D* 的rd置为nullptr
//		//rd->f(); 
//		D& rd = dynamic_cast<D&>(b); // 检测出来是非法的
//		rd.f();
//
//		//D d;
//		//D* ptr = new D();
//		//B& pb = dynamic_cast<B&>(d); // B类的引用指向的是B类的
//		//pb.f();
//		//B* ppb = dynamic_cast<B*>(ptr);
//		//ppb->f();
//	}
//	catch (bad_cast&)
//	{
//		B b;
//		b.f();
//	}
//	system("pause");
//}

//class A
//{
//private:
//	int i;
//public:
//	A(int n = 0)
//		:i(n)
//	{};
//	friend void f(A& p)
//	{
//		cout << p.i << "_";
//	}
//	friend void f(A*p)
//	{
//		cout << p->i << "#";
//	}
//};
//int main()
//{
//	A o1(5);
//	A o2;
//	f(o1);
//	f(&o2);
//	cout << endl;
//	system("pause");
//}

//class A
//{
//	int a;
//	int q;
//public:
//	A(int x, int y)
//		:a(x)
//		, q(y)
//	{}
//	void operator<<(ostream& out)
//	{
//		cout << a << "/" << q << endl;//都可以输出 a/q
//		out << a << "/" << q << endl; //借助标准输出 可以输出 a/q 
//	}
//};
//int main()
//{
//	A o1(1, 2);
//	o1.operator<<(cout);// 传参传cout
//	system("pause");
//}


//class A
//{
//private:
//	static int n;
//	int val;
//public:
//	A()
//	{
//		n++;
//	}
//	void show()
//	{
//		cout << n << endl;
//	}
//};
//int A::n = 0;
//int main()
//{
//	A a;
//	a.show();
//	cout << A::n << endl;
//	system("pause");
//
//}

template <class T1, class T2>
class R
{
	T1 val1;
	T2 val2;
public:
	R(T1 _val1, T2 _val2)
		:val1(_val1)
		, val2(_val2)
	{}
	void show() const //表示类的成员
	{
		val1 = 10;
		val2 = 100;
		cout << val1 << " " << e
	}
};

//template<class T1, class T2>
//void R<T1,T2>::show() const
//{
//	cout << val1 <<" " <<  val2 << endl;
//}
int main()
{
	R<int, int> r(1, 2);
	r.show();
	system("pause");
}
//bool Is_Valid (TreeNode* root)
//{
//	if(root == nullptr)
//		return false;
//	if (root->left == nullptr && root->right == nullptr)
//	{
//		return root->boolen;// val是bool类型的 true or false
//	}
//	bool root_r = Is_Valid(root->right);
//	bool root_l = Is_Valie(root->left);
//
//	return root_r&&root_l;
//}
/*
4 3
1 3 2 4
*/
//int main()
//{
//	int m = 0;
//	int n = 0;
//	while (cin >> n >> m)
//	{
//		vector<int> v(n);
//		for (int j = 0; j < n; j++)
//		{
//			cin >> v[j];
//		}
//		int count = 0;
//		int target = 0;
//		int i = 0;
//
//		while (1)
//		{
//			int count1 = 0;
//			bool flag1 = false;
//			if (v[i] > v[i + 1])
//			{
//				target = v[i];
//				v.push_back(v[i + 1]);
//				v[i + 1] = v[i];
//				i++;
//				count1 += 1;
//				count++;
//				if (count1 == m)
//				{
//					flag1 = true;
//					break;
//				}
//				while (v[i] == target && target > v[i + 1])
//				{
//					count1 += 1;
//					v.push_back(v[i + 1]);
//					v[i + 1] = v[i];
//					count++;
//					i++;
//					if (count1 == m)
//					{
//						flag1 = true;
//						break;
//					}
//				}
//				if (flag1)
//				{
//					break;
//				}
//			}
//				else// v[i] < v[i+1]
//				{
//					target = v[i + 1];
//					v.push_back(v[i]);
//					i++;
//					count1 += 1;
//					count++;
//					if (count1 == m)
//					{
//						flag1 = true;
//						break;
//					}
//					while (v[i] == target && target > v[i + 1])
//					{
//						count1 += 1;
//						v.push_back(v[i + 1]);
//						v[i + 1] = target;
//						count++;
//						i++;
//						if (count1 == m)
//						{
//							flag1 = true;
//							break;
//						}
//					}
//					if (flag1)
//					{
//						break;
//					}
//				}
//
//		}
//		cout << count << endl;
//	}
//}
