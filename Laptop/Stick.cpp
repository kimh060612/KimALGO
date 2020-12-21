#include <iostream>

using namespace std;

int main()
{
	int X;
	cin >> X;
	int r = 0;
	while (X != 0) {
		if (X % 2 == 1) r++;
		X /= 2;
	}
	cout << r << '\n';
}