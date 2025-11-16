#include <iostream>
#include <climits>
using namespace std;

int N;
char grid[20][20];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ansMin = INT_MAX;
bool gFlag = false;

void FindPath(int r, int c, int cnt, int coin, int coinCount)
{
    if (cnt == N * N)
    {
        return;
    }
    if (grid[r][c] == 'E')
    {
        if (coinCount >= 3)
        {
            ansMin = min(ansMin, cnt);
            gFlag = true;
        }
        return;
    }

    for (int d = 0; d < 4; ++d)
    {
        int x = r + dx[d];
        int y = c + dy[d];

        if (x < 0 || y < 0 || x >= N || y >= N) continue;
        int num = grid[x][y] - '0';
        if (num <= 9 && num >= 1 && coin < num) FindPath(x, y, cnt + 1, num, coinCount + 1);
        else FindPath(x, y, cnt + 1, coin, coinCount);
    }
}


int main() {
    cin >> N;
    int r, c;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
            {
                r = i;
                c = j;
            }
        }

    // Please write your code here.

    FindPath(r, c, 0, -1, 0);
    if (gFlag) cout << ansMin;
    else cout << -1;
    return 0;
}
