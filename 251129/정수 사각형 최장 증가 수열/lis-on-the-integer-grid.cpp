#include <iostream>
#include <stack>
using namespace std;

int n;
int grid[500][500];
int visited[500][500];
long long int ans[500][500];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int Travel(int cnt, int r, int c)
{
    int maxCnt = 0;
    for (int d = 0; d < 4; ++d)
    {
        int x = r + dx[d];
        int y = c + dy[d];
        if (x < 0 || y < 0 || x >= n || y >= n) continue;
        if (grid[x][y] <= grid[r][c] || ans[x][y] > ans[r][c]) continue;
        maxCnt = max(maxCnt, cnt + Travel(cnt, x, y));
        
    }
    ans[r][c] = maxCnt;
    return maxCnt;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.

    long long int ansMax = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            if (ans[i][j] == 0) Travel(1, i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            ansMax = max(ansMax, ans[i][j]);
        }
    }
    cout << ansMax + 1;


    return 0;
}