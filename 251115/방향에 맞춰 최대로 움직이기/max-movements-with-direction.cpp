#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[4][4];
int gridDir[4][4];
pair<int, int> dir[8] = { {-1,0}, {-1,1}, {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
int r, c;
int countMax = -1;

bool Possible(int r, int c)
{
    for (int i = 1; i < 4; ++i)
    {
        int x = r + dir[gridDir[r][c]].first * i;
        int y = c + dir[gridDir[r][c]].second * i;
        if (x < 0 || y < 0 || x >= n || y >= n) continue;
        if (grid[x][y] > grid[r][c]) return true;
    }
    return false;
}

void Path(int r, int c, int cnt)
{
    if (!Possible(r,c))
    {
        countMax = max(countMax, cnt);
        return;
    }

    for (int i = 1; i < 4; ++i)
    {
        int x = r + dir[gridDir[r][c]].first * i;
        int y = c + dir[gridDir[r][c]].second * i;
        if (x < 0 || y < 0 || x >= n || y >= n) continue;
        if (grid[x][y] > grid[r][c])
        {
            Path(x, y, cnt + 1);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            gridDir[i][j] = x - 1;
        }


    cin >> r >> c;
    Path(r - 1, c - 1, 0);  

    cout << countMax;
    // Please write your code here.

    return 0;
}
