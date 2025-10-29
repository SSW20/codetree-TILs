#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[100][100];
int r, c, m1, m2, m3, m4, dir;
int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;
    vector<int> v;
    int x = r - 1;
    int y = c - 1;
    for (int i = 0; i < m1; ++i)
    {
        v.push_back(grid[x][y]);
        x--; y++;
    }
 
    for (int i = 0; i < m2; ++i)
    {
        v.push_back(grid[x][y]);
        x--; y--;
    }
  
    for (int i = 0; i < m3; ++i)
    {
        v.push_back(grid[x][y]);
        x++; y--;
    }
  
    for (int i = 0; i < m4; ++i)
    {
        v.push_back(grid[x][y]);
        x++; y++;
    }
    if (dir == 0)
    {
        // 오른쪽 shift
        int temp = v[v.size() - 1];
        for (int i = v.size() - 1; i > 0; --i)
        {
            v[i] = v[i - 1];
        }
        v[0] = temp;
    }
    else
    {
        int temp = v[0];
        for (int i = 0; i < v.size() - 1; ++i)
        {
            v[i] = v[i + 1];
        }
        v[v.size()-1] = temp;
    }
    x = r - 1;
    y = c - 1;

    int idx = 0;
    for (int i = 0; i < m1; ++i)
    {
        grid[x][y] = v[idx];
        x--; y++; ++idx;
    }
    for (int i = 0; i < m2; ++i)
    {
        grid[x][y] = v[idx];
        x--; y--; ++idx;
    }
  
    for (int i = 0; i < m3; ++i)
    {
        grid[x][y] = v[idx];
        x++; y--; ++idx;
    }
   
    for (int i = 0; i < m4; ++i)
    {
        grid[x][y] = v[idx];
        x++; y++; ++idx;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cout << grid[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
