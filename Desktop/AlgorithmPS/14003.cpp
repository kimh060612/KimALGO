#include <iostream>
#include <vector>

using namespace std;

int N;
int A[1000001], visit[1000001], trace[1000000];
vector<int> V;

int search(int x)
{
    int s = 0, e = V.size() - 1;
    int mid;
    while (s < e)
    {
        mid = (s + e) / 2;
        if (V[mid] >= x) e = mid;
        else s = mid + 1; 
    }
    return e;
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
    
    int LIMIT = (-1) * (1 << 30);
    V.push_back(LIMIT);
    for (int i = 1; i <= N; i++)
    {
        if (V.back() < A[i])
        {
            trace[i] = V.size();
            V.push_back(A[i]);       
        }
        else 
        {
            int x = search(A[i]);
            V[x] = A[i];
            trace[i] = x;
        }
    }

    cout << V.size() - 1 << endl;
    int num = V.size() - 1;
    for (int i = N; i >= 1 && num; i--)
    {
        if (trace[i] == num)
        {
            visit[i] = 1;
            num --;
        }
    }   
    for (int i = 1; i <= N; i++) if (visit[i]) cout << A[i] << " ";
    cout << endl;
    return 0;
}