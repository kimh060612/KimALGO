#include <iostream>
#include <fstream>

using namespace std;

ifstream fin;
ofstream fout;

int main()
{
	fin.open("input.txt");
	fout.open("output.txt");

	int A, I;
	cin >> A >> I;

	cout << (A*(I - 1)) + 1 << endl;

	fin.close();
	fout.close();
}