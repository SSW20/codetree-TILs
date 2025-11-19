#include <iostream>
#include <vector>
using namespace std;

int N, M;
int grid[50][50];
int visited[50][50];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int K;
void clear()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = false;
        }
    }
}

void Divide(int r, int c)
{
    visited[r][c] = true;

    for (int d = 0; d < 4; ++d)
    {
        int x = r + dx[d];
        int y = c + dy[d];
        if (x < 0 || y < 0 || x >= N || y >= M) continue;
        if (grid[x][y] <= K || visited[x][y] == true) continue;
        Divide(x, y);
    }
}

int main() {
    cin >> N >> M;
    int max_height = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            max_height = max(max_height, grid[i][j]);
        }
    }

    int max_sector = -1;
    int maxK = -1;
    for (K = 1; K <= max_height; ++K)
    {
        int town = 0;
        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < M; j++) 
            {
                if (visited[i][j] == false && grid[i][j] > K)
                {
                    Divide(i, j);
                    town++;
                }
            }
        }
        clear();
        if (max_sector < town)
        {
            maxK = K;
            max_sector = town;
        }
    }

    cout << maxK << ' ' << max_sector;

    // Please write your code here.

    return 0;
}
