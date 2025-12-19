#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int a[1002];
int b[1002];
int dp[1001][1001];
int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    for (int i = n; i > 0; --i)
    {
        for (int k = m; k > 0; --k)
        {
            if (a[i] == b[k]) dp[i][k] = dp[i + 1][k + 1] + 1;
            else dp[i][k] = max(dp[i + 1][k], dp[i][k + 1]);
        }
    }

    int curX = 1;
    int curY = 1;

    int len = dp[1][1];
    for (int i = len; i > 0; --i)
    {
        int minVal = 1001;
        int nextX = -1;
        int nextY = -1;

        for (int k = curX; k <= n; ++k)
        {
            if (a[k] < minVal)
            {
                for (int j = curY; j <= m; ++j)
                {
                    if (a[k] == b[j])
                    {
                        if (dp[k][j] == i)
                        {
                            minVal = a[k];
                            nextX = k;
                            nextY = j;
                        }
                        break;
                    }
                }
            }
        }

        cout << minVal << ' ';
        curX = nextX + 1;
        curY = nextY + 1;
    }


    return 0;
}
