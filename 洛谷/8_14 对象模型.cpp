#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//int add(int, int);
//extern int add(int, int);

//class Base
//{
//public:
//	virtual void fun1()
//	{
//		cout << "Base::fun1()" << endl;
//	}
//	virtual void fun2()
//	{
//		cout << "Base::fun2()" << endl;
//	}
//private:
//	int a;
//};
//
//class Derive :public Base
//{
//public:
//	virtual void fun1()
//	{
//		cout << "Derive::fun1()" << endl;
//	}
//	virtual void fun3()
//	{
//		cout << "Derive::fun3()" << endl;
//	}
//	virtual void fun4()
//	{
//		cout << "Derive::fun4()" << endl;
//	}
//private:
//	int b;
//};
//
//typedef void(*Ff)();//函数指针（指向函数的指针）
//
//void PrintVTable(int* VTable)//打印虚函数表
//{
//	cout << "VTable: " << VTable << endl;
//	for (int i = 0; VTable[i] != 0; ++i)
//	{
//		printf("VTable[i]: 0x%x,->", i, VTable[i]);
//		Ff f = (Ff)VTable[i];
//		f();
//	}
//	cout << endl;
//}
//int main()
//{
//	Base b;
//	Derive d;
//
//	int* vtable1 = (int*)(*(int*)&b);
//	int* vtable2 = (int*)(*(int*)&d);
//	PrintVTable(vtable1);
//	PrintVTable(vtable2);
//
//	system("pause");
//	return 0;
//}



//class A
//{
//public:
//	virtual void fun1()
//	{
//		cout << "A::fun1()" << endl;
//	}
//public:
//	int _a;
//};
//
//class B : public A
//{
//public:
//	virtual void fun1()
//	{
//		cout << "B::fun1()" << endl;
//	}
//	virtual void fun2()
//	{
//		cout << "B::fun2()" << endl;
//	}
//
//public:
//	int _b;
//};
//
//class C : public A
//{
//public:
//	virtual void fun1()
//	{
//		cout << "C::fun1()" << endl;
//	}
//	virtual void fun3()
//	{
//		cout << "C::fun3()" << endl;
//	}
//
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	virtual void fun1()//重写B,C中的虚函数
//	{
//		cout << "D::fun1()" << endl;
//	}
//	 void fun5()//重写B中的虚函数
//	{
//		cout << "D::fun5()" << endl;
//	}
//	virtual void fun4()//D中的虚函数
//	{
//		cout << "D::fun4()" << endl;
//	}
//
//public:
//	int _d;
//};
//
//typedef void(*FUNC)();
//
//void PrintVTable(int* VTable)
//{
//	cout << "VTable: " << VTable << endl;
//	for (int i = 0; VTable[i] != 0; ++i)
//	{
//		printf("VTable[%d]:0x%x,->", i, VTable[i]);
//		FUNC f = (FUNC)VTable[i];
//		f();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d._b = 2;
//	d.C::_a = 3;
//	d._c = 4;
//	d._d = 5;
//	int* vtable = (int*)(*(int*)&d);
//	PrintVTable(vtable);
//	
//
//	
//	vtable = (int*)(*((int*)&d + sizeof(B) / 4));
//	PrintVTable(vtable);
//	
//
//	system("pause");
//	return 0;
//}

//
//class AA
//{
//public:
//	virtual void fun1()
//	{
//		cout << "AA::fun1()" << endl;
//	}
//	virtual void fun2()
//	{
//		cout << "AA::fun2()" << endl;
//	}
//private:
//	int _a;
//};
//
//class BB
//{
//public:
//	virtual void fun1()
//	{
//		cout << "BB::fun1()" << endl;
//	}
//	virtual void fun2()
//	{
//		cout << "BB::fun2()" << endl;
//	}
//private:
//	int _b;
//};
//
//class CC : public AA, public BB
//{
//public:
//	virtual void fun1()
//	{
//		cout << "CC::fun1()" << endl;
//	}
//	//virtual void fun3()
//	//{
//	//	cout << "CC::fun3()" << endl;
//	//}
//
//private:
//	int _c;
//};
//
//typedef void(*FUNC)();
//
//void PrintVTable(int* VTable)
//{
//	cout << "VTable: " << VTable << endl;
//	for (int i = 0; VTable[i] != 0; ++i)
//	{
//		printf("VTable[i]:0x%x,->", i, VTable[i]);
//		FUNC f = (FUNC)VTable[i];
//		f();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	CC c;
//	int* vtable = (int*)(*(int*)&c);
//	PrintVTable(vtable);
//
//	
//	vtable = (int*)(*((int*)&c + sizeof(AA) / 4));
//	//sizeof(AA)=8除4为int*的个数
//	PrintVTable(vtable);
//
//	system("pause");
//	return 0;
//}

class Base1

{

public:

	virtual void func1()

	{

		cout << "Base1::func1" << endl;

	}

	virtual void func2()

	{

		cout << "Base1::func2" << endl;

	}

private:

	int b1;

};

class Base2

{

public:

	virtual void func1()

	{

		cout << "Base2::func1" << endl;

	}

	virtual void func2()

	{

		cout << "Base2::func2" << endl;

	}

private:

	int b2;

};




class Derive : public Base1, public Base2

{

public:

	virtual void func1()

	{

		cout << "Derive::func1" << endl;

	}

	//virtual void func3()

	//{

	//	cout << "Derive::func3" << endl;

	//}
	virtual void func4()
	{
		cout << "caibi" << endl;
	}



private:

	int d1;

};

typedef void(*FUNC) ();

void PrintVTable(int* VTable)

{

	cout << " 虚表地址>" << VTable << endl;

	for (int i = 0; VTable[i] != 0; ++i)

	{

		printf(" 第%d个虚函数地址 :0X%x,->", i, VTable[i]); FUNC f = (FUNC)VTable[i];

		f();

	}

	cout << endl;

}




void Test1()

{

	Derive d1;

	int* VTable = (int*)(*(int*)&d1);

	PrintVTable(VTable);

	// Base2虚函数表在对象Base1后面 VTable = (int *)(*((int*)&d1 + sizeof (Base1)/4));

	// PrintVTable(VTable);

}

class A
{
public:
	int a = 10;
	virtual void func1()
	{

	}
	virtual void func2()
	{

	}
};
class B:public A
{
public:
	virtual void func2()
	{

	}
	virtual void func3()
	{

	}
	int b = 20;
};

class C:  public B
{
public:
	virtual void func2()
	{

	}
	virtual void func3()
	{

	}
	int c = 20;
};

int main()
{
	
	B b;
	cout << (int*)(*(int*)&b) << endl;
	system("pause");
}