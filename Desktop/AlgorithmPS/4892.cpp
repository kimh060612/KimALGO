#include <iostream>

using namespace std;

int main()
{
	int t = 1;
	while (1) 
	{
		int n;
		cin >> n;
		if (n == 0) break;

		if (n % 2 == 1) cout << t << ". odd " << (n - 1) / 2 << endl;
		else cout << t << ". even " << n / 2 << endl;
		t++;
	}
	return 0;
}