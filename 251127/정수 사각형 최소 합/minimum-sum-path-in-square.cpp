#include <iostream>

using namespace std;

int n;
int grid[100][100];
int ans[100][100];
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    ans[0][n-1] = grid[0][n-1];
    if (n == 1) cout << grid[0][0];
    else
    {
        for (int i = n - 2; i >= 0; --i)
        {
            ans[0][i] = ans[0][i + 1] + grid[0][i];
        }

        for (int i = 1; i < n; ++i)
        {
            ans[i][n - 1] = ans[i - 1][n - 1] + grid[i][n - 1];
        }

        for (int i = 1; i < n; ++i)
        {
            for (int k = n - 2; k >= 0; --k)
            {
                ans[i][k] = min(ans[i - 1][k], ans[i][k + 1]) + grid[i][k];
            }
        }
        cout << ans[n - 1][0];
    }
    return 0;
}
