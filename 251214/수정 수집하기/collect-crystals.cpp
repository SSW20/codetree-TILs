#include <iostream>
#include <climits>
using namespace std;

int n, k;
int dp[1001][21][2];
int map[1001];

int main() {
    cin >> n >> k;
    char c;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        if (c == 'L') map[i] = 0;
        else map[i] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            for (int t = 0; t <= 1; ++t)
            {
                dp[i][j][t] = INT_MIN;
            }
        }
    }

    if (map[1] == 0)
    {
        dp[1][0][0] = 1;
        dp[1][1][1] = 0;
    }
    else
    {
        dp[1][0][0] = 0;
        dp[1][1][1] = 1;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            for (int t = 0; t <= 1; ++t)
            {
                if (dp[i][j][t] == INT_MIN) continue;
                if (j < k)
                {
                    if (map[i + 1] == t)
                    {
                        dp[i + 1][j][t] = max(dp[i + 1][j][t], dp[i][j][t] + 1);
                        dp[i + 1][j + 1][(t + 1) % 2] = max(dp[i + 1][j + 1][(t + 1) % 2], dp[i][j][t]);
                    }
                    else
                    {
                         dp[i + 1][j][t] = max(dp[i + 1][j][t], dp[i][j][t]);
                        dp[i + 1][j + 1][(t + 1) % 2] = max(dp[i + 1][j + 1][(t + 1) % 2], dp[i][j][t] + 1);
                    }
                }
                else
                {
                    if (map[i + 1] == t) dp[i + 1][j][t] = max(dp[i + 1][j][t], dp[i][j][t] + 1);
                    else dp[i + 1][j][t] = max(dp[i + 1][j][t], dp[i][j][t]);
                }
            }
        }
    }

    int ansMax = -1;
    for (int i = 0; i <= k; ++i)
    {
        for (int j = 0; j <= 1; ++j)
            ansMax = max(ansMax, dp[n][i][j]);
    }

    cout << ansMax;
}

