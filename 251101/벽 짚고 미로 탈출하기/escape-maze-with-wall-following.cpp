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
    int  count = 0;
    int d = 0;
    int curX = x;
    int curY = y;
    if (grid[x][y] == '#') {
        cout << -1;
        return 0;
    }
    while (count <= N * N)
    {
        if (curX <= 0 || curY <= 0 || curX > N || curY > N) break;
            if (d == 0)
            {
                if (grid[curX + 1][curY] != '#')
                    d = (d + 1) % 4;
            }
            else if (d == 1)
            {
                if (grid[curX][curY - 1] != '#')
                    d = (d + 1) % 4;
            }
            else if (d == 2)
            {
                if (grid[curX - 1][curY] != '#')
                    d = (d + 1) % 4;
            }
            else
            {
                if (grid[curX][curY + 1] != '#')
                    d = (d + 1) % 4;
            }
            if (grid[curX + dx[d]][curY + dy[d]] == '#')
            {
                int temp = 0;
                while (grid[curX + dx[d]][curY + dy[d]] == '#' && temp < 4)
                {
                    d = (d + 3) % 4;
                    ++temp;
                }
                if (temp == 4)
                {
                    count = N * N + 1;
                    break;
                }
            }

        curX += dx[d];
        curY += dy[d];
        ++count;

    }
    // Please write your code here.
    if (count > N * N)
    {
        cout << -1;
    }
    else {
        cout << count;
    }
    

    return 0;
}
