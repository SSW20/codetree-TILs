#include <iostream>
#include <climits>
using namespace std;

int N, M;
int a[501];
int dp[501][101][5];

int Calc(int i,  int k)
{
    return (a[i] == k ? 1 : 0);
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int k = 0; k <= M; ++k)
        {
            for (int j = 1; j <= 4; ++j)
            {
                dp[i][k][j] = INT_MIN;
            }
        }
    }

    for (int i = 1; i <= 4; ++i)
    {
        if (a[1] == i)
        {
            dp[1][0][i] = 1;
        }
        else
        {
            dp[1][0][i] = 0;
        }
    }

    for (int i = 1; i < N; ++i)
    {
        for (int k = 0; k <= M; ++k)
        {
            for (int j = 1; j <= 4; ++j)
            {
                if (dp[i][k][j] == INT_MIN) continue;
                for (int t = 1; t <= 4; ++t)
                {
                    if (k == M)
                    {
                        if (t == j)
                        {
                            dp[i + 1][k][t] = max(dp[i + 1][k][t], dp[i][k][j] + Calc(i, t));
                        }
                    }
                    else
                    {
                        if (t == j)
                        {
                            dp[i + 1][k][t] = max(dp[i + 1][k][t], dp[i][k][j] + Calc(i, t));
                        }
                        else
                        {
                            dp[i + 1][k + 1][t] = max(dp[i + 1][k + 1][t], dp[i][k][j] + Calc(i, t));
                        }
                    }
                }
            }
        }
    }

    int ansMax = -1;

    for (int i = 0; i <= M; ++i)
    {
        for (int k = 1; k <= 4; ++k)
        {
            ansMax = max(ansMax, dp[N][i][k]);
        }
    }
    cout << ansMax;

    return 0;
}
