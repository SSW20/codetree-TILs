#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, int>> vec;
int dp[10001];
int main() {
    cin >> N >> M;
    int w, v;
    for (int i = 0; i < N; i++) {
        cin >> w >> v;
        vec.push_back({ w,v });
    }


    for (int i = 0; i < N; ++i)
    {
        for (int k = M; k > -1; --k)
        {
            if (k >= vec[i].first)
            {
                dp[k] = max(dp[k],  dp[k - vec[i].first] + vec[i].second);
            }
        }
    }

    cout << dp[M];
    return 0;
}
