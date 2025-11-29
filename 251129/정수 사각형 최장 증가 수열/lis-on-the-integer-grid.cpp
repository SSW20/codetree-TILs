#include <iostream>

using namespace std;

int n;
int grid[500][500];
int ans[500][500];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            ans[i][j] = 1;
        }
    }

    // Please write your code here.

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            for (int d = 0; d < 4; ++d)
            {
                int x = i + dx[d];
                int y = j + dy[d];
                if (x < 0 || y < 0 || x >= n || y >= n) continue;
                if (grid[x][y] > grid[i][j] && ans[x][y] <= ans[i][j])
                {
                    ans[x][y] = ans[i][j] + 1;
                }
            }
        }
    }

    int ansMax = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            ansMax = max(ansMax, ans[i][j]);
        }
    }

    cout << ansMax;


    return 0;
}