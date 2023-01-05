#include <iostream>
#include <string>

using namespace std;
int A[20][20], DP[11][20][20], cnt;

bool InRange(int y, int x) { return (1 <= y && y <= 9) && (1 <= x && x <= 9); }
pair<int, int> SudokuRange(int y, int x) {
    int sy = (((y - 1) / 3) * 3) + 1;
    int sx = (((x - 1) / 3) * 3) + 1;
    return { sy, sx };
}

int Sudoku(int y, int x, int depth) {
    if (!InRange(y, x) && A[y][x] != 0) return false;
    if (DP[A[y][x]][y][x] != 0) return DP[A[y][x]][y][x];

    int check[11] = {0, };
    for (int j = 1; j <= 9; j++) {
        if (A[y][j] != 0) check[A[y][j]] = 1;
        if (A[j][x] != 0) check[A[j][x]] = 1;
    }
    pair<int, int> su_ = SudokuRange(y, x);
    for (int i = su_.first; i <= su_.first + 2; i++) {
        for (int j = su_.second; j <= su_.second + 2; j++) {
            if (A[i][j] != 0) check[A[i][j]] = 1;
        }
    }

    for (int j = 1; j <= 9; j++) 
    {
        if (check[j] == 0) {
            A[y][x] = j;
            bool flag = false;
            for (int k = y; k <= 9; k++) {
                for (int l = 1; l <= 9; l++) {
                    if (A[k][l] == 0) {
                        DP[j][y][x] = Sudoku(k, l, depth + 1);
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (depth == cnt) {
                for (int i = 1; i <= 9; i++) {
                    for (int j = 1; j <= 9; j++)
                        cout << A[i][j];
                    cout << endl;
                }
                exit(0);
            }
            A[y][x] = 0;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int sy = 1, sx = 1;
    bool flag = true;
    for (int i = 1; i <= 9; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++) {
            A[i][j + 1] = s[j] - '0';
            if (A[i][j + 1] == 0) cnt ++;
            if (A[i][j + 1] == 0 && flag) {
                sy = i;
                sx = j + 1;
                flag = false;
            }
        }
    }

    Sudoku(sy, sx, 1);

    return 0;
}