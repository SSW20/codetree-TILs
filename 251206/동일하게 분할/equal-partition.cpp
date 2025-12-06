#include <iostream>

using namespace std;

int n;
int arr[100];
bool dp[100001];
int main() {
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    if (total % 2 != 0)
    {
        cout << "No"; return 0;
    }
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int k = total; k > -1; k--)
        {
            if (k >= arr[i])
            {
                if (dp[k - arr[i]] == true) dp[k] = true;
            }
        }
    }

    bool flag = false;
    for (int i = 0; i <= total; ++i)
    {
        if (dp[i] == true)
        {
            if (total % 2 == i)
            {
                flag = true;
                break;
            }
        }
    }

    if (flag) cout << "Yes";
    else cout << "No";

    return 0;
}
