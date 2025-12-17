    #include <iostream>
    #include <string>

    using namespace std;

    string A, B;
    int dp[1001][1001];
    int main() {
        cin >> A;
        cin >> B;
    
        for (int i = 0; i <= A.length(); i++) dp[i][0] = i;
        for (int j = 0; j <= B.length(); j++) dp[0][j] = j;

        for (int i = 1; i <= A.length(); ++i)
        {
            for (int k = 1; k <= B.length(); ++k)
            {
                if (A[i-1] != B[k- 1])
                {
                    dp[i][k] = min(dp[i - 1][k], dp[i][k - 1]) + 1;
                }
                else
                {
                    dp[i][k] = dp[i - 1][k - 1];
                }
            }
        }

        cout << dp[A.length()][B.length()];
        return 0;
    }
