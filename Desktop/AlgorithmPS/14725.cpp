#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N;
vector<string> V[1001];
vector<string> P[1001];
map<string, int> A;

bool compare(const vector<string> &i, const vector<string> &j) {
    int index = 0, e = i.size() < j.size() ? i.size() : j.size();
    while (index < e) {
        if (i[index].compare(j[index]) == 0) index++;
        else return i[index] < j[index];
    }
    return i[e - 1] < j[e - 1];
}

void dfs(int depth, int now) {
    if (V[now].size() <= depth) return;

    for (int i = 0; i < depth; i++)
        cout << "--";
    cout << V[now][depth] << endl;

    for (int i = 1; i <= N; i++) {
        if (V[now][depth].compare(V[i][depth]) == 0) {
            dfs(depth + 1, i);
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int K;
        cin >> K;
        for (int j = 1; j <= K; j++) {
            string a;
            cin >> a;
            V[i].push_back(a);
            if (j == 1) {
                if (A.find(a) == A.end()) {
                    A.insert({ a, i });
                }
            }
        }
    }
    sort(V + 1, V + 1 + N, compare);

    for (auto con: A) {
        dfs(0, con.second);
    }
    

    return 0;
}