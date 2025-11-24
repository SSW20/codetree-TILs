#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, k;
int grid[100][100];
int visited[100][100];
int ans[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
    cin >> n >> k;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2)
            {
                q.push({ i,j });
                visited[i][j] = 1;
                ans[i][j] = 1;
            }
        }
    }

    // Please write your code here.
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();

        for (int d = 0; d < 4; ++d)
        {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny] == 1 || grid[nx][ny] == 0) continue;
            q.push({ nx,ny });
            visited[nx][ny] = 1;
            ans[nx][ny] = ans[cx][cy] + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 1)
            {
                cout << ans[i][j] - 1 << ' ';
            }
            else
            {
                if (grid[i][j] != 0)
                {
                    cout << -2 << ' ';
                }
                else cout << -1 << ' ';
            }
        }
        cout << '\n';
    }


    return 0;
}
