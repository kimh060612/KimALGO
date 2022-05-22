#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int A[3];
	cin >> A[0] >> A[1] >> A[2];
	sort(A, A + 3);

	int d1 = A[1] - A[0];
	int d2 = A[2] - A[1];

	if (d1 != d2 && d1 < d2) {
		cout << A[1] + d1 << endl;
	}
	else if (d1 != d2 && d1 > d2) {
		cout << A[0] + d2 << endl;
	}
	else {
		cout << A[2] + d2 << endl;
	}

	return 0;
}