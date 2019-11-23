//#define _CRT_SECURE_NO_WARNINGS 1 
//#define _CRT_SECURE_NO_WARNINGS 1 


//#include <iostream>
//using namespace std;
//day15 9
//class A
//{
//public:
//	void f()
//	{
//		printf("A\n");
//	}
//	~A()
//	{
//
//	}
//};
//class B : public A
//{
//public:
//	virtual void f()
//	{
//		printf("B\n");
//	}
//};
//int main()
//{
//	A* a = new B;
//	a->f();
//	//delete a;
//	system("pause");
//	//return 0;
//}

//day15 10
//class A
//{
//public:
//	A()
//	{
//		printf("A ");
//	}
//	~A()
//	{
//		printf("deA ");
//	}
//};
//class B
//{
//public:
//	B()
//	{
//		printf("B ");
//	}
//	~B()
//	{
//		printf("deB ");
//	}
//};
//class C : public A, public B
//{
//public:
//	C()
//	{
//		printf("C ");
//	}
//	~C()
//	{
//		printf("deC ");
//	}
//};
//int main()
//{
//	A* a = new C();
//	delete a;
//	system("pause");
//}

//day 16 T8
//class CSomething
//{
//private:
//	static int a;
//	int _val;
//public:
//	CSomething(int val)
//	{
//		printf("%d ", ++a);
//		_val = val;
//	}
//	 CSomething(const CSomething& c)
//	{
//		 _val = c._val;
//		 
//	}
//	CSomething()
//	{
//		printf("%d ", ++a);
//	}
//
//};
//int CSomething::a = 0;
//int main()
//{
//	//CSomething z(); 为什么这里不可以调用构造函数
//	CSomething b(2);  //调用一次构造 
//	CSomething c(10); // 调用一次构造
//	CSomething d[3];  // 调用三次构造
//	CSomething e = b;  //调用拷贝构造函数
//	CSomething *p = new CSomething(4);  //调用构造
//	CSomething &ra = b;  //不调用拷贝构造函数
//	CSomething *pA  = d;
//	system("pause");
//}

//class myClass
//{
//public:
//	myClass()
//	{
//
//	}
//	void foo()
//	{
//		delete this;
//	}
//
//};
//
////void myClass::foo()
////{
////	delete this;
////}
//
//int main()
//{
//	myClass A;
//	myClass *pa = &A;
//	myClass *a = new myClass();
//	a->foo();
//	system("pause");
//}

//day 17
//int main()
//{
	/*char *ptr;
	char myString[] = "abcdefg";
	ptr = myString;
	ptr += 5;
	printf("%s", ptr);
	system("pause");*/


	/*char *p = "abc";
	char *q = "abc123";
	while (*p = *q);
	printf("%c %c", *p, *q);
	system("pause");*/
//}
//
//template <class T>
//struct sum
//{
//	static void foo(T op1, T op2)
//	{
//		cout << op1 << op2;
//	}
//};
//int main()
//{
//	sum<int>::foo(1, 3);
//	system("pause");
//}


//class A
//{
//public:
//	A()
//	{
//		p();
//	}
//	virtual void p()
//	{
//		printf("A");
//	}
//	virtual ~A()
//	{
//		p();
//	}
//};
//class B : public A
//{
//public:
//	B()
//	{
//		p();
//	}
//	void p()
//	{
//		printf("B");
//	}
//	~B()
//	{
//		p();
//	}
//};
//int main()
//{
//	A* a = new B();
//	delete a;
//	system("pause"); //ABBA
//}
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int  n = 0;
//	scanf("%d", &n);
//	//老版本 错误的
	/*for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <n - i; j++)
		{
			printf("%c", ' ');
		}
		for (int j = 0; j <= n + i; j++)
		{
			printf("%c ", '*');
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			printf("%c", ' ');
		}
		for (int j = i + 1; j < 2*n- i ; j++)
		{
			printf("%c ", '*');
		}
		printf("\n");
	}*/
	/*for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			printf("%c ", ' ');
		}
		for (int j = n - i; j < n+1 ; j++)
		{
			printf("%c ", '*');
		}
		printf("\n");
	}*/
//	system("pause");
//}
//

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n - i; j++)printf("%c ", ' ');
//		for (int j = 1; j <= 2 * i - 1; j++) printf("%c ", '*');
//		cout << endl;
//	}
//	for (int i = n - 1; i >= 1; i--)
//	{
//		for (int j = 1; j <= n - i; j++) printf("%c ", ' ');
//		for (int j = 1; j <= 2 * i - 1; j++)printf("%c ", '*');
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}
