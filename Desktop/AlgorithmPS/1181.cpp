#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(const string &i , const string &j)
{
    if (i.size() == j.size()) return i < j;
    else return i.size() < j.size();
}

int main()
{
    int N;
    vector<string> V;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        string S;
        cin >> S;
        V.push_back(S);
    }
    sort(V.begin(), V.end(), compare);

    cout << V[0] << endl;
    for (int i = 1; i < N; i++)
    {
        if (V[i] == V[i - 1]) continue;
        cout << V[i] << endl;
    }

    return 0;
}