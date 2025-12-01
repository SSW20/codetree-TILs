#include <iostream>

using namespace std;

int N;
int M[1000];
int dp[1000];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }
    dp[0] = 1;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; ++j)
        {
            if (M[j] < M[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ansMax = -1;
    for (int i = 0; i < N; ++i)
    {
        ansMax = max(ansMax, dp[i]);
    }

    cout << ansMax;
    

    return 0;
}
