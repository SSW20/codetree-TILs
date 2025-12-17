    #include <iostream>
    #include <string>
#include <set>
    using namespace std;

    string S, P;
    bool dp[1001][1001];
    set<char> aster;
    int main() {
        cin >> S;
        cin >> P;

        dp[0][0] = true;

        for (int j = 2; j <= P.length(); j++) {
            if (P[j - 1] == '*') {
                aster.insert(P[j - 2]);
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= S.length(); ++i)   
        {
            for (int k = 1; k <= P.length(); ++k)
            {
                if (S[i - 1] == P[k - 1] || P[k - 1] == '.')
                {
                    dp[i][k] = dp[i-1][k-1];
                }
                else
                {
                    if (P[k - 1] == '*')
                    {
                        dp[i][k] = dp[i][k - 2];
                        if (S[i - 1] == P[k - 2] || P[k - 2] == '.')
                        {
                            dp[i][k] = dp[i][k] || dp[i - 1][k];
                        }
                    }
                }
            }
        }

        if (dp[S.length()][P.length()]) cout << "true";
        else cout << "false";
        return 0;
    }
