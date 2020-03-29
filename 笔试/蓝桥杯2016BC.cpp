#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>




using namespace std;

#include <set>

void DFS(vector<string>& ss, string& a, string tmp, int n, int cur)
{
	if (tmp.size() == n)
	{
		ss.push_back(tmp);
		return;
	}
	for (int i = cur; i < a.size(); i++)
	{
		tmp += a[i];
		DFS(ss, a, tmp, n, i + 1);
		tmp.pop_back();
	}
}



//int main()
//{
//	int pre = 1;
//	int plus = 2;
//	long sum = 1;
//	for (int i = 2; i <= 100; i++)
//	{
//		pre = pre + plus;
//		sum += pre;
//		plus++;
//	}
//	cout << sum << endl;
//	system("pause");
//}


//#include <stdio.h>
//#define N 6
//#define M 5
//#define BUF 1024
//
//int ans = 0;
//void f(int a[], int k, int m, char b[])
//{
//
//
//	if (k == N) // N = 
//	{
//		b[M] = 0;
//		if (m == 0)
//		{
//			printf("%s\n", b);
//
//		}
//		return;
//	}
//	for (int i = 0; i <= a[k]; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			b[M - m + j] = k + 'A';
//		}
//		f(a, k + 1, m - i, b);
//	}
//}
//int main()
//{
//	int  a[N] = { 4, 2, 2, 1, 1, 3 };
//	char b[BUF] = {};
//	f(a, 0, M, b);
//	printf("%d\n", ans);
//	system("pause");
//}




////���ظ�Ԫ�ص�ȫ����
//int a[4] = { 1, 2, 3, 4 };
//
//void f(int k)
//{
//	if (k == 4)
//	{
//		for (auto e : a)
//		{
//			cout << e << " ";
//		}
//		cout << endl;
//		return;
//	}
//
//	for (int i = k; i < 4; i++)
//	{
//		swap(a[i], a[k]);
//		f(k + 1);
//		swap(a[i],a[k]);
//	}
//}
//int main()
//{
//	//f(0);
//	vector<int> v = { 2, 4, 3 };
//
//	do{
//		
//		/*for (auto e : a)
//		{
//			cout << e << " ";
//		}
//		cout << endl;*/
//		for (auto&e : v)
//		{
//			cout << e << " ";
//		}
//		cout << endl;
//
//	} while (next_permutation(v.begin(),v.begin()+3)); //�����������������֮ǰa�����������
//
//	system("pause");
//}



// ȫ���� �� check()

//bool check(string str)
//{
//	vector<vector<int>> vp(4);
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == 'A')
//			vp[0].push_back(i);
//		else if (str[i] == '2')
//			vp[1].push_back(i);
//		else if (str[i] == '3')
//			vp[2].push_back(i);
//		else
//			vp[3].push_back(i);
//	}
//	if (vp[0][1] - vp[0][0] ==2 && vp[1][1] - vp[1][0] ==3
//		&& vp[2][1] - vp[2][0] ==4 && vp[3][1] - vp[3][0] == 5)
//		return true;
//	return false;
//}
//
//bool check1(const string&s)
//{
//	if (s.rfind('A') - s.find('A') == 2
//		&& s.rfind('2') - s.find('2') == 3
//		&& s.rfind('3') - s.find('3') == 4
//		&& s.rfind('4') - s.find('4') == 5)
//		return true;
//	return false;
//}
//int main()
//{
//	string tmp;
//	string str = "A23";
//	do{
//		//if (check(str))  //2342A3A4  2342A3A4
//		cout << str << endl;
//      
//	} while (next_permutation(str.begin(), str.end()));
//	cout << tmp << endl;
//	system("pause");
//}


// ������ʽ

