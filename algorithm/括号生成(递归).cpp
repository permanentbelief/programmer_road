#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//void generateParenthesis_(vector<string>& vs, string tmp, int n)
//{
//	if (tmp.size() == 2 * n)
//	{
//		vs.push_back(tmp);
//		return;
//	}
//	generateParenthesis_(vs, tmp + '(', n );
//
//	generateParenthesis_(vs, tmp + ')', n );
//
//}
//vector<string> generateParenthesis(int n)
//{
//	vector<string> vs;
//	string tmp;
//    generateParenthesis_(vs, tmp, n);
//	return vs;
//}


// ∫œ¿Ì¿®∫≈
void generate(string item, int left, int right, vector<string>& vs)
{
	if (left == 0  && 0 ==right)
	{
		vs.push_back(item);
		return;
	}
	if (left > 0)
		generate(item + '(', left - 1, right, vs);
	if (right > left)
		generate(item + ')', left, right - 1, vs);

}
int main()
{
	vector<string> result;
	generate("", 4, 4, result);
	for (auto &e : result)
	{
		cout << e << endl;
	}
	cout << endl;
	system("pause");
}