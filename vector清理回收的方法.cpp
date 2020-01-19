//#define _CRT_SECURE_NO_WARNINGS 1 
//
//
//
//#include <iostream>
//
//#include <vector>
//using namespace std;
//
////int main()
////{
////	// clear() 不回收空间
////	vector <int> v = { 1, 2, 3, 4, 5, 6 };
////	cout << v.size() << endl;
////	cout << v.capacity() << endl;
////	cout << endl;
////	v.clear(); //只清除size()的大小 ，不改变capacity()的大小 
////	cout << "clear清空后" << endl;
////	cout << v.size() << endl;
////	cout << v.capacity() << endl;
////	system("pause");
////}
//
//
//
//
//int main()
//{
//	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;
//	cout << endl;
//
//	//注意迭代器it不能++，在vector底层的实现中，vector的erase()也会返回一个迭代器 
//	vector<int> ::iterator it = v.begin();
//	while (it != v.end())
//	{
//		it = v.erase(it); // 同上 vector.erase()也只是将数据清空，size()清0，不改变capacity()，不回收空间
//	}
//	cout << "通过迭代器和erase循环删除后" << endl;
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;
//
//
//
//
//	system("pause");
//	for (auto&e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
////使用swap,清理数据，并回收元素
////vector<int>().swap(v);
////cout << v.size() << endl;
////cout << v.capacity() << endl;
//
////v.swap(vector<int>());
////cout << v.size() << endl;
////cout << v.capacity() << endl;
