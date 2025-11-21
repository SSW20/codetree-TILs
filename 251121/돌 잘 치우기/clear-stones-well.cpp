#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, m, r, c;
int grid[100][100];
int visited[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> rocks;
queue<pair<int, int>> q;
int ansMax = -1;
void BFS()
{
    queue<pair<int, int>> temp_q = q;

    while (!temp_q.empty())
    {
        int cur_x = temp_q.front().first;
        int cur_y = temp_q.front().second;

        temp_q.pop();
        for (int d = 0; d < 4; ++d)
        {
            int x = cur_x + dx[d];
            int y = cur_y + dy[d];
            if (x < 0 || y < 0 || x >= n || y >= n) continue;
            if (grid[x][y] == 1 || visited[x][y] == 1) continue;
            temp_q.push(make_pair(x, y));
            visited[x][y] = 1;
        }
    }
}

void Clear()
{
    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < n; ++k)
        {
            visited[i][k] = 0;
        }
    }
}

int Calculate()
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < n; ++k)
        {
            if (visited[i][k]) ++count;
        }
    }
    Clear();
    return count;
}



void Select(int idx, int cnt)
{
    if (cnt == m)
    {
        BFS();
        ansMax = max(ansMax, Calculate());
    }
    for (int i = idx; i < rocks.size(); ++i)
    {
        grid[rocks[i].first][rocks[i].second] = 0;
        Select(i + 1, cnt + 1);
        grid[rocks[i].first][rocks[i].second] = 1;
    }
}

int main() {
    cin >> n >> k >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 1)
            {
                rocks.push_back(make_pair(i, j));
            }
        }

    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        r--;
        c--;
        q.push(make_pair(r, c));
        visited[r][c] = 1;
    }

    Select(0, 0);
    cout << ansMax;

    // Please write your code here.

    return 0;
}
