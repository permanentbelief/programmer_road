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
////	// clear() �����տռ�
////	vector <int> v = { 1, 2, 3, 4, 5, 6 };
////	cout << v.size() << endl;
////	cout << v.capacity() << endl;
////	cout << endl;
////	v.clear(); //ֻ���size()�Ĵ�С �����ı�capacity()�Ĵ�С 
////	cout << "clear��պ�" << endl;
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
//	//ע�������it����++����vector�ײ��ʵ���У�vector��erase()Ҳ�᷵��һ�������� 
//	vector<int> ::iterator it = v.begin();
//	while (it != v.end())
//	{
//		it = v.erase(it); // ͬ�� vector.erase()Ҳֻ�ǽ�������գ�size()��0�����ı�capacity()�������տռ�
//	}
//	cout << "ͨ����������eraseѭ��ɾ����" << endl;
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
////ʹ��swap,�������ݣ�������Ԫ��
////vector<int>().swap(v);
////cout << v.size() << endl;
////cout << v.capacity() << endl;
//
////v.swap(vector<int>());
////cout << v.size() << endl;
////cout << v.capacity() << endl;
