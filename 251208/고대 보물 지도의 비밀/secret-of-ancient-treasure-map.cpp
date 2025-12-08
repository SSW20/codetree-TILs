#include <iostream>
#include <climits>
using namespace std;

int n, k;
long long int numbers[100000];
long long int dp[100001][11];
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; ++j)
        {
            dp[i][k] = INT_MIN;
        }
    }

 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; ++j)
        {
            if (numbers[i + 1] < 0)
            {
                dp[i + 1][1] = max(dp[i + 1][1], numbers[i + 1]);
                if(j != k) dp[i + 1][j + 1] = numbers[i + 1] + dp[i][j];
                else dp[i + 1][1] = max(dp[i + 1][1], numbers[i + 1]);
            }
            else
            {
                dp[i + 1][j] = max(numbers[i + 1] + dp[i][j], numbers[i + 1]);
            }
        }
    }

    long long int ansMax = INT_MIN;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; ++j)
        {
            ansMax = max(ansMax, dp[i][j]);
        }
    }

    cout << ansMax;


    return 0;
}
