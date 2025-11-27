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
    ans[0][0] = grid[0][0];

    for (int i = 1; i < n; ++i)
    {
        ans[i][0] = ans[i-1][0] + grid[i][0];
        ans[0][i] = ans[0][i-1] + grid[0][i];
    }

    for (int i = 1; i < n; ++i)
    {
        for (int k = 1; k < n; ++k)
        {
            ans[i][k] = max(ans[i - 1][k], ans[i][k - 1]) + grid[i][k];
        }
    }

    cout << ans[n - 1][n - 1];



    return 0;
}
