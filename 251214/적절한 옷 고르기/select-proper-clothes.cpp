#include <iostream>
#include <climits>
using namespace std;

int N, M;
int s[201], e[201], v[201];
int dp[201][201];
int main() {
    cin >> N >> M;

    for (int i = 0; i <= M; ++i)
    {
        for (int k = 0; k <= N; ++k)
        {
            dp[i][k] = INT_MIN;
        }
    }

    for (int i = 1; i <= N; i++) {
        cin >> s[i] >> e[i] >> v[i];
        if (s[i] == 1)
        {
            dp[1][i] = 0;
        }
    }

    
    dp[1][0] = 0;

    for (int i = 1; i <= M; ++i)
    {
        for (int k = 1; k <= N; ++k)
        {
            int start = s[k];
            int end = e[k];
            if (start > i || end < i) continue;

            for (int j = 1; j <= N; ++j)
            {
                if (dp[i-1][j] == INT_MIN) continue;
                dp[i][k] = max(dp[i][k], dp[i - 1][j] + abs(v[k] - v[j]));
            }
        }
    }

    int ansMax = -1;

    for (int i = 1; i <= M; ++i)
    {
        for (int k = 1; k <= N; ++k)
        {
            ansMax = max(ansMax, dp[i][k]);
        }
    }

    cout << ansMax;

    return 0;
}
