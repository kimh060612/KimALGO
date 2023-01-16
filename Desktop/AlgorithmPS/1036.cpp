#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using iip = pair<int, int>;
int N, K, nA[60];
int S[60][60], nS[60], ANS[60];
vector<string> SS;

bool compare(const iip &i, const iip &j) {
    if (i.second == j.second) return i.first < j.first;
    return i.second > j.second;
}
bool compareString(const string &i, const string &j) {
    if (i.size() == j.size()) return i < j;
    return i.size() > j.size();
}
int max(int a, int b) { return a > b ? a : b; }

int main()
{
    cin >> N;
    int maxLen = -1;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        
        nS[i] = s.size();
        SS.push_back(s);
        maxLen = max(maxLen, s.size());
    }
    cin >> K;
    sort(SS.begin(), SS.end(), compareString);
    int k = K, len = maxLen;
    while (k > 0 && len >= 1) {
        for (int i = SS.size() - 1; i > 0 ; i--) {
            if (SS[i].size() >= len) {
                char index = SS[i][len - 1];
                int l;
                if ('0' <= index && index <= '9') l = index - '0';
                else l = index - 'A' + 10;
                if (!nA[l] && k > 0) {
                    nA[l] = 1;
                    k--;
                }
            } else break;
        }
        len --;
    }   

    for (int i = 0; i < SS.size(); i++) {
        for (int j = 0; j < SS[i].size(); j++) {
            string s = SS[i];
            char index = s[j];
            int l;
            if ('0' <= index && index <= '9') l = index - '0';
            else l = index - 'A' + 10;
            if (nA[l]) s[j] = 'Z';
            if ('0' <= s[j] && s[j] <= '9') {
                S[i + 1][j + 1] = s[j] - '0';
            } else {
                S[i + 1][j + 1] = s[j] - 'A' + 10;
            }
        }
    }

    int carry;
    int l = -1;
    for (int i = 1; i <= N; i++) {
        carry = 0;
        for (int j = 1; j <= nS[i]; j++) {
            ANS[j] = ANS[j] + S[i][j] + carry;
            carry = ANS[j] / 36;
            ANS[j] %= 36;
        }
        l = max(l, nS[i]);
        if (carry > 0) {
            ANS[nS[i] + 1] = carry;
            l = max(l, nS[i] + 1);
        }
    }

    for (int i = 1; i <= l; i++) {
        if (0 <= ANS[i] && ANS[i] <= 9) cout << (char)(ANS[i] + '0');
        else cout << (char)(ANS[i] - 10 + 'A');
    }
    cout << endl;
    return 0;
}