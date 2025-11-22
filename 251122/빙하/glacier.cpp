#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int a[200][200];
int temp_a[200][200];
int visited[200][200];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
            temp_a[i][j] = a[i][j];
        }
    }

    int time = 0;
    int last_ice_count = 0;
    
    // Please write your code here.
    while (true)
    {
        memset(visited, 0, sizeof(visited));
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        visited[0][0] = 1;
        int current_ice_count = 0;
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
                if (a[x][y] == 0)
                {
                    q.push(make_pair(x, y));
                    visited[x][y] = 1;
                }
                else 
                {
                    visited[x][y] = 1;
                    current_ice_count++;
                    a[x][y] = 0;
                }
            }
        }

        if (current_ice_count == 0) break;

        time++;
        last_ice_count = current_ice_count;
    }

    cout << time << " " << last_ice_count;
    return 0;
}
