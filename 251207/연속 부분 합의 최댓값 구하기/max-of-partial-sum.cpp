#include <iostream>
#include <climits>
using namespace std;

int n;
long long int arr[100001];
long long int dp[100001];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    
    for(int i = 1; i <= n; i++)
        dp[i] = INT_MIN;
    dp[1] = arr[1];
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    }

    long long int ansMax = INT_MIN;
    for (int i = 1; i <= n; ++i)
    {
        ansMax = max(ansMax, dp[i]);
    }

    cout << ansMax;
    return 0;
}
