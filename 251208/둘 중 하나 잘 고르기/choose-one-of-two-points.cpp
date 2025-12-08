#include <iostream>
#include <climits>

using namespace std;

int N;
int red[201];
int blue[201];
int dp[201][101];
int main() {
    cin >> N;

    for (int i = 1; i <= 2 * N; i++) {
        cin >> red[i] >> blue[i];
    }


    for (int i = 0; i < 2 * N; i++) {
        for (int k = 0; k <= N; ++k)
        {
            dp[i][k] = INT_MIN;
        }
    }

    dp[0][0] = 0;
    for (int i = 0; i < 2 * N; ++i)
    {
        for (int k = 0; k <= N; ++k)
        {
            if (dp[i][k] == INT_MIN) continue;
            {
                if(k == N) dp[i + 1][k] = max(dp[i + 1][k], dp[i][k] + blue[i + 1]);
                else {
                    dp[i + 1][k] = max(dp[i + 1][k], dp[i][k] + blue[i + 1]);
                    dp[i + 1][k + 1] = max(dp[i + 1][k + 1], dp[i][k] + red[i + 1]);
                }
                
            }
        }
    }
    cout << dp[2 * N][N];
    return 0;
}
