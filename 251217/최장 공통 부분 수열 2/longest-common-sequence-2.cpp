#include <iostream>
#include <string>

using namespace std;

string A, B;
pair<int,string> dp[1001][1001];
int main() {
    cin >> A;
    cin >> B;


    for (int i = 1; i <= A.length(); ++i)
    {
        for (int k = 1; k <= B.length(); ++k)
        {
            if(A[i - 1] == B[k - 1])
            {
                dp[i][k] = { dp[i - 1][k - 1].first + 1, dp[i - 1][k - 1].second + A[i - 1] };
            }
            else
            {
                if (dp[i - 1][k].first > dp[i][k - 1].first)
                {
                    dp[i][k] = { dp[i - 1][k].first, dp[i - 1][k].second };
                }
                else
                {
                    dp[i][k] = { dp[i][k - 1].first, dp[i][k - 1].second };
                }
            }
        }
    }
    cout << dp[A.length()][B.length()].second;
    return 0;
}
