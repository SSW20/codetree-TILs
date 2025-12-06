#include <iostream>

using namespace std;

int n;
int profit[101];
int dp[101];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> profit[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int k = 0; k < n; k++)
        {
            if (i >= k)
            {
                dp[i] = max(dp[i], dp[i - k] + profit[k]);
            }
        }
    }

    cout << dp[n];
    return 0;
}
