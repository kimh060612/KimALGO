#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int A[5];
	cin >> A[0] >> A[1] >> A[2] >> A[3];
	sort(A, A + 4);
	
	cout << A[2] * A[0] << endl;

	return 0;
}