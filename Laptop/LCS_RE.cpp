/*
문제유형: 동적 계획법의 문제 유형 중 하나 ,LCS
구현 아이디어: 구글 피셜, 점화식이 있음. 그것 고대로 짜는데 그것을 재귀 형태로 구현
느낀점 : 백준은 런타임 무새 개객기다
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