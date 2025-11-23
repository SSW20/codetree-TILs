#include <iostream>
#include <queue>
using namespace std;

int n;
int visited[100][100];
int path[100][100];
int dx[8] = { 1,1,-1,-1,2,2,-2,-2 };
int dy[8] = { 2,-2,2,-2,1,-1,1,-1 };
int main() {
    cin >> n;

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;

    queue<pair<int, int>> q;
    q.push({ r1,c1 });
    visited[r1][c1] = 1;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();

        for (int d = 0; d < 8; ++d)
        {
            int x = cx + dx[d];
            int y = cy + dy[d];

            if (x < 0 || y < 0 || x >= n || y >= n) continue;
            if (visited[x][y] == 1) continue;
            visited[x][y] = 1;
            path[x][y] = path[cx][cy] + 1;
            q.push({ x,y });
        }
    }
    if (visited[r2][c2])
    {
        cout << path[r2][c2];
    }
    else cout << -1;

    return 0;
}
