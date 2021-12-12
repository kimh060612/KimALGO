#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int A[51];

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    sort(A + 1, A  + N + 1);
    
    cout << A[1] * A[N] << endl;

    return 0;
}