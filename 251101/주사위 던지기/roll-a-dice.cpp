#include <iostream>

using namespace std;

int n, m;
int r, c;
char dir;
int map[101][101];
int main() {
    cin >> n >> m >> r >> c;
    int front = 2;
    int right = 3;
    int up = 1;
    map[r][c] = 6;
    for (int i = 0; i < m; i++) {
        cin >> dir;
        if (dir == 'R')
        {
            if (c + 1 > n) continue;
            map[r][++c] = right;
            int temp = right;
            right = up;
            up = 7 - temp;
        }
        else if (dir == 'L')
        {
            if (c - 1 < 1) continue;
            map[r][--c] = 7-right;
            int temp = right;
            right = 7 - up;
            up = temp;
        }
        else if (dir == 'U')
        {
            if (r - 1 < 1) continue;
            map[--r][c] = 7 - front;
            int temp = front;
            front = 7 - up;
            up = temp;
        }
        else
        {
            if (r + 1 > n) continue;
            map[++r][c] = front;
            int temp = front;
            front = up;
            up = 7 - temp;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < n; ++k)
        {
            ans += map[i][k];
        }
    }
    // Please write your code here.
    cout << ans;
    return 0;
}
