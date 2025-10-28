#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int N, M;
int grid[20][20];
int ux, uy, dx, dy;

bool rec1(int i, int j, int k, int p)
{
    for (int x = i; x < i + k; ++x)
    {
        for (int y = j; y < j + p; ++y)
        {
            if (x < 0 || y < 0 || x >= N || y >= M) {  return false; };
            if ( grid[x][y] <= 0) return false;
        }
    }
    return true;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.

    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                for (int p = 1; p <= M; p++)
                {
                    if (rec1(i, j, k, p))
                    {
                        ans = max(ans, k * p);
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}
