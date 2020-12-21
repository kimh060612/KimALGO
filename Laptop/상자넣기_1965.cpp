/*
문제유형: 동적 계획법의 산출 문제중 하나 LIS
구현 아이디어: 상자가 들어가는 로직 자체가 가장 긴 증가 수열 자체의 정의를 만족하기에 그냥 그렇게 썼다.
헷갈린점: 시간만 있으면 누구나 풀 수 있는 문제
느낀점:역시 쉬운건 정답율이 높다
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int A[1001];
int N;
int check[1001];

void clear()
{
	for (int i = 1; i <= N; i++)
	{
		check[i] = 0;
	}
}

int LIS(const int s_index)
{
	int &ret = check[s_index];
	if (ret != 0) { return ret; }
	for (int i = s_index + 1; i <= N; i++)
	{
		if (A[i] > A[s_index])
		{
			if (LIS(i) > ret) { ret = LIS(i); }
		}
	}
	++ret;
	return ret;
}

int main()
{

	cin >> N;

	int answer = -987654321;

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++)
	{
		if (LIS(i) > answer) { answer = LIS(i); }
		clear();
	}

	cout << answer;

	return 0;
}
