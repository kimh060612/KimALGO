#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[100001];

bool search(int x)
{
    int s = 1, e = N;
    bool ans = false;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (A[mid] == x){
            ans = true;
            break;
        }
        else if (A[mid] > x) e = mid - 1;
        else if (A[mid] < x) s = mid + 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    sort(A + 1, A + 1 + N);

    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        int x;
        cin >> x;
        cout << search(x) << "\n";
    }

    return 0;
}