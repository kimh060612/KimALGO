#include <iostream>

using namespace std;

int A[100]; // n_i
int Y[100], X[100][100];
int I, N;

int Prod(int col)
{
    int mul = 1;
    for (int i = 0; i < I; i++)
    {
        if (X[i][col] != 0) mul *= A[i];
    }
    return mul;
}

int main()
{
    cin >> I >> N;
    for (int i = 0; i < I; i++)
    {
        cin >> A[i];
    }

    // Initialize
    for (int i = 0; i < I; i++)
    {
        Y[i] = 1;
        X[i][i] = 1;
    }

    int i = 0, j = 0;
    while (i < I)
    {
        int k = i;
        while (k > j)
        {
            X[i][k - 1] = X[i][k];
            if (Prod(k - 1) > N) {
                X[i][k - 1] = 0;
                j = k;
                break;
            }
            else {
                X[i][k] = 0;
            }
            k -= 1;
        }
        i += 1;
    }

    i = 0;
    while (i < I)
    {
        int sum = 0;
        for (int l = 0; l < I; l++) sum += X[l][i];
        if (sum == 0) Y[i] = 0;
        i += 1;
    }

    for (i = 0; i < I; i++)
    {
        for (j = 0; j < I; j++)
        {
            cout << X[i][j] << "  ";
        }
        cout << endl;
    }

    cout << endl;
    for (i = 0; i < I; i++) cout << Y[i] << "  ";
    cout << endl;

    return 0;
}