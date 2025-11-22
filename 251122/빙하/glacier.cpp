#include <iostream>
#include <queue>
using namespace std;

int N, M;
int a[200][200];
int temp_a[200][200];
int visited[200][200];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>> q;
bool check()
{
    for (int i = 0; i < N; ++i)
    {
        for (int k = 0; k < M; ++k)
        {
            if (a[i][k] == 1) return false;
        }
    }
    return true;
}

void clear()
{
    for (int i = 0; i < N; ++i)
    {
        for (int k = 0; k < M; ++k)
        {
            a[i][k] = temp_a[i][k];
        }
    }
}

pair<int,int> Find()
{
    for (int i = 0; i < N; ++i)
    {
        for (int k = 0; k < M; ++k)
        {
            if (a[i][k] == 0 && visited[i][k] == 0)
            {
                for (int d = 0; d < 4; ++d)
                {
                    int x = i + dx[d];
                    int y = k + dy[d];

                    if (x < 0 || y < 0 || x >= N || y >= M || visited[x][y] == 1) continue;
                    if (a[x][y] == 0) return make_pair(i, k);
                }
            }
        }
    }
}


void BFS(int time, int count)
{
    if (check())
    {
        cout << time << ' ' << count;
        return;
    }

    count = 0;
    pair<int, int> start = Find();
    q.push(start);
    visited[start.first][start.second] = 1;
    while (!q.empty())
    {
        int start_x = q.front().first;
        int start_y = q.front().second;
        
        q.pop();

        for (int d = 0; d < 4; ++d)
        {
            int x = start_x + dx[d];
            int y = start_y + dy[d];

            if (x < 0 || y < 0 || x >= N || y >= M || visited[x][y] == 1) continue;
            if (a[x][y] == 1 && temp_a[x][y] == 1) { temp_a[x][y] = 0; count++;  continue; }
            if (a[x][y] == 1) continue;
            q.push(make_pair(x, y));
            visited[x][y] = 1;
        }
    }

    clear();
    BFS(time + 1, count);
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
            temp_a[i][j] = a[i][j];
        }
    }

    BFS(0,0);
    // Please write your code here.

    return 0;
}
