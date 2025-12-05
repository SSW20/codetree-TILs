#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
int coin[100];
int dp[10001];
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> coin[i];

    }

    for (int i = 0; i <= M; i++)
    {
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
    // Please write your code here.
    for (int i = 1; i <= M; ++i)
    {
        for (int k = 0; k < N; ++k)
        {
            if (i >= coin[k])
            {
                if (dp[i - coin[k]] == INT_MIN) continue;
                dp[i] = max(dp[i], dp[i - coin[k]] + 1);
            }
        }
    }

    if (dp[M] == INT_MIN) cout << -1;
    else cout << dp[M];

    return 0;
}
