#include <iostream>

using namespace std;

int n;
int grid[10][10];
int visited[10];
int ansMax = -1;
void Select(int row, int total)
{
    if (row == n)
    {
        ansMax = max(ansMax, total);
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == 1) continue;
        visited[i] = 1;
        if (total > grid[row][i]) total = grid[row][i];
        Select(row + 1,total);
        visited[i] = 0;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    Select(0, 1000000);
    cout << ansMax;
    // Please write your code here.

    return 0;
}
