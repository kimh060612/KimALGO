#include <iostream>
#include <algorithm>
#define MAX 500001

using namespace std;

int N;
pair <int, int> A[MAX];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++) 
    {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A + 1, A + N + 1);
    
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = A[i].second - i > ans ?  A[i].second - i : ans; 
    }

    cout << ans << endl;

    return 0;
}