#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int i = 0;
	while (n--) 
	{
		int a, b;
		cin >> a >> b;
		i++;
		cout << "Case " << i << ": " << a + b << endl;
	}
	return 0;
}