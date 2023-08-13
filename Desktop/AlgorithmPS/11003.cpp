#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

struct Data
{
    int index;
    ll data;
    Data(int _index, ll _data): index(_index), data(_data) {}
    bool operator<(const Data &d) const {
        if (this->data == d.data) return this->index < d.index;
        return d.data < this->data;
    }
};


int N, L;
ll A[5000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> L;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    priority_queue<Data> pq;

    for (int i = 1; i <= N; i++) {
        pq.push(Data(i, A[i]));
        ll ret = pq.top().data;
        int inow = pq.top().index, lim = i - L + 1 >= 1 ? i - L + 1: 1;
        if (inow < lim) {
            while (!pq.empty()) {
                ret = pq.top().data;
                inow = pq.top().index;
                if (inow >= lim) break;
                pq.pop();
            }
        }
        cout << ret << " ";
    }
    cout << "\n";
    return 0;
}