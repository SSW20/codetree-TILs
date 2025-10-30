#include <iostream>

using namespace std;

int n;
int grid[50][50];
int gridtemp[50][50];
int temp[50][50];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void copy()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            gridtemp[i][j] = grid[i][j];
        }
    }
}
void clear()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            gridtemp[i][j] = temp[i][j];
            temp[i][j] = 0;
        }
    }
}
void gravity()
{
    for (int i = 0; i < n; i++)
    {
        int idx = n - 1;
        for (int j = n - 1; j > -1; j--)
        {
            if (gridtemp[j][i] != 0) temp[idx--][i] = gridtemp[j][i];
        }
    }
    clear();
}
int search()
{
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (gridtemp[i][j] == 0) continue;
            if (i + 1 < n && gridtemp[i][j] == gridtemp[i + 1][j]) ++count;
            if (j + 1 < n && gridtemp[i][j] == gridtemp[i][j + 1]) ++count;
        }
    }
    copy();
    return count;
}
int bomb(int r, int c)
{
    int count = grid[r][c];
    for (int i = 0; i < count; ++i)
    {
        for (int d = 0; d < 4; ++d)
        {
            int x = r + dx[d] * i;
            int y = c + dy[d] * i;
            if (x < 0 || y < 0 || x >= n || y >= n) continue;
            gridtemp[x][y] = 0;
        }
    }
    gravity();
    return search();
}



int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            gridtemp[i][j] = grid[i][j];
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            ans = max(ans, bomb(i, j));
        }
    }
    cout << ans;
    // Please write your code here.

    return 0;
}
