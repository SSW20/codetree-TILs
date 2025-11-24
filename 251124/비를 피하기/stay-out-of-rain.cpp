#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, h, m;
int grid[100][100];
int visited[100][100];
int ans[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector < pair<int, int>> people;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> h >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) people.push_back({ i,j });
        }
    }

    // Please write your code here.
    for (auto p : people)
    {
        memset(visited, 0, sizeof(visited));

        bool flag = false;
        queue<pair<int, int>> q;
        q.push({ p.first,p.second });
        visited[p.first][p.second] = 1;

        while (!q.empty() && !flag)
        {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            for (int d = 0; d < 4; ++d)
            {
                int nx = cx + dx[d];
                int ny = cy + dy[d];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (visited[nx][ny] >= 1 || grid[nx][ny] == 1) continue;
                if (grid[nx][ny] == 3)
                {
                    ans[p.first][p.second] = visited[cx][cy];
                    flag = true;
                    break;
                }
                q.push({ nx,ny });
                visited[nx][ny] = visited[cx][cy] + 1;
            }
        }
       if(!flag)ans[p.first][p.second] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}
