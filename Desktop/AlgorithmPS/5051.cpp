#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <algorithm>
#include <iomanip>
#define MOD 1000000007
#define M_PI 3.14159265358979323846264338327950288

using namespace std;
typedef long long ll;
typedef complex<double> base;

int N;
int tmp[500001], sp[500001];

int max(int a, int b) { return a > b ? a : b; }

void fft(vector<base> &a, bool invert)
{
    int n = (int)a.size();
    for (int i=1,j=0;i<n;i++){
        int bit = n >> 1;
        for (;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (int len=2;len<=n;len<<=1){
        double ang = 2*M_PI/len*(invert?-1:1);
        base wlen(cos(ang), sin(ang));
        for (int i=0;i<n;i+=len){
            base w(1);
            for (int j=0;j<len/2;j++){
                base u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert){
        for (int i=0;i<n;i++) a[i] /= n;
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
	for (int i = 0; i < n; i++) a[i] = base(round(a[i].real()), 0);
}

int main()
{
	cin >> N;
	for (int i = 1; i < N; i++) {
		tmp[((ll)i * i) % N] ++;
		sp[(2 * (ll)i * i) % N] ++;
	}
	vector<base> p1(N);
	vector<base> p2(N);

	for(int i = 0; i < N; i++) p1[i] = base(tmp[i], 0);
	for(int i = 0; i < N; i++) p2[i] = base(tmp[i], 0);

	multiply(p1, p2);
	ll ans = 0;
	for(int i = 1; i < N; i++) {
        ll k = ((ll)i * i) % N;
        ll total = p1[k].real() + p1[N + k].real();
        ll eq = sp[k];
        ans = ans + ((total - eq) / 2 + eq);
    }
	cout << ans << "\n";
	return 0;
}