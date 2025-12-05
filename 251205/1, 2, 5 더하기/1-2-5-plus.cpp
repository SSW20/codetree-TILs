#include <iostream>

using namespace std;

int n;
int dp[1001];
int main() {
    cin >> n;

    // Please write your code here.
    int arr[3] = { 1,2,5 };
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int k = 0; k < 3; ++k)
        {
            if (i >= arr[k])
            {
                dp[i] = (dp[i] + dp[i - arr[k]]) % 10007;
            }
        }
    }

    cout << dp[n];
    return 0;
}
