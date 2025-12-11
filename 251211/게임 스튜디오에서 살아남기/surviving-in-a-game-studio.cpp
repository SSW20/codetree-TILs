#include <iostream>

using namespace std;

int N;
long long int dp[1001][3][3];
int main() {
    cin >> N;

    dp[0][0][0] = 0;
    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    dp[1][0][1] = 1;

    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                if (dp[i][j][k] == 0) continue;

                // G
                dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][k]) % 1000000007;
                
                // T
                if (j + 1 < 3)  dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + dp[i][j][k]) % 1000000007;
                // B

                if (k + 1 < 3) dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] + dp[i][j][k]) % 1000000007;
            }
        }
    }

    long long int ans = 0;
    for (int j = 0; j < 3; ++j)
    {
        for (int k = 0; k < 3; ++k)
        {
            ans = (ans + dp[N][j][k]) % 1000000007;
        }
    }
    cout << ans;

    return 0;
}
