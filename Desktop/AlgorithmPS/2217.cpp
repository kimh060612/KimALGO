#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[100001];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(A + 1, A + 1 + n);

	vector<int> K;
	for (int i = n; i >= 1; i--)
	{
		K.push_back(A[n - i + 1] * i);
	}
	sort(K.begin(), K.end());

	cout << K[K.size() - 1] << endl;
	return 0;
}