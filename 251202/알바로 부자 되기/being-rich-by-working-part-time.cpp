#include <iostream>

using namespace std;

int N;
int s[1000], e[1000], p[1000];
long long int dp[1000];
int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> p[i];
        dp[i] = p[i];
    }


    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; ++j)
        {
            if (s[i] > e[j])
            {
                dp[i] = max(dp[i], dp[j] + p[i]);
            }
        }
    }

    long long int ansMax = -1;
    for (int i = 0; i < N; i++)
    {
        ansMax = max(dp[i], ansMax);
    }
    cout << ansMax;


    return 0;
}
