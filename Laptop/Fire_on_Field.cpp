#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

int A[1010], n;
int check[1010];

void clear(int N)
{
	for (int i = 0; i <= N; i++)
	{
		check[i] = 0;
	}
}

int main()
{
	//fin.open("input.txt");
	//fout.open("output.txt");

	cin >> n;

	A[0] = 1;
	A[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		int k = (i / 2);

		for (int j = 1; j <= k; j++)
		{
			if(2 * A[i - j] - A[i - 2*j] > 0)check[2 * A[i - j] - A[i - 2 * j]] = 1;
		}

		int tmp = 987654321;

		for (int j = 1; j <= i; j++)
		{
			if (!check[j])
			{
				if (tmp > j) tmp = j;
			}
		}

		clear(i);

		A[i] = tmp;
	}

	cout << A[n] << endl;

	//fin.close();
	//fout.close();
	return 0;
}