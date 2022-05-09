#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[101], B[101];

bool isAllZero(vector<int> &A)
{
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] != 0) return false;
	}
	return true;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> A;
		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			A.push_back(a);
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (A[i] == A[j] && A[i] != 0 && A[j] != 0) {
					A[j] = 0;
					ans++;
				}
			}
		}
		
		sort(A.begin(), A.end());

		int min_ = A[0];
		sort(A.begin(), A.end());
		min_ = A[0];
		if (min_ == 0) {
			for (int i = 0; i < n; i++)
			{
				if (A[i] != 0) ans++;
			}
		}
		else {
			A[n - 1] = A[0];
			ans++;
			A[0] = 0;
			ans++;
			for (int i = 0; i < n; i++)
			{
				if (A[i] != 0) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}