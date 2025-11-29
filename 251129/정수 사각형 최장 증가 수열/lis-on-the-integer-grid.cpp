#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
int grid[500][500];
long long int ans[500][500];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<tuple<int, int, int>> v;


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            v.push_back({ grid[i][j], i, j});
            ans[i][j] = 1;
        }
    }

    // Please write your code here.

    long long int ansMax = -1;
    sort(v.begin(), v.end());
    for (auto t : v)
    {
        int x, y;
        tie(ignore, x, y) = t;

        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (grid[x][y] >= grid[nx][ny]) continue;
            ans[nx][ny] = max(ans[nx][ny], ans[x][y] + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            ansMax = max(ansMax, ans[i][j]);
        }
    }
    cout << ansMax;


    return 0;
}