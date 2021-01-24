#include <iostream>

using namespace std;

long long N, K;

long long min(long long a, long long b) {return a < b ? a : b;}

long long go(long long mid) 
{
	long long cnt = 0;
	for (long long i = 1; i <= N; i++)
    {
		cnt += min(N, mid / i);
	}
	return cnt; 
}

int main()
{
    cin >> N >> K;
    long long left = 1;
    long long right = N * N;
    long long ans;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long indi = go(mid);
        if (indi >= K)
        {
            ans = mid;
            right = mid - 1;
        }
        else if (indi < K)
        {
            left = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}