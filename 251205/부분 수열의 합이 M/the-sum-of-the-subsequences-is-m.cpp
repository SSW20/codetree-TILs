#include <iostream>
#include <climits>
using namespace std;

int n, m;
int A[100];
int dp[10001];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i <= m; ++i)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int k = m; k  > -1; --k)
        {
            if (k >= A[i])
            {
                if (dp[k - A[i]] == INT_MAX) continue;
                dp[k] = min(dp[k], dp[k - A[i]] + 1);
            }
        }
    }


    if (dp[m] == INT_MAX) cout << -1;
    else cout << dp[m];
    return 0;
}
