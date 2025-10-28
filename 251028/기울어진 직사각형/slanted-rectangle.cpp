#include <iostream>
#include <cmath>
using namespace std;

int N;
int grid[20][20];
int dx[4] = { -1, 1, 1, -1 };
int dy[4] = { 1, 1, -1, -1 };

int answer(int i, int j, int k, int p)
{
    int x = j;
    int y = i;
    int move[4] = { k,p,k,p };
    int ans = 0;
    for (int idx = 0; idx < 4; ++idx)
    {
        for (int length = 0; length < move[idx]; ++length)
        {
            x += dx[idx];
            y += dy[idx];

            if (x < 0 || x >= N || y < 0 || y >= N) return 0;
            ans += grid[y][x];
        }
    }
    return ans;
}


int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.

    int ans = -1;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                for (int p = 1; p <= N; p++)
                {
                    ans = max(ans, answer(i, j, k, p));
                }
            }
        }
    }

    cout << ans;
    return 0;
}
