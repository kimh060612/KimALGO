#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> A[100001];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i].first >> A[i].second;
	sort(A + 1, A + 1 + n);

	vector<pair<int, int>> V;
	V.push_back(A[1]);
	for (int i = 2; i <= n; i++)
	{
		int j = V.size() - 1;
		if (A[i].first >= V[j].first && A[i].second < V[j].second)
		{
			V.pop_back();
			V.push_back(A[i]);
		}
		else if (A[i].first >= V[j].second){
			V.push_back(A[i]);
		}
	}

	cout << V.size() << endl;
	return 0;
}