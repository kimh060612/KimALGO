#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

int N , A[15];

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int left;
		cin >> left;

		for (int j = 1; j <= N; j++)
		{
			if (left == 0 && A[j] == 0)
			{
				A[j] = i;
				break;
			}
			else if (A[j] == 0)
			{
				left--;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	fin.close();
	fout.close();
	return 0;
}