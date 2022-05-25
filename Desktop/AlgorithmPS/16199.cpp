#include <iostream>

using namespace std;

int main()
{
	int y, m, d;
	int yy, mm, dd;
	cin >> y >> m >> d;
	cin >> yy >> mm >> dd;


	if (yy != y) {
		int k = (mm * 30 + dd) - (m * 30 + d) >= 0 ? yy - y : yy - y - 1;
		cout << k << endl;
	}
	else {
		cout << 0 << endl;
	}
	cout << yy - y + 1 << endl;
	cout << yy - y << endl;

	return 0;
}