//����һ��
void test1()
{
	string s = "aaabbbbccccc";
	vector<string> vs;
	int ans = 0;
	do
	{
		//�ų��ظ�������v1�е�Ԫ�ؽ��м�飬�������s����ת��ת��������
		int i = 0;
		for (; i < vs.size(); i++)
		{
			if (vs[i].find(s) != string::npos)
			{
				break;
			}
		}
		//s�����õ����
		if (i != vs.size())
		{
			continue;
		}
		string s2 = s + s;
		vs.push_back(s2);
		reverse(s2.begin(), s2.end());
		vs.push_back(s2);

		ans++;
	} while (next_permutation(s.begin(), s.end()));
	cout << ans << endl;
}


//int main()
//{
//
//	//test1();
//	//1170
//	system("pause");
//}

/*int a[5][6];
int vis[10]*/;
//��������


//void Init() // a[5][6]
//{
//	// ��ʼ��a[5][6] Ϊ����
//}
//bool check(int i, int j)
//{
//	for (int x = i - 1; x <= i + 1; x++)
//	{
//		for (int y = j - 1; y <= j + 1; ++y)
//		{
//			if (abs(a[x][y] - a[i][j]) == 1)
//			{
//				return false;
//			}
//		}
//	}
//	return true;
//}
//int ans = 0;
//void f(int x, int y)
//{
//	if (x == 3 && y == 4)
//	{
//		ans++;
//		return;
//	}
//	//��0��9ץȡһ��
//	for (int i = 0; i < 10; i++)
//	{
//		if (vis[i] == 0)
//		{
//			a[x][y] = i;
//			if (!check(x, y))
//			{
//				a[x][y] = -10;
//				continue;
//			}
//			vis[i] = 1; //����ѷ��ʸ���
//			if (y == 4)
//			{
//				f(x + 1, 1);//����
//			}
//			else
//			{
//				f(x, y + 1);//���Ҳ������
//			}
//			{
//				//����
//				vis[i] = 0; 
//				a[x][y] = -10;
//			}
//		}
//	}
//}


//����Ʊ

//int a[4] = { 1,1,3,4};
//bool vis[4] = { false };
//int cnt = 0;
//void f(int k, int path[3])
//{
//	if (k == 3)
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			cout << path[i] ;
//		}
//		cnt++;
//		cout << endl;
//		
//	}
//	for (int i = 0; i < 4; i++)
//	{ 
//		if (i > 0 && a[i] == a[i - 1] && !vis[i -1]) //��һ��Ԫ�ػ�û��ʹ��
//			continue;
//
//		if (!vis[i])
//		{
//			vis[i] = true;//���Ϊ�ѷ���
//			path[k] = a[i];
//			f(k + 1, path);
//			vis[i] = false; //����
//		}
//	}
//}
//int main()
//{
//	//int v[] = { 1, 2, 3, 4 };
//	int path[3];
//	f(0, path);
//	cout << cnt << "��" << endl;
//	system("pause");
//
//}


/*
5
1 3 4 2 5
*/
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		vector<int> v(n + 1);
//		for (int i = 1; i <= n; i++)
//		{
//			cin >> v[i];
//		}
//		int ans = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			if (i != v[i])
//			{
//				int tmp = 0;
//				while (tmp <= n && tmp != v[i])
//				{
//					tmp++;
//				}
//				swap(v[tmp], v[i]);
//				ans++;
//			}
//		}
//		cout << ans << endl;
//	}
//}



