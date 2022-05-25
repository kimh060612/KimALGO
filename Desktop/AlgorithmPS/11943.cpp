#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int ans = (a + d) < (b + c) ? (a + d) : (b + c);
	cout << ans << endl;
	return 0;
}