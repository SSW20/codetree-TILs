#include <iostream>
#include <climits>
using namespace std;

int N, M;
int coin[100];
int dp[101];
int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    for (int i = 0; i <= M; ++i) {
        dp[i] = 100001; 
    }
    dp[0] = 0;
    for (int i = 1; i <= M; ++i)
    {
        for (int k = 0; k < N; ++k)
        {
            if (i >= coin[k])
            {
                dp[i] = min(dp[i], dp[i - coin[k]] + 1);
            }
        }
    }

    cout << dp[M];

    return 0;
}
