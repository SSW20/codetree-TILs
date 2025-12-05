#include <iostream>

using namespace std;

int n, m;
int A[100];
int dp[10001];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i <= m; ++i)
    {
        dp[i] = 100001;
    }
    dp[0] = 0;

    
    
        for (int k = 0; k < n; ++k)
        {
            for (int i = m; i > -1; --i)
            {   
            if (i >= A[k])
            {
                if (dp[i - A[k]] == 100001) continue;
                else
                {
                    dp[i] = min(dp[i], dp[i - A[k]] + 1);
                }
            }
        }
    }

    if (dp[m] == 100001) cout << "No";
    else cout << "Yes";
    return 0;
}
