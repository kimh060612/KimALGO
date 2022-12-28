#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N, x;
vector <int> V;

int binsearch(int x)
{
	int s = 0;
	int e = V.size() - 1;
	while (s < e)
	{
		int mid = (s + e) / 2;
		if (V[mid] > x) s = mid + 1;
		else e = mid;
	}
	return e;
}

int main()
{
	cin >> N;
	// V.push_back(987654321);
	for (int i = 1; i <= N; i++)
	{
		cin >> x;
		if (V.empty()) V.push_back(x);
		else if (V.back() > x) V.push_back(x);
		else
		{
			int index = binsearch(x);
			V[index] = x;
		}
	}
	// for (int i = 0; i < V.size(); i++) cout << V[i] << " ";
	// cout << endl;
	cout << N - V.size() << endl;
	return 0;
}