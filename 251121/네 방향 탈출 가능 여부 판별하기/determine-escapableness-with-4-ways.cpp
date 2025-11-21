#include <iostream>
#include <queue>
using namespace std;

int n, m;
int a[100][100];
int v[100][100];
queue<pair<int,int>> q;

void Find()
{
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };


    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;

        v[cur_x][cur_y] = 1;
        q.pop();

        for (int d = 0; d < 4; ++d)
        {
            int x = cur_x + dx[d];
            int y = cur_y + dy[d];

            if (x < 0 || y < 0 || x >= n || y >= m) continue;
            if (a[x][y] == 0 || v[x][y] == 1) continue;
            q.push(make_pair(x, y));
        }
    }
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    q.push(make_pair(0, 0));
    Find();

    if (v[n - 1][m - 1] == 1) cout << 1;
    else cout << 0;
    // Please write your code here.

    return 0;
}
