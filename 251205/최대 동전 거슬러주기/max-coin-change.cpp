#include <iostream>
#include <algorithm>
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
        dp[i] = -10;
    }
    dp[0] = 0;
    // Please write your code here.
    for (int i = 1; i <= M; ++i)
    {
        for (int k = 0; k < N; ++k)
        {
            if(dp[k] == -1) continue;
            if (i >= coin[k])
            {
                dp[i] = max(dp[i], dp[i - coin[k]] + 1);
            }
        }
    }

    if (dp[M] == -10) cout << -1;
    else cout << dp[M];

    return 0;
}
