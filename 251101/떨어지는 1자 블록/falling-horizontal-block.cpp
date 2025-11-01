#include <iostream>

using namespace std;

int n, m, k;
int grid[100][100];
int temp[100];

void search()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[j][i] > 0) {
                temp[i] = j;
                break;
            }
        }
        if (temp[i] == 0) temp[i] = n;
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    search();
    int idx = 99;
    for (int i = k - 1; i < k - 1 + m; ++i)
    {
        if (idx > temp[i])
        {
            idx = temp[i];
        }
    }
    for (int i = k - 1; i < k - 1 + m; ++i)
    {
        grid[idx - 1][i] = 1;
    }
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout<< grid[i][j] << ' ';
        }
        cout << '\n';
    }
    // Please write your code here.

    return 0;
}
