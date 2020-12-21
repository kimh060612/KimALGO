#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

int N, M;

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	cin >> N >> M;

	cout << (N * M) - 1 << endl;

	fin.close();
	fout.close();
	return 0;
}