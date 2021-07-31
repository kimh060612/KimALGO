#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int N;
vector<int> V[300001];
vector<int> T;
ll E[300001];
ll D, G;

int main()
{
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        E[i] = V[i].size();
        if (E[i] >= 3) G += (E[i]) * (E[i] - 1) * (E[i] - 2) / 6;
        if (E[i] >= 2) T.push_back(i);
    }

    for (int i = 0; i < T.size(); i++)
    {
        ll k = E[T[i]];
        for (int j = 0; j < V[T[i]].size(); j++)
        {
            D += (k - 1) * (E[V[T[i]][j]] - 1);
        }
    }
    
    if ((D / 2) == G * 3) cout << "DUDUDUNGA" << endl;
    else if ((D / 2) > G * 3) cout << "D" << endl;
    else if ((D / 2) < G * 3) cout << "G" << endl;
    return 0;
}