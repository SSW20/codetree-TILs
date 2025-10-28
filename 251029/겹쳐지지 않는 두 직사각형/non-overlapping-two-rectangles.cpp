#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int N, M;
int grid[20][20];
int ux, uy, dx, dy;

bool flag = true;
int rec1(int i, int j, int k, int p)
{
    int ans = 0;
    for (int x = i; x < i + k; ++x)
    {
        for (int y = j; y < j + p; ++y)
        {
            if (x < 0 || y < 0 || x >= N || y >= M) { flag = false; return INT_MIN; };
            ans += grid[x][y];
        }
    }
    ux = i;
    uy = j;
    dx = i + k -1;
    dy = j + p - 1;
    return ans;
}

int rec2(int i, int j, int k, int p)
{
    int x = i;
    int y = j;
    int ans = 0;
    if (!(x > dx || y > dy || x + k - 1 < ux || y + p - 1 < uy)) {
        return INT_MIN;
    };

    for (int x = i; x < i + k; ++x)
    {
        for (int y = j; y < j + p; ++y)
        {
            if (x < 0 || y < 0 || x >= N || y >= M) { return INT_MIN; };
            ans += grid[x][y];
        }
    }
    flag = true;
    return ans;
}
int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.

    int ans = -INT_MAX;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int count = 0;
            for (int k = 1; k <= N; k++)
            {
                for (int p = 1; p <= M; p++)
                {
                    int temp = rec1(i, j, k, p);
                    if (temp == INT_MIN) continue;
                    for (int z = 0; z < N; z++)
                    {
                        for (int w = 0; w < M; w++)
                        {
                            for (int x = 1; x <= N; x++)
                            {
                                for (int y = 1; y <= M; y++)
                                {
                                    int count = rec2(z, w, x, y);
                                    if (count != INT_MIN) ans = max(ans, temp + count);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}
