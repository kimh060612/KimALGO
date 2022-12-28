#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S;
int A[100001];

int main()
{
    cin >> S;
    int N = S.length();
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        A[i] = S[i] - '0';
        sum += A[i];
    }
    sort(A, A + N);
    if (A[0] != 0 || sum % 3 != 0)
    {
        cout << -1 << endl;
        return 0;
    } 
    else 
    {
        for (int i = N - 1; i >= 0; i--)cout << A[i];
    }
    return 0;
}