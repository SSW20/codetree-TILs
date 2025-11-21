#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
int grid[100][100];
int visited[100][100];
int towns[100][100];
vector<pair<int, int>> numbers;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>> q;
int BFS()
{
    int i = 0;
    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;

        q.pop();
        visited[cur_x][cur_y] = 1;
        numbers.push_back(make_pair(cur_x, cur_y));
        i++;
        for (int d = 0; d < 4; ++d)
        {
            int x = cur_x + dx[d];
            int y = cur_y + dy[d];
            if (x < 0 || y < 0 || x >= n || y >= n) continue;
            if (visited[x][y] == 1 || grid[x][y] == 1) continue;

            q.push(make_pair(x, y));
            visited[x][y] = 1;
        }
    }
    return i;
}

void SetMax(int x)
{
    for (pair<int, int>& index : numbers)
    {
        int cur_x = index.first;
        int cur_y = index.second;

        towns[cur_x][cur_y] = x;
    }
    numbers.clear();
}

int main() {
    cin >> n >> k;
    int r, c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    int total = 0;

    for (int i = 0; i < k; i++)
    {
        cin >> r >> c;
        r--; c--;
        if (visited[r][c] == 1) continue;
        else {
            q.push(make_pair(r, c));
            int x = BFS();
            total += x;
            SetMax(x);
        }
    }

    cout << total;

    // Please write your code here.

    return 0;
}
