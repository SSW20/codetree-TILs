#include <iostream>

using namespace std;

int n;
int a[1001];
int b[1001];
int dp[1001][1001];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) dp[i][j] = -1;

    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == -1) continue;
            if (a[i + 1] < b[j + 1])
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

            if (a[i + 1] > b[j + 1])
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + b[j + 1]);
                
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, dp[i][n]);
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
    return 0;
}
