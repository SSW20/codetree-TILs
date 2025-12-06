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


    for (int i = 1; i <= M; ++i)
    {
        for (int k = 0; k < N; ++k)
        {
            if (i >= vec[k].first)
            {
                dp[i] = max(dp[i], dp[i - vec[k].first] + vec[k].second);
            }
        }
    }

    cout << dp[M];
    return 0;
}