//// ʵ��String�����
//class String
//{
//public:
//	String(char* str = "")
//	{
//		if (nullptr == str)
//			str = "";
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//	// ��������
//	String(const String& s)
//		: _str(new char[strlen(s._str) + 1])
//	{
//		cout << "String(const String& s)" << endl;
//		strcpy(_str, s._str);
//	}
//
//	// �ƶ�����->Ϊʲô������ֱ�ӽ����ƶ�����Ϊs����ֵ�еĽ���ֵ��
//	// �����㶼Ҫ���ˣ��Ҳ�Ҫ�����ˣ�ֱ�ӽ�����Դ�ƶ����ҿɺá�
//	String(String&& s)
//		:_str(nullptr)
//	{
//		cout << "String(String&& s)" << endl;
//		swap(_str, s._str);
//	}
//
//	// s1 = tmp
//	// �ƶ�����
//	String& operator = (String&& s)
//	{
//		swap(_str, s._str);
//		return *this;
//	}
//
//	String& operator=(const String& s)
//	{
//		cout << "String& operator=(const String& s)" << endl;
//
//		if (this != &s)
//		{
//			char* pTemp = new char[strlen(s._str) + 1];
//			strcpy(pTemp, s._str);
//			delete[] _str;
//			_str = pTemp;
//		}
//		return *this;
//	}
//
//	// s1 + s2
//	// s1.operator+(&s1, s2)
//	String operator+(const String& s) const
//	{
//		String tmp;
//		tmp._str = new char[strlen(_str) + strlen(s._str) + 1];
//		strcpy(tmp._str, _str);
//		strcat(tmp._str, s._str);
//		return tmp;
//	}
//
//	~String()
//	{
//		if (_str)
//			delete[] _str;
//	}
//
//	char* c_str()
//	{
//		return _str;
//	}
//private:
//	char* _str;
//};

// �ƶ�������ƶ���ֵ

//int main()
//{
//	string s1("hello");
//	string s2("world");
//	string ret = s1 + s2;
//	cout << ret.c_str() << endl;
//
//	string s3(s1);       // ��������
//	string s5(move(s1)); // �ƶ�����
//	cout << s1 << endl;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	vector<String> v;
//	//String s1("��ֵ");
//	//v.push_back(s1);               // ��������-���-���۴�
//	//v.push_back("��ֵ-����ֵ");    // �ƶ�����-�ƶ���Դ-����С
//	v.push_back(move(s1));         // �ƶ�����-����Ḷ�����ۣ����������ã�s1���ƿ���
//
//
//	String s2("��ֵ");  // �˽�һ�£�һ����������ǻ���ʹ������push_pack�Ϳ���
//	v.emplace_back(s2);
//	v.emplace_back(String("��ֵ-����ֵ"));
//
//	return 0;
//}

//ʵ��String�����
class String
{
public:
	String(char* str = "")
	{
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	//��������
	String(const String& s)
		:_str(new char[strlen(s._str) +1])
	{
		cout << "String(const String& s)" << endl;
		strcpy(_str, s._str);
	}
	//�ƶ�����
	String(String&& s)
		:_str(nullptr)
	{
		cout << "String(String&& s)" << endl;
		swap(_str, s._str);
	}
	
	//�ƶ���ֵ
	String& operator = (String&& s)
	{
		swap(_str, s._str);
		return *this;
	}

	
	String& operator=(const String& s)
	{
		cout << "String& operator=(const String& s)" << endl;

		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}

	String operator+(const String& s) const
	{
		String tmp;
		tmp._str = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(tmp._str, _str);
		strcat(tmp._str, s._str);
		return tmp;
	}

	~String()
	{
		if (_str)
			delete[] _str;
	}
	
	char* c_str()
	{
		return _str;
	}
private:
	char* _str;
};

//�ƶ�������ƶ���ֵ



string& out(string &str1, string& str2) //�����������ã���Ϊ��Ĳ�����������������еģ�����ֵ�����ǿ�������Ϊ��������������������ջ֡�еġ�
{
	return str1 < str2 ? str1 : str2;
}

const string& out1(const  string& s)
{
	string tmp = s;
	return tmp;
}
int main()
{
	//String s1("change");
	//String s2("world");
	//String ret = s1 + s2;
	//cout << ret.c_str() << endl;

	//String s3(s1); //��������

	//String s4(move(s1)); //�ƶ�����


	////cout << s1.c_str() << endl;

	string str1 = "anc";
	string str2 = "abc";
	cout << out(str1,str2) << endl;

	cout << out1(str2) << endl;
	system("pause");
}
