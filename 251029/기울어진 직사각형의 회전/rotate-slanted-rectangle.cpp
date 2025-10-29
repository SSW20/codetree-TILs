#include <iostream>

using namespace std;

int n;
int grid[100][100];
int r, c, m1, m2, m3, m4, dir;


void circle(int r, int c,int m1, int m2, int m3, int m4)
{
    int temp = grid[r - m1][c + m1];
    // 오른쪽 위 m1

    for (int i = m1; i > 0; --i)
    {
        grid[r - i][c + i] = grid[r  - i + 1][c + i - 1];
    }
    // 왼쪽 아래 m4
    for (int i = 0; i < m4; ++i)
    {
        grid[r + i][c + i] = grid[r + i - 1][c + i - 1];
    }
    // 왼쪽 아래 m3
    int x = r - m4;
    int y = c - m4;
    for (int i = 0; i < m3; ++i)
    {
        grid[x -i][y + i] = grid[x -i - 1][y + i + 1];
    }
    // 왼쪽 위 m2
    x = r - m1;
    y = c + m1;
    for (int i = m1; i > 1; --i)
    {
        grid[x - i][y - i] = grid[x - i + 1][y - i + 1];
    }   
    grid[x-1][y-1] = temp;
}
void reverse(int r, int c, int m1, int m2, int m3, int m4)
{
    int temp = grid[r - m4][c - m4];
    // m4
    for (int i = m4; i > 0; --i)
    {
        grid[r - i][c - i] = grid[r - i + 1][c - i + 1];
    }
    //m1
    for (int i = m1; i > 0; --i)
    {
        grid[r - (m1-i)][c + (m1 - i)] = grid[r -(m1 - i) - 1][c + (m1 - i) + 1];
    }
    // m2
    int x = r - m1;
    int y = c + m1;
    for (int i = 0; i < m2; ++i)
    {
        grid[x - i][y - i] = grid[x - i - 1][y - i - 1];
    }
    // m3
    x -= m2;
    y -= m2;
    for (int i = 0; i < m3 - 1; ++i)
    {
        grid[x + i][y - i] = grid[x + i + 1][y - i - 1];
    }

    grid[x + m3 - 1][y - m3 + 1] = temp;
   
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

    // Please write your code here.
    if (dir == 0)
    {
        circle(r-1,c-1,m1, m2, m3, m4);
    }
    else
    {
        reverse(r-1,c-1,m1, m2, m3, m4);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
