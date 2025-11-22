#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, k;
int grid[100][100];
int visited[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int r, c;
queue<pair<int, int>> q;

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    // Please write your code here.
    r -= 1; c -= 1;
   
    while (k-- > 0)
    {
        memset(visited, 0, sizeof(visited));
        q.push({ r,c });
        visited[r][c] = 1;
        int h = grid[r][c];

        int maxR = r, maxC = c, maxH = -1;

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
                if (visited[nx][ny]) continue;
                if (grid[nx][ny] < h)
                {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = 1;
                    if (maxH < grid[nx][ny])
                    {
                        maxH = grid[nx][ny];
                        maxR = nx;
                        maxC = ny;
                    }
                    if (maxH == grid[nx][ny])
                    {
                        if (maxR > nx) { maxR = nx; maxC = ny; }
                        if( maxR == nx) {if(maxC > ny) { maxR = nx; maxC = ny;}}
                    }
                }

            }
        }

        if (maxR == r && maxC == c) break;
        r = maxR; c = maxC;
    }

    cout << r + 1 << ' ' << c + 1;
    return 0;
}
