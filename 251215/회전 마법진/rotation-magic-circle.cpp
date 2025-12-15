#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
string a, b;
vector<int> origin;
vector<int> des;
int dp[10002][10];
int main() {
    cin >> N;
    cin >> a;
    cin >> b;
    origin.push_back(-1);
    des.push_back(-1);
    for (char c : a)
    {
        origin.push_back(c - '0');
    }
    for (char c : b)
    {
        des.push_back(c - '0');
    }

    for (int i = 0; i <= N; ++i)
    {
        for (int k = 0; k < 10; ++k)
        {
            dp[i][k] = INT_MAX;
         }
    }

    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i)
    {
        for (int k = 0; k < 10; ++k)
        {
            if (dp[i-1][k] == INT_MAX) continue;
            int start = (origin[i] + k) % 10;
            
            int clock = (start - des[i] + 10) % 10;
            int Rclock = (10 - clock) % 10;

            dp[i][k] = min(dp[i][k], dp[i - 1][k] + clock);
            dp[i][(k + Rclock) % 10] = min(dp[i][(k + Rclock) % 10], dp[i - 1][k] + Rclock);
        }
    }

    int ansMin = INT_MAX;

    for (int i = 0; i < 10; ++i)
    {
        ansMin =min(dp[N][i], ansMin);
    }

    cout << ansMin;
    return 0;

}
