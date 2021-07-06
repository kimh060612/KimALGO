#include <iostream>
#include <vector>
#define MOD 10000

using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;

ll N;

matrix multiply(matrix &a, matrix &b)
{
    matrix c(2, vector<ll>(2));

    for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++){
			for (int k = 0; k < 2; k++) c[i][j] += a[i][k] * b[k][j];
			c[i][j] %= MOD;
		}
	return c;	
}

int main()
{
    while (1)
    {
        cin >> N;
        if (N == -1) break;

        matrix ans = {{1, 0}, {0, 1}};
        matrix a = {{1, 1}, {1, 0}};

        while (N > 0)
        {
            if (N % 2 == 1) ans = multiply(ans, a);
            a = multiply(a, a);
            N /= 2;
        }
        cout << ans[0][1] << endl;
    }
    
    return 0;
}