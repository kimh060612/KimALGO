#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	int t = 0;
	if (a < 0) {
		t += c * abs(a);
		t += d;
		t += e * b;
	}
	else if (a > 0) {
		t += e * (b - a);
	}

	cout << t << endl;
	return 0;
}