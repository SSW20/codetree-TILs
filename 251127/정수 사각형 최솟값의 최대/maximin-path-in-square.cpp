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


    int rowMin = grid[0][0];
    for (int i = 1; i < n; i++)
    {
        rowMin = min(rowMin, grid[0][i]);
        ans[0][i] = rowMin;
    }

    int colMin = grid[0][0];
    for (int i = 1; i < n; i++)
    {
        colMin = min(colMin, grid[i][0]);
        ans[i][0] = colMin;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(grid[i][j] > max(ans[i - 1][j], ans[i][j - 1]))
            {
                ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
            }
            else
            {
               ans[i][j] = grid[i][j];
            }
        }
    }
    cout << ans[n - 1][n - 1];

    return 0;
}
