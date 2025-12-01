#include <iostream>
#include <climits>
using namespace std;

int n, m;
int grid[50][50];
int dp[50][50];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            dp[i][j] = INT_MIN;
        }
    }
    dp[0][0] = 1;
    // Please write your code here.

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < i; ++k)
            {
                for (int p = 0; p < j; ++p)
                {
                    if (dp[k][p] == INT_MIN) continue;
                    if (grid[i][j] > grid[k][p])
                    {
                        dp[i][j] = max(dp[i][j], dp[k][p] + 1);
                    }
                }
            }
        }
    }

    int ansMax = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ansMax = max(ansMax, dp[i][j]);
        }
    }



    cout << ansMax;


    return 0;
}
