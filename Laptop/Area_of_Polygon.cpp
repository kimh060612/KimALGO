#include <iostream>
#include <math.h>

using namespace std;

struct Coord
{
	long long x;
	long long y;
};

int N;

long long distance(Coord a1, Coord a2)
{
	return (long long)((a1.x - a2.x)*(a1.x - a2.x)) + (long long)((a1.y - a2.y)*(a1.y - a2.y));
}

int CCW(Coord a1, Coord a2, Coord a3)
{
	long long Cross;
	Cross = (a2.x - a1.x)*(a3.y - a1.y) - (a2.y - a1.y)*(a3.x - a1.x);

	if (Cross > 0)return 1;
	else if (Cross < 0)return -1;
	else return 0;
}

Coord pi;
int compare(Coord left, Coord right)
{
	int ret;
	int direction = CCW(pi, left, right);
	if (direction == 0)ret = distance(pi, left) < distance(pi, right);
	else if (direction == 1)ret = 1;
	else if (direction == -1)ret = 0;
	return ret;
}

void Quick(Coord *List, int s, int e)
{
	if (e - s <= 0)return;

	Coord Pivot = List[s + (e - s + 1)/2];
	int i = s, j = e;

	while (i <= j)
	{
		while (compare(List[i], Pivot)) i++;
		while (compare(Pivot, List[j])) j--;

		if (i > j)break;

		Coord tmp = List[i];
		List[i] = List[j];
		List[j] = tmp;

		i++;
		j--;

	}

	Quick(List, s, j);
	Quick(List, i, e);

}

int main()
{
	Coord A[10001];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i].x >> A[i].y;
	}

	Quick(A, 0, N - 1);

	long long K = 0, Q = 0;
	for (int i = 0; i < N - 1; i++)
	{
		K += A[i].x*A[i + 1].y;
		Q += A[i].y*A[i + 1].x;
	}

	cout.precision(2);
	long long res = abs(K - Q);
	if (res%2 == 0)cout << res/2 << ".0" << endl;
	else cout << res / 2 << ".5" << endl;
	return 0;
}