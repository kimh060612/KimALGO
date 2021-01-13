#include <iostream>

using namespace std;

int R, C;
int A[25][25];
int maxDepth = 0;
int alpha[26];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool inRange(int y, int x) {return (1 <= x && x <= C && 1 <= y && y <= R);}
int max(int a, int b) {return a > b ? a : b;}

void Depth(int y, int x, int depth)
{
    
    alpha[A[y][x]]++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!inRange(ny, nx))continue;
        if (alpha[A[ny][nx]] == 0)
        {
            //alpha[A[ny][nx]] ++;
            Depth(ny, nx, depth + 1);
            //alpha[A[ny][nx]] --;
        }
    }
    alpha[A[y][x]] --;
    maxDepth = max(maxDepth, depth);
}

int main()
{
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        char tmp[21];
        cin >> tmp;
        for (int j = 0; j < C; j++)
        {
            A[i][j + 1] = tmp[j] - 'A';
        }
    }

    alpha[A[1][1]] = 1;
    Depth(1, 1, 1);

    cout << maxDepth << endl;

    return 0;
}


// #include <iostream>
// #include <vector>

// using namespace std;

// int R, C;
// int A[25][25];
// int maxDepth = 0;
// vector<int> V;
// int dx[] = {1, 0, -1, 0};
// int dy[] = {0, 1, 0, -1};

// bool inRange(int y, int x) {return (1 <= x && x <= C && 1 <= y && y <= R);}
// int max(int a, int b) {return a > b ? a : b;}

// void Depth(int y, int x, int depth)
// {
//     maxDepth = max(maxDepth, depth);
//     for (int i = 0; i < 4; i++)
//     {
//         int nx = x + dx[i];
//         int ny = y + dy[i];
//         bool isDup = false;
//         if (!inRange(ny, nx))continue;
//         for (int j = 0; j < V.size(); j++)
//         {
//             if (V[j] == A[ny][nx])isDup = true;
//         }
//         if (!isDup)
//         {
//             V.push_back(A[ny][nx]);
//             Depth(ny, nx, depth + 1);
//             V.pop_back();
//         }
//     }
// }

// int main()
// {
//     cin >> R >> C;
//     for (int i = 1; i <= R; i++)
//     {
//         char tmp[21];
//         cin >> tmp;
//         for (int j = 0; j < C; j++)
//         {
//             A[i][j + 1] = tmp[j] - 'A';
//         }
//     }
//     V.push_back(A[1][1]);
//     Depth(1, 1, 1);

//     cout << maxDepth << endl;

//     return 0;
// }


