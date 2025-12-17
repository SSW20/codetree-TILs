#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string A, B;
int dp[1001][1001];
int main() {
    cin >> A;
    cin >> B;


    for (int i = 1; i <= A.length(); ++i)
    {
        for (int k = 1; k <= B.length(); ++k)
        {
            dp[i][k] = (A[i - 1] == B[k - 1] ? dp[i - 1][k - 1] + 1 : max(dp[i - 1][k], dp[i][k - 1]));
        }
    }
    int x = A.length();
    int y = B.length();

    string ans = "";

    while (x > 0 && y > 0)
    {
        if (A[x - 1] == B[y - 1])
        {
            ans += A[x - 1];
            --x;
            --y;
        }
        else if (dp[x][y] == dp[x][y-1])
        {
            y--;
        }
        else
        {
            x--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}
