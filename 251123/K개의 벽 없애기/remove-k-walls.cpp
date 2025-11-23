#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
int grid[100][100];
int r1, c1, r2, c2;
int visited[100][100];
int dx[8] = { 0,0,1,-1 };
int dy[8] = { 1,-1,0,0 };
int ansMin = 2000000;
bool flag = false;
vector<pair<int, int>> rock;
vector<pair<int, int>> selected;
queue<pair<int, int>> q;
int BFS()
{
    memset(visited, 0, sizeof(visited));

    q.push({ r1,c1 });
    visited[r1][c1] = 1;

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
            if (visited[nx][ny] >= 1 || grid[nx][ny] == 1) continue;
            visited[nx][ny] = visited[cx][cy] + 1;
            q.push({ nx,ny });
        }
    }

    if (visited[r2][c2] != 0)
    {
        flag = true;
        return visited[r2][c2] - 1;
    }
    return 2000000;
}

void Select(int cnt, int idx)
{
    if (cnt == k)
    {
        ansMin = min(ansMin, BFS());
        return;
    }

    for (int i = idx; i < rock.size(); ++i)
    {
        selected.push_back({ rock[i].first, rock[i].second });
        grid[rock[i].first][rock[i].second] = 0;
        Select(cnt + 1, i + 1);
        selected.pop_back();
        grid[rock[i].first][rock[i].second] = 1;
        Select(cnt, i + 1);
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) rock.push_back({ i,j });
        }
    }

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;
    Select(0, 0);

    if (!flag) cout << -1;
    else cout << ansMin;

    // Please write your code here.

    return 0;
}
