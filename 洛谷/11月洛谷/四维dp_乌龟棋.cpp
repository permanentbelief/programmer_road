#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

double d[10]; // ����
double pi[10]; // ����
int main()
{
	double d1, c, d2, p, pmin = 1000, l = 0, pz = 0; // l��ָ�����е�������pz�ǻ�Ǯ��������ʼֵΪ0
	int n;
	cin >> d1 >> c >> d2 >> p >> n;
	d[0] = 0;
	double d0 = 0;
	pi[0] = p;
	double x = c * d2; // ������������ߵ��ľ���
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i] >> pi[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] - d[i - 1] > x)
		{
			cout << "No Solution" << endl;
			return 0;
		}
	}

	int ii = 0; // �˴�����ĵط� ---���Ž� 

	while (d1 - d0) //d1�ܵ�·�̣�d0 ��ǰ�ƶ��ľ��루����Դ��ľ��룩
	{

		// x������ ������ߵ�·��
		for (int i = ii + 1; d[i] - d0 <= x && i <= n; i++)
		{
			if (pi[i] < pmin) // �ҵ���͵ķ���
			{
				pmin = pi[i];
				ii = i;     //��¼���Ž���±�
			}
		}
		if (pmin <= p) // ��Χ�ڵļ���վ ii����Լ����� 
		{
			pz += ((d[ii] - d0) / d2 - l) * p;
			l = (d[ii] - d0) / d2; // �����е�����ֱ�Ӽ�����ii���
		}
		else if (d1 - d0 > x) // ֱ�Ӽ����� �˴�����˶���û�а취ֱ��һ��߶߶�յ�
		{
			pz += (c - 1) * p;
			l = c;
		}
		else  // �˴�����ˣ�һ�ε����յ�
		{
			pz += ((d1 - d0) / d2 - l)* p;
			break;
		}
		l = l - (d[ii] - d0) / d2; // ������ʣ�������
		d0 = d[ii]; // ��ϸ�ƶ�����(�ƶ����� ��ȷ�ĵ���)
		p = pmin; // ����p,�����´ν��бȽ�
		pmin = 1000; // �´�������Сֵ
	}
	printf("%.2lf", pz);
	return 0;
}