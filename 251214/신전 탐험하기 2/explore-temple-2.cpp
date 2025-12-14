#include <iostream>

using namespace std;

int n;
int dp[1001][4];
int dir[1001][4];

int map[1001][4];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> map[i][1] >> map[i][2] >> map[i][3];
    }
    dir[1][1] = 1;
    dir[1][2] = 2;
    dir[1][3] = 3;
    
    dp[1][1] = map[1][1];
    dp[1][2] = map[1][2];
    dp[1][3] = map[1][3];

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            for (int k = 1; k <= 3; ++k)
            {
                if (j != k)
                {
                    if (i == n && dir[i - 1][k] == j) continue;
                    if (dp[i][j] < dp[i - 1][k] + map[i][j])
                    {
                        dir[i][j] = dir[i - 1][k];
                    }
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + map[i][j]);
                }
            }
        }
    }

    int ansMax = -1;
    for (int i = 0; i < 4; ++i)
    {
        ansMax = max(ansMax, dp[n][i]);
    }

    cout << ansMax;
}
