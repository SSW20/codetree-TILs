#include <iostream>

using namespace std;

int n;
int r, c;
int a[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void move(int r, int c)
{
    int x = r, y = c;
    int max = a[x][y];
    cout << a[x][y] << ' ';
    while (true)
    {
        int tempX = -1, tempY = -1;
        for (int d = 0; d < 4; ++d)
        {
            int i = x + dx[d];
            int k = y + dy[d];
            if (i < 0 || k < 0 || i >= n || k >= n) continue;
            if (max < a[i][k])
            {
                max = a[i][k];
                tempX = i;
                tempY = k;
                break;
            }
        }
        if (tempX == -1 && tempY == -1) return;
        else
        {
            cout << max << ' ';
            x = tempX;
            y = tempY;
        }
    }
}

int main() {
    cin >> n >> r >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    move(r - 1, c - 1);
    // Please write your code here.

    return 0;
}
