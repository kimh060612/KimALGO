#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <algorithm>
#include <iomanip>
#define MOD 1000000007
#define M_PI 3.1415926535

using namespace std;
typedef complex<double> base;

int N;

int max(int a, int b) { return a > b ? a : b; }

void fft(vector<base> &a, bool inv) {
	int n = (int)a.size();
	vector<base> b = a;
	for (int i = 0; i < n; i++) {
		int sz = n, shift = 0, idx = i;
		while (sz > 1) {
			if (idx & 1) shift += sz >> 1;
			idx >>= 1;
			sz >>= 1;
		}
		a[shift + idx] = b[i];
	}
	for (int i = 1; i < n; i <<= 1) {
		double x = inv ? M_PI / i : -M_PI / i;
		base w = { cos(x), sin(x) };
		for (int j = 0; j < n; j += i << 1) {
			base th = { 1, 0 };
			for (int k = 0; k < i; k++) {
				base tmp = a[i + j + k] * th;
				a[i + j + k] = a[j + k] - tmp;
				a[j + k] += tmp;
				th *= w;
			}
		}
	}
	if (inv) {
		for (int i = 0; i < n; i++) {
			a[i] /= n;
		}
	}
}

void multiply(vector<base> &a, vector<base> &b) {
	int n = (int)max(a.size(), b.size());
	int i = 0;
	while ((1 << i) < (n << 1)) i++;
	n = 1 << i;
	a.resize(n);
	b.resize(n);
	fft(a, false);
	fft(b, false);
	for (int i = 0; i < n; i++) {
		a[i] *= b[i];
	}
	fft(a, true);
}

int main()
{
	cin >> N;
	vector<pair<int, pair<int, int>>> V;

	for (int i = 1; i < N; i++) cout << (i*i) % N << setw(5);
	cout << endl << endl;

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			cout << (i * i + j * j) % N << setw(5);
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			for (int k = 1; k < N; k++)
			{
				if ((i * i + j * j) % N == (k * k) % N)
				{
					V.push_back({ k, {i, j} });
					// cout << i << " " << j << " " << k << endl; //<< " " << i * i + j * j << " " << k * k << endl;
				}
			}
		}
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i].first << " " << V[i].second.first << " " << V[i].second.second << endl;
	}
	cout << V.size() << endl;
	return 0;
}