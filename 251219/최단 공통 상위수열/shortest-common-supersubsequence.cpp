#include <iostream>

using namespace std;

string s;
string t;
int dp[1001][1001];
int main() {
    cin >> s;
    cin >> t;

    int n = s.length();
    int m = t.length();

    for (int i = 1; i <= n; ++i)
    {
        dp[0][i] = dp[0][i - 1] + 1;
    }

    for (int i = 1; i <= m; ++i)
    {
        dp[i][0] = dp[i-1][0] + 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int k = 1; k <= m; ++k)
        {
            if (s[i - 1] == t[k - 1])
            {
                dp[i][k] = dp[i - 1][k - 1] + 1;
            }
            else
            {
                dp[i][k] = min(dp[i - 1][k], dp[i][k - 1]) + 1;
            }
        }
    }

    cout << dp[n][m];
    return 0;
}
