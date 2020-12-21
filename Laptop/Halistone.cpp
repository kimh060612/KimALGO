#include <cstdio>
#pragma warning(disable:4996)

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		int N;
		scanf("%d", &N);
		int tmp = 1;
		int iter = N;
		while (iter != 1)
		{
			tmp = max(iter, tmp);
			if (iter % 2 == 0) iter /= 2;
			else { iter *= 3; iter++; }
		}
		printf("%d\n", tmp);
	}
	return 0;
}