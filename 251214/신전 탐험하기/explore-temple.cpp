#include <iostream>

using namespace std;

int n;
int dp[1001][4];

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
                if (j != k)
                {
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
