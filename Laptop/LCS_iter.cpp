/*
문제유형: 동적 계획법의 문제 유형 중 하나 ,LCS
구현 아이디어: 구글 피셜, 점화식이 있음. 그것 고대로 짜는데 그것을 반복문 형태로 구현
느낀점 : 백준은 런타임 무새 개객기다
*/

#include <iostream>
#include <string.h>

using namespace std;

int LCS[110][110];
char A[1010], B[1010];

int MAX(int a, int b)
{
	return a > b ? a : b;
}

int main()
{

	cin >> A >> B;

	int nA = strlen(A), nB = strlen(B);

	for (int i = 1; i <= strlen(A); i++)
	{
		for (int j = 1; j <= strlen(B); j++)
		{
			if (A[i - 1] == B[j - 1]) LCS[i][j] += LCS[i-1][j-1] + 1;
			else
			{
				LCS[i][j] = MAX(LCS[i - 1][j], LCS[i][j - 1]);
			}
		}
	}

	cout << LCS[nA][nB];

	return 0;
}