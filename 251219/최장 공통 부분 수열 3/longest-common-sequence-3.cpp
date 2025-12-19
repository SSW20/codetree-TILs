#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int a[1001];
int b[1001];
pair<int,int> dp[1001][1001];
int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    vector<int> an;
    for (int i = 1; i <= n; ++i)
    {
        for (int k = 1; k <= m; ++k)
        {
            if (a[i] == b[k])
            {
                dp[i][k].first = dp[i - 1][k - 1].first + 1;
                dp[i][k].second = min(a[i],b[k]);
            }
            else
            {
                if (dp[i - 1][k].first > dp[i][k - 1].first)
                {
                    dp[i][k].first = dp[i - 1][k].first;
                    dp[i][k].second = dp[i - 1][k].second;
                }
                else
                {
                    dp[i][k].first = dp[i][k - 1].first;
                    dp[i][k].second = dp[i][k - 1].second;
                }
            }
        }
    }

    int x = n;
    int y = m;
    int idx = dp[x][y].first;
    vector<int> ans(idx);
    while (x > 0 && y > 0)
    {
        if (a[x] == b[y])
        {
            ans[--idx] = a[x];
            x--;
            y--;
        }
        else
        {
            if (dp[x][y].first == dp[x][y-1].first && dp[x][y].first == dp[x-1][y].first)
            {
                if (a[x] < b[y]) y--;
                else x--;
            }
            else if (dp[x][y].first == dp[x][y - 1].first || dp[x][y].first == dp[x - 1][y].first)
            {
                if (dp[x][y].first == dp[x][y - 1].first) y--;
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
