/*
��������: ���� ��ȹ���� ���� ���� �� �ϳ� ,LCS
���� ���̵��: ���� �Ǽ�, ��ȭ���� ����. �װ� ���� ¥�µ� �װ��� ��� ���·� ����
������ : ������ ��Ÿ�� ���� �������
*/

#include <iostream>
#include <fstream>
#include <string>
#define max(a,b) a > b ? a : b

using namespace std;

ifstream fin;
ofstream fout;

string A, B;

int LCS(string L1, string L2)
{
	int n1 = L1.size();
	int n2 = L2.size();

	if (n1 == 0 || n2 == 0)return 0;

	else if (L1[n1 - 1] == L2[n2 - 1])return LCS(L1.substr(0,n1-1),L2.substr(0,n2-1)) + 1;

	else return max(LCS(L1, L2.substr(0, n2 - 1)),LCS(L1.substr(0, n1 - 1),L2));

}

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	cin >> A >> B;

	int answer = LCS(A,B);

	cout << answer << endl;

	fin.close();
	fout.close();
	return 0;
}