#include <iostream>

using namespace std;

int n;
int dp[1001][10];
int main() {
    cin >> n;

    
    for (int i = 1; i <= 9; ++i)
    {
        dp[1][i] = 1;
    }
   


    for (int i = 2; i <= n; ++i)
    {
        for (int k = 0; k <= 9; ++k)
        {
            for (int j = 0; j <= 9; ++j)
            {
                if (abs(k - j) == 1)
                {
                    dp[i][k] = (dp[i][k] + dp[i - 1][j]) % 1000000007;
                }
            }
        }
    }


    int ans = 0;
    for (int i = 0; i < 10; ++i)
    {
        ans = (ans + dp[n][i]) % 1000000007;
    }

    
    cout << ans;
    return 0;
}
