#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main()
{

	string line;
	while (getline(cin, line))
	{
		// ��ը��� ֱ�����
		if (line.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else
		{
			int dash = line.find('-');
			// �ֿ�������
			string str1 = line.substr(0, dash);
			string str2 = line.substr(dash + 1);
			// ��ȡ�Ŀո�Ĵ���
			int c1 = count(str1.begin(), str1.end(), ' ');
			int c2 = count(str2.begin(), str2.end(), ' ');
			// �õ���һ����
			string first1 = str1.substr(0, str1.find(' '));
			string first2 = str2.substr(0, str2.find(' '));
			string str = "2345678910JQKA2jokerJOKER";
			if (c1 == c2)
			{
				//ֻҪ������ȣ����һ�Ŵ�ľ������
				if (str.find(first1) > str.find(first2))
					cout << str1 << endl;
				else
					cout << str2 << endl;
			}
			else // ˵�����Ͳ�ͬ ��c1��c2Ϊ3˵����ը��������Խ��бȽ�
			{
				if (c1 == 3)
					cout << str1 << endl;
				else if (c2 == 3)
					cout << str2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
	system("pause");
}