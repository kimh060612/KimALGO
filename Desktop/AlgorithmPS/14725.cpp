#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N;
vector<string> V[1001];

bool compare(const vector<string> &i, const vector<string> &j) {
    int index = 0, e = i.size() < j.size() ? i.size() : j.size();
    while (index < e) {
        if (i[index].compare(j[index]) == 0) index++;
        else return i[index] < j[index];
    }
    return i[e - 1] < j[e - 1];
}

struct Node {
    string food;
    vector<Node> children;
    Node () {
        this->children = vector<Node>(0);
    }
} root;

void insert(Node &v, int depth, int index) {
    if (depth >= V[index].size()) return;
    string &ptr = V[index][depth];

    for (auto &n: v.children)
        if (n.food == ptr) {
            insert(n, depth + 1, index);
            return;
        }
    Node tmp;
    tmp.food = ptr;
    v.children.push_back(tmp);
    insert(v.children.back(), depth + 1, index);
}

void dfs(Node v, int depth) {
    for (int i = 0; i < depth - 1; i++) 
        cout << "--";
    if (depth != 0) cout << v.food << "\n";

    for (auto n: v.children) {
        dfs(n, depth + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int K;
        cin >> K;
        for (int j = 1; j <= K; j++) {
            string a;
            cin >> a;
            V[i].push_back(a);
        }
    }
    sort(V + 1, V + 1 + N, compare);

    for (int i = 1; i <= N; i++) {
        insert(root, 0, i);
    }

    dfs(root, 0);

    return 0;
}