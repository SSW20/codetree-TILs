#include <iostream>
#include <queue>
using namespace std;

int n;
int grid[200][200];
int r, c;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    // Please write your code here.
    int bomb = grid[r - 1][c - 1];
    for (int i = 0; i < bomb; i++) 
    {
        for (int d = 0; d < 4; ++d)
        {
            int x = r - 1 + dx[d] * i;
            int y = c - 1 + dy[d] * i;
            if (x < 0 || y < 0 || x >= n || y >= n) continue;
            grid[x][y] = -1;
        }
    }
    for (int i = 0; i < n; i++) 
    {
        queue<int> q;
        for (int j = n-1; j >= 0; j--) 
        {
            if (grid[j][i] == -1) continue;
            q.push(grid[j][i]);
        }
        for (int j = n-1; j >= 0; j--)
        {
            if (q.empty()) grid[j][i] = 0;
            else
            {
                grid[j][i] = q.front();
                q.pop();
            }
        }

    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}
