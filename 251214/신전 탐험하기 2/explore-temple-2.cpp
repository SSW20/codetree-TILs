#include <iostream>
#include <climits>
using namespace std;

int n;
int dp[1001][4][4];
int map[1001][4];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> map[i][1] >> map[i][2] >> map[i][3];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            for (int k = 1; k <= 3; ++k)
            {
                dp[i][j][k] = INT_MIN;
            }
        }
    }
    for (int j = 1; j <= 3; ++j)
    {
        for (int k = 1; k <= 3; ++k)
        {
            dp[0][j][k] = 0;
        }
    }



    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            for (int t = 1; t <= 3; ++t)
            {
                for (int k = 1; k <= 3; ++k)
                {
                    if (j != k)
                    {

                            if (dp[i - 1][k][t] == INT_MIN) continue;
                            if (i == n && t == j) continue;
                            dp[i][j][t] = max(dp[i][j][t], dp[i - 1][k][t] + map[i][j]);
                    }
                }
            }
        }
    }

    int ansMax = -1;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 1; j <= 3; ++j)
            ansMax = max(ansMax, dp[n][i][j]);
    }

    cout << ansMax;
}

