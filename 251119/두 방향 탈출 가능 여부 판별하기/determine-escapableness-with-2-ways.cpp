#include <iostream>

using namespace std;

int n, m;
int grid[100][100];
bool visited[100][100]; 
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
bool flag = false;
void FindPath(int r, int c)
{
    visited[r][c] = true;

    for (int d = 0; d < 2; ++d)
    {
        int x = r + dx[d];
        int y = c + dy[d];
        if (x >= n || y >= m || x <0 || y<0)
        {
            continue;
        }

        if (visited[x][y] == false && grid[x][y] == 1)
        {
            FindPath(x, y);
        }

    }
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    FindPath(0, 0);
    // Please write your code here.
    if (visited[n - 1][m - 1] == true) cout << 1;
    else cout << 0;
    return 0;
}
