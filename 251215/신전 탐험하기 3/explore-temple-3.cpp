#include <iostream>

using namespace std;

int n,m;
int dp[1001][101];
int map[1005][101];

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }


    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int k = 1; k <= m; ++k)
            {
                if (j != k)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + map[i][j]);
                }
            }
        }
    }

    int ansMax = -1;
    for (int i = 1; i <= m; ++i)
    {
        ansMax = max(ansMax, dp[n][i]);
    }

    cout << ansMax;
}
