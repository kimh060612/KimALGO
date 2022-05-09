#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;

		int k = 0;
		vector<int> A;
		for (int i = 1; i < n; i++)
		{
			if (s[i - 1] != s[i]) {
				A.push_back(k + 1);
				k = 0;
			}
			else {
				k++;
			}
		}
		A.push_back(k + 1);

		int ans = 0;
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] % 2 == 1) {
				int j = i + 1;
				while (j < A.size()) {
					if (A[j] % 2 == 1)
					{
						ans += (j - i);
						i = j;
						break;
					}
					else j++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}