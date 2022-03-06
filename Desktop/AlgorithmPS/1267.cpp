#include <iostream>

using namespace std;

int main()
{
	int n, y = 0, m = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		y += (a / 30 + 1) * 10;
		m += (a / 60 + 1) * 15;
	}

	if (y < m) {
		cout << "Y " << y << endl;
	}
	else if (m < y) {
		cout << "M " << m << endl;
	}
	else {
		cout << "Y M " << y << endl;
	}

	return 0;
}