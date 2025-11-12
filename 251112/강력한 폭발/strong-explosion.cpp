#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[20][20];
int gMax = -1;
vector<pair<int, int>> v;

int dx[3][5] = { {-2,-1,0,1,2 },
                {-1,0,0,1,0},
                {-1,-1,0,1,1} };
int dy[3][5] = { {0,0,0,0,0 },
                {0,1,0,0,-1},
                {-1,1,0,1,-1} };

void Calculate(int idx, int count)
{
    if (idx == v.size()) { if (count > gMax) gMax = count; return; }
    int r = v[idx].first;
    int c = v[idx].second;
    for (int i = 0; i < 3; ++i)
    {
        int ans = 0;
        for (int k = 0; k < 5; ++k)
        {
            int x = r + dx[i][k];
            int y = c + dy[i][k];
            if (x < 0 || y < 0 || x >= n || y >= n) continue;
            if (grid[x][y] == 0) { ++ans; grid[x][y]++; }
            else grid[x][y]++;
        }
        Calculate(idx + 1, count + ans);

        for (int k = 0; k < 5; ++k)
        {
            int x = r + dx[i][k];
            int y = c + dy[i][k];
            if (x < 0 || y < 0 || x >= n || y >= n) continue;
            if (grid[x][y] > 0) { grid[x][y]--; }
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1)
            {
                v.push_back(make_pair(i, j));
            }
        }
    }

    // Please write your code here.
    Calculate(0, 0);
    cout << gMax + v.size();
    return 0;
}
