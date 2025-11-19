#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[25][25];
bool visited[25][25];
vector<int> towns;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void FindTown(int r, int c, int& people)
{
    visited[r][c] = 1;
    people++;

    for (int d = 0; d < 4; ++d)
    {
        int x = r + dx[d];
        int y = c + dy[d];

        if (x < 0 || y < 0 || x >= n || y >= n) continue;
        if (visited[x][y] == true || grid[x][y] == 0) continue;
        FindTown(x, y, people);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (visited[i][j] == false && grid[i][j] == 1)
            {
                int people = 0;
                FindTown(i, j, people);
                towns.push_back(people);
            }
        }
    }
    sort(towns.begin(), towns.end());

    cout << towns.size() << '\n';
    for (int x : towns)
    {
        cout << x << '\n';
    }

    return 0;
}
