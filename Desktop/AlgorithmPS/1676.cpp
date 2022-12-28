#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int two = 0, five = 0;
	for (int i = 1; i <= n; i++)
	{
		int k = i;
		while (k % 2 == 0)
		{
			k /= 2;
			two++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int k = i;
		while (k % 5 == 0)
		{
			k /= 5;
			five++;
		}
	}

	cout << ( two < five ? two : five) << endl;
	return 0;
}