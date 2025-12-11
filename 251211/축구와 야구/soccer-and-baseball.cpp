#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
vector<pair<int, int>> v;
long long dp[12][10];

int main() {
    cin >> n;
    int s, b;
    for (int i = 0; i < n; i++) {
        cin >> s >> b;
        v.push_back({ s,b });
    }

    for (int i = 0; i < 12; i++) {
        for (int k = 0; k < 10; ++k)
        {
            dp[i][k] = INT_MIN;
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i < n; ++i)
    {
        int cur_socc = v[i].first;
        int cur_base = v[i].second;

        for (int j = 11; j > -1; --j)
        {
            for (int k = 9; k > -1; --k)
            {
                if (dp[j][k] == INT_MIN) continue;
                
                if (j < 11)
                {
                    dp[j + 1][k] = max(dp[j + 1][k], dp[j][k] + cur_socc);
                }
                if (k < 9)
                {
                    dp[j][k + 1] = max(dp[j][k + 1], dp[j][k] + cur_base);
                }
            }
        }
    }
    cout << dp[11][9];
    return 0;
}
