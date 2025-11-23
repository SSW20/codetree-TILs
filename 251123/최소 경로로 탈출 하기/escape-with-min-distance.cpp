#include <iostream>
#include <queue>
using namespace std;

int n, m;
int a[100][100];
int visited[100][100];
int path[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    visited[0][0];
    
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();

        for (int d = 0; d < 4; ++d)
        {
            int x = cx + dx[d];
            int y = cy + dy[d];

            if (x < 0 || y < 0 || x >= n || y >= m) continue;
            if (visited[x][y] || a[x][y] == 0) continue;
            visited[x][y] = 1;
            path[x][y] = path[cx][cy] + 1;
            q.push({ x,y });
        }
    }

    if (path[n - 1][m - 1])
    {
        cout << path[n - 1][m - 1];
    }
    else cout << -1;

    return 0;
}
