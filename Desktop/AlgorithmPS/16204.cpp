#include <iostream>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	if (m > k) {
		cout << k + n - m << endl;
	}
	else if (m < k) {
		cout << m + n - k << endl;
	}
	else {
		cout << n << endl;
	}
	return 0;
}