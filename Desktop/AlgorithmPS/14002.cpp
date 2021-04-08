#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

int N;
vector<int> A;

int main()
{
    cin >> N;
    int sub;
    cin >> sub;
    A.push_back(sub);

    for (int i = 1; i < N; i++) {
        int sub;
        cin >> sub;

        int size = A.size();
        for (int j = size - 1; j >= 0; j --) {
            if (A.at(j) < sub) {
                if (j == size - 1)A.push_back(sub);
                else A.at(j + 1) = sub;
                break;
            }
            if (j == 0)A.at(0) = sub;
        }
    }

    cout << A.size() << endl;

    return 0;
}