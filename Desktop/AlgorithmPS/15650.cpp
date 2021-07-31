#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

bool desc(int a, int b){
    return a > b;
}

int main()
{
    cin >> N >> M;
    vector<int> n;
    for (int i = 1; i <= N; i++) n.push_back(i);

    vector<int> ind;
    for (int i = 1; i <= M; i++) ind.push_back(1);
    for (int i = 1; i <= N - M; i++) ind.push_back(0);
    sort(ind.begin(), ind.end(), desc);

    do {
        for (int i = 0; i < ind.size(); i++)
        {
            if (ind[i])cout << n[i] << " ";
        }
        cout << "\n";
    } while(next_permutation(ind.begin(), ind.end(), desc));

    return 0;
}