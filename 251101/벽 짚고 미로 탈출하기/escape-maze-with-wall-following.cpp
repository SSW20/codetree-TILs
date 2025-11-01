#include <iostream>

using namespace std;

int N;
int x, y;
char grid[101][101];

// 오 하 좌 상
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};




int main() {
    cin >> N;
    cin >> x >> y;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }
    int count = 1;
    int d = 0;
    int nextX = x;
    int nextY = y;
    if (grid[x][y] == '#') {
        cout << -1;
        return 0;
    }
    while (count <= N * N)
    {
        nextX += dx[d];
        nextY += dy[d];

        if (grid[nextX][nextY] == '.') ++count;
        if (nextX <= 0 || nextY <= 0 || nextX > N || nextY > N) break;
        // 한칸 이동 시  벽이 있을 때  
        if (grid[nextX][nextY] == '#')
        {
            d = (d + 3) % 4;
        }
        // 없을 때
        else
        {
            // 벽있을때
            if (d == 0)
            {
                if (grid[nextX + 1][nextY] != '#')
                    d = (d + 1) % 4;
            }
            else if (d == 1)
            {
                if (grid[nextX][nextY - 1] != '#')
                    d = (d + 1) % 4;
            }
            else if(d == 2)
            {
                if (grid[nextX - 1][nextY] != '#')
                    d = (d + 1) % 4;
            }
            else
            {
                if (grid[nextX][nextY + 1] != '#')
                    d = (d + 1) % 4;
            }
        }
    }
    // Please write your code here.
    if (count > N * N)
    {
        cout << -1;
    }
    else 
    {
        cout << count;
    }

    return 0;
}
