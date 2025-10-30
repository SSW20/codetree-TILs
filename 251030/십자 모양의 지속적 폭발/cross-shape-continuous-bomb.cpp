#include <iostream>

using namespace std;

int n, m;
int grid[200][200];
int temp[200][200];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int searchIdx(int c);
void gravity()
{
    for (int i = 0; i < n; ++i)
    {
        int idx = n - 1;
        for (int k = n-1; k > -1; --k)
        {
            if (grid[k][i] != 0) temp[idx--][i] = grid[k][i];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < n; ++k)
        {
            grid[i][k] = temp[i][k];
            temp[i][k] = 0;
        }
    }
}

void bomb(int c)
{
    int idx = searchIdx(c);
    if (idx == -1) return;
    int count = grid[idx][c];
    for (int i = 0; i < count; ++i)
    {
        for (int d = 0; d < 4; ++d)
        {
            int x = idx + dx[d] * i;
            int y = c + dy[d] * i;
            if (x < 0 || y < 0 || x >= n || y >= n) continue;
            grid[x][y] = 0;
        }
    }

}

int searchIdx(int c)
{
    int b = -1;
    for (int i = 0; i < n; ++i)
    {
        if (grid[i][c] != 0) return i;
    }
    return b;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        bomb(c - 1);
        gravity();
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << grid[i][j] <<' ';
        }
        cout << '\n';
    }
    // Please write your code here.

    return 0;
}
