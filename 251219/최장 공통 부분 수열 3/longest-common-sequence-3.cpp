#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int a[1001];
int b[1001];
int dp[1001][1001];
int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int k = 1; k <= m; ++k)
        {
            if (a[i] == b[k]) dp[i][k] = dp[i - 1][k - 1] + 1;
            else dp[i][k] = max(dp[i - 1][k], dp[i][k - 1]);
        }
    }

    int x = n;
    int y = m;
    int idx = dp[x][y];
    vector<int> ans(dp[x][y]);
    while (x > 0 && y > 0 && idx > -1)
    {
        if (a[x] == b[y])
        {
            ans[--idx] = a[x];
            x--;
            y--;
        }
        else
        {
            if (dp[x][y] == dp[x][y-1] && dp[x][y] == dp[x-1][y])
            {
                if (a[x] < b[y]) y--;
                else x--;
            }
            else if (dp[x][y] == dp[x][y - 1] || dp[x][y] == dp[x - 1][y])
            {
                if (dp[x][y] == dp[x][y - 1]) y--;
                else x--;
            }
        }
    }
    for (int t : ans)
    {
        cout << t << ' ';
    }


    return 0;
}
