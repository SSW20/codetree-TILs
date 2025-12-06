#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr[100];
int dp[100001];
int main() {
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    // Please write your code here.
    for (int k = 0; k < n; ++k) {

        for (int i = total; i > -1; --i)
        {
            if (i >= arr[k])
            {
                dp[i] = max(dp[i], dp[i - arr[k]] + 1);
            }
        }
    }

    int ansMin = 10000001;
    for (int i = 1; i <= total; ++i)
    {
        if (dp[i] != 0)
        {
            ansMin = min(ansMin, abs(i - (total - i)));
        }
    }

    cout << ansMin;
    return 0;
}
