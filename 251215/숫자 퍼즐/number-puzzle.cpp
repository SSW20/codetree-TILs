#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int dp[11][201][201];
vector<int> ans;
int main() {
    cin >> n >> m >> k;

    // Please write your code here.

    for (int i = 1; i <= m; ++i)
    {
        dp[1][i][i] = 1;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int k = 1; k <= m; ++k)
        {
            for (int t = 1; t <= m; ++t)
            {
                if (dp[i][k][t] == 0)  continue;
                for (int j = t; j <= m; ++j)
                {
                    if (k + j > m) break;
                    dp[i + 1][k + j][j] += dp[i][k][t];
                }
            }
        }
    }


    // 최종 결과를 계산하고 출력합니다.
    int cur_l = 1;
    int cur_m = m;
    for (int i = n; i >= 1; i--) {
        while (dp[i][cur_m][cur_l] < k) {
            k -= dp[i][cur_m][cur_l];
            cur_l++;
        }

        ans.push_back(cur_l);
        cur_m -= cur_l;
        cur_l = 1;
    }
    reverse(ans.begin(),ans.end());
    for (int x : ans)
    {
        cout << x << ' ';
    }
    return 0;
}
