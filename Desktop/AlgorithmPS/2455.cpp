#include <iostream>

using namespace std;

int main()
{
	int ans = 0, sum = 0;
	while (1)
	{
		int a, b;
		cin >> a >> b;
		sum += b - a;
		ans = ans < sum ? sum : ans;
		if (b == 0) break;
	}
	cout << ans << endl;
	return 0;
}