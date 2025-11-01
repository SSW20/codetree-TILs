#include <iostream>

using namespace std;

int n, m;
int r, c;
int map[101][101];
int dice[4][4] = { {0,1,0,0},{0,5,0,0},{4,6,3,1},{0,2,0,0} };
void shift(int &r, int &c, char dir)
{
    //가로 2 / 세로 1
    if (dir == 'R')
    {
        if (c + 1 > n) return;
        //가로 왼쪽 당김
        int temp = dice[2][0];
        for (int i = 0; i < 3; ++i)
        {
            dice[2][i] = dice[2][i + 1];
        }
        dice[2][3] = temp;
        map[r][++c] = dice[2][1];
    }
    else if (dir == 'D')
    {
        if (r + 1 > n) return;
        //세로 위쪽 당김
        int temp = dice[0][1];
        for (int i = 0; i < 3; ++i)
        {
            dice[i][1] = dice[i+1][1];
        }
        dice[3][1] = temp;
        map[++r][c] = dice[2][1];
    }
    else if (dir == 'L')
    {
        if (c - 1 < 1) return;

        //가로 오른쪽 당김
        int temp = dice[2][3];
        for (int i = 3; i > 0; --i)
        {
            dice[2][i] = dice[2][i - 1];
        }
        dice[2][0] = temp;
        map[r][--c] = dice[2][1];

    }
    else
    {
        if (r - 1 < 0) return;

        //세로 아래 당김
        int temp = dice[3][1];
        for (int i = 3; i > 0; --i)
        {
            dice[i][1] = dice[i - 1][1];
        }
        dice[0][1] = temp;
        map[--r][c] = dice[2][1];

    }
    return;
}
int main() {
    cin >> n >> m >> r >> c;
    char dir;
    map[r][c] = 6;

    int idX = 1;
    int idY = 2;
    for (int i = 0; i < m; i++) {
        cin >> dir;
        shift(r, c, dir);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < n; ++k)
        {
            ans += map[i][k];
        }
    }

    cout << ans;
    // Please write your code here.

    return 0;
}
