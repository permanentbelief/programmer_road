//#define _CRT_SECURE_NO_WARNINGS 1 
//#include <iostream>
//#include  <string>
//#include  <vector>
//using namespace std;
//
//// 方法一
////int main()
////{
//	//string code = "VWXYZABCDEFGHIJKLMNOPQRSTU";
//	//string str;
//	////char _ch = ' ';
//	//while (getline(cin,str))
//	//{
//	//	for (int i = 0; i < str.size(); i++)
//	//	{
//	//		if (str[i] >= 'A' && str[i] <= 'Z')
//	//			cout << code[str[i] - 'A'];
//	//		else
//	//			cout << str[i];
//	//	}
//	//	cout << endl;
//	
//
//	//}
//	//system("pause");
////}
//
//方法二  不依靠code字符串
int main()
{
	string str;
	while (getline(cin, str))
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'F' && str[i] <= 'Z')
			{
				cout << char(str[i] - 5);
			}
			else if (str[i] >= 'A' && str[i] < 'F')
			{
				cout << char(str[i]+21);
			}
			else
				cout << str[i];
			
		}
		cout << endl;
	}
}