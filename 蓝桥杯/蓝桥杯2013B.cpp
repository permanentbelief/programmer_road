#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;



//void f (vector<int>& v, int n, int k)
//{
//	if (n == 5)
//	{
//		for (int i = 0; i < 5; i++)
//		{
//			cout << v[i] << endl;
//		}
//		return;
//	}
//	for (int i = 0; i < v.size(); i++)
//	{
//		swap(v[i], v[k]);
//		f(v, i + 1, k);
//		swap(v[i], v[k]);
//	}
//}



// ������������
//void Sort(vector<int>& v)
//{
//	int left = -1;
//	int end = v.size() - 1;
//	int i = 0;
//	while (i <= end)
//	{
//		if (v[i] < 0)
//		{
//			swap(v[++left], v[i]);
//
//		}
//
//		else if (v[i] > 0)
//		{
//			swap(v[end--], v[i]);
//			//continue;
//		}
//		else
//		{
//			i++;
//		}
//		
//	}
//}

//#include <sstream>
//#include <string>
//
//int main()
//{
//	int n = 0;
//	int ans = 0;
//	cin >> n;
//	string s = "123456789";
//	do
//	{
//		for (int i = 1; i <= 7; i++)
//		{
//			string a = s.substr(0, i);
//			int inta = atoi(a.c_str());
//			if (inta >= n)
//				continue;
//			for (int j = 1; j <= 9 - i - 1; ++j)
//			{
//				string b = s.substr(i, j);
//				string c = s.substr(i + j);
//				int intb = atoi(b.c_str());
//				int intc = atoi(c.c_str());
//				if ()
//				{
//					ans++;
//				}
//			}
//		}
//	} while (next_permutation(s.begin(), s.end()));
//}


//string add(string a, string b)
//{
//	b = b.substr(b.find_first_not_of('0'));
//	a = a.substr(a.find_first_not_of('0'));
//	long long lenA = a.length();
//	long long lenB = b.length();
//	long long len = max(lenA, lenB) + 1;
//
//	//��ת���ӵ�λ�����
//	reverse(a.begin(), a.end());
//	reverse(b.begin(), b.end());
//
//	string ans(len, '0');  //��ʼ����Ϊlen����ȫ���ַ�Ϊ'0��
//	
//	// ��a������ans��
//	for (int i = 0; i < lenA; i++)
//	{
//		ans[i] = a[i];
//	}
//	int tmp = 0; // tmp����һλ��Ӻ�Ľ�λ
//	for (int i = 0; i < len; i++)
//	{
//		if (i < b.size())
//		{
//			tmp += (ans[i] - '0') + (b[i] - '0'); 
//		}
//		else
//		{
//			tmp += (ans[i] - '0');
//		}
//		ans[i] = tmp % 10 + '0';
//		tmp /= 10; //���Ƿ��н�λ
//	}
//
//	reverse(ans.begin(), ans.end());
//	return ans.substr(ans.find_first_not_of('0'));
//}
//
//
//#include <sstream>
//void i2s(int& num, string& str)
//{
//	stringstream ss;
//	ss << num;
//	ss >> str;
//}
//
//int cmp(string& a, string& b)
//{
//	unsigned long ia = a.find_first_not_of('0');
//	if (ia == string::npos)
//	{
//		a = '0';
//	}
//	else
//	{
//		a.substr(ia);
//	}
//
//	unsigned long ib = b.find_first_not_of('0');
//	if (ib == string::npos)
//	{
//		b = '0';
//	}
//	else
//	{
//		b.substr(ib);
//	}
//
//	if (a.size() > b.size())
//		return 1;
//	else if (a.size() < b.size())
//		return -1;
//	else   //�������
//	{
//		if (a < b)
//			return -1;
//		if (a > b)
//			return 1;
//		else
//			return 0;
//	}
//}
//
//
//
//// �˴� aһ������b
//string substact(string a, string b)
//{
//	//1.��ת
//	reverse(a.begin(), a.end());
//	reverse(b.begin(), b.end());
//
//	//2.��λ������
//	for (int i = 0; i < b.size(); i++)
//	{
//		if (a[i] >= b[i])
//		{
//			a[i] = a[i] - b[i] + '0';
//		}
//		else //��λ
//		{
//			int k = 1;
//			while (a[i + k] == '0')  //��һλ�����0.�ͱ�Ϊ9
//			{
//				a[i + k] = '9';
//				k++;
//			}
//
//			//������Ա�֤i + k��һλ�ϲ���0
//
//			// ����Ҫ��λ��
//			a[i + k] = a[i + k] - '1' + '0'; //a[i+k] - '1'�Ժ���int�ͣ�Ҫת�����ַ�������+'0'
//
//
//			//  a[i] =  (������ - �������� + '0��
//			a[i] = (a[i] - '0' + 10) - (b[i] - '0') + '0';
//		}
//	}
//	reverse(a.begin(), a.end());
//	if (a.find_first_not_of('0') == string::npos) //�Ҳ�����0��Ҳ����ȫ��0 ����return"0"
//		return "0";
//	return a.substr(a.find_first_not_of('0'));
//}
//string divide(string a, string b)
//{
//	//ֻ����a < b�������
//	string ans = "0.";
//	for (int i = 0; i < 101; i++)
//	{
//		a.append("0"); //��0�Ĺ���
//		int t = 0;
//		while (cmp(a, b) >= 0)
//		{
//			a = substact(a, b);   //��ͣ��������
//			t++;	 //��¼���˶��ٴμ���
//		}
//		string t_str;
//		i2s(t, t_str);
//		ans.append(t_str);
//	}
//	return ans;
//
//}
//
//int main()
//{
//	string str1;
//	string str2;
//	while (getline(cin, str1) && getline(cin, str2))
//	{
//		//cout << "���: "  << add(str1, str2) << endl;
//		cout << "���: " << substact(str1, str2) << endl;
//		//cout << "���: " << divide(str1, str2) << endl;
//	}
//	
//}

#include <set>

#include <iostream>

using namespace std;

int ans;

void f(int dian, int hua, int jiu) {
	if (dian == 0 && hua == 0 && jiu == 1)
		ans++;
	if (dian > 0) f(dian - 1, hua, jiu * 2);
	if (hua > 0) f(dian, hua - 1, jiu - 1);
}

int main(int argc, const char *argv[]) {
	f(5, 9, 2);
	cout << ans << endl;
	system("pause");
	return 0;

}