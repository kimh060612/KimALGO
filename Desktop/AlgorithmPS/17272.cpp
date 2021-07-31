#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;

ll N, M;

matrix multiply(matrix &a, matrix &b)
{
    matrix c(M, vector<ll>(M));

    for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++){
			for (int k = 0; k < M; k++) c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
		}
	return c;	
}

int main()
{
    cin >> N >> M;
    matrix ans(M, vector<ll>(M));
    matrix A(M, vector<ll>(M));

    for (int i = 0; i < M; i++) ans[i][i] = 1;
    for (int i = 0; i < M - 1; i++) A[i + 1][i] = 1;
    A[0][0] = 1;
    A[0][M - 1] = 1;
    
    ll k = N - M + 1;
    while(k > 0)
    {
        if (k % 2 == 1) ans = multiply(ans, A);
        A = multiply(A, A);
        k /= 2;
    }
    ll answer = 0;
    for (int i = 0; i < M; i++) answer = (answer + ans[0][i]) % MOD;
    cout << answer << endl;
    return 0;
}