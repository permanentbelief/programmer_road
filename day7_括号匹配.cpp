#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <stack>
using namespace std;
class Parenthesis 
{
public:

	  bool chkParenthesis(string A, int n) {
		stack<char> s;
		for (int i = 0; i < n; i++)
		{
			if (A[i] != '(' && A[i] != ')')
				return false;
			if (A[i] == ')')
			{
				if (s.empty())
					return false;
				s.pop();
			}
			if (A[i] == '(')
			s.push(A[i]);

		}
		if (s.empty())
			return true;
		else
		return false;	
	}
};
int main()
{

	Parenthesis p;
	string s("((()))");
	cout << p.chkParenthesis(s,s.size()) << endl;
	system("pause");
}
// 例1
//class parent
//{
//	int i;
//protected:
//	int x;
//public :
//	parent()
//	{
//		x = 0;
//		i = 0;
//	}
//	void change()
//	{
//		x++;
//		i++;
//	}
//	void display();
//};
//class son : public parent
//{
//public:
//	void modify();
//};
//void parent::display()
//{
//	cout << "x = " << x << endl;
//}
//void son::modify()
//{
//	x++;
//}
//int main()
//{
//	son A;
//	parent B;
//	A.display();
//	A.change();
//	A.modify();
//	A.display();
//	B.change();    
//	B.display();  // 输出parent对象B的x
//	system("pause"); // 0 2 1
//}
 