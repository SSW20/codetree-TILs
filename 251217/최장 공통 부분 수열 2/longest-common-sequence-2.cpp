#include <iostream>
#include <string>

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
    for (int i = 1; i <= A.length(); ++i)
    {
        if(dp[i][B.length()] != dp[i - 1][B.length()]) cout << A[i - 1];
    }
    return 0;
}
