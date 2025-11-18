#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[10][10];
int visited[10];
vector<int> v;
int ansMax = -1;
void Select(int row)
{
    if (row == n)
    {
        sort(v.begin(), v.end());
        ansMax = max(ansMax, v[0]);
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == 1) continue;
        visited[i] = 1;
        v.push_back(grid[row][i]);
        Select(row + 1);
        visited[i] = 0;
        v.pop_back();

    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    Select(0);
    cout << ansMax;
    // Please write your code here.

    return 0;
}
