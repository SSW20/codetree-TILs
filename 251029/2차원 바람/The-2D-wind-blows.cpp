#include <iostream>
#include <vector>
using namespace std;

int n, m, q;
int a[100][100];
int v[100][100];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0, 0,-1 };
void change(int r1, int c1, int r2, int c2)
{
    // 가로 ->
    int temp = a[r1][c2];
    for (int j = c2; j > c1; --j)
    {
        a[r1][j] = a[r1][j-1];
    }
    // 위 
    for (int i = r1; i < r2; ++i)
    {
        a[i][c1] = a[i + 1][c1];
    }
    // 가로 왼쪽 <-
    for (int j = c1; j < c2; ++j)
    {
        a[r2][j] = a[r2][j + 1];
    }
    // 아래
    for (int i = r2; i > r1 + 1; --i)
    {
        a[i][c2] = a[i - 1][c2];
    }
    a[r1 + 1][c2] = temp;
}
void average(int r1, int c1, int r2, int c2)
{
    for (int i = r1; i <= r2; ++i)
    {
        for (int k = c1; k <= c2; ++k)
        {
            int total = a[i][k];
            int count = 1;
            for (int d = 0; d < 4; ++d)
            {
                if (i + dx[d] < 0 || i + dx[d] >= n || k + dy[d] < 0 || k + dy[d] >= m) continue;
                total += a[i + dx[d]][k + dy[d]];
                ++count;
            }
            v[i][k] = total / count;
        }
    }
    for (int i = r1; i <= r2; ++i)
    {
        for (int k = c1; k <= c2; ++k)
        {
            a[i][k] = v[i][k];
        }
    }

}
void clear(int r1, int c1, int r2, int c2)
{
    for (int i = r1; i <= r2; ++i)
    {
        for (int k = c1; k <= c2; ++k)
        {
            v[i][k] = 0;
        }
    }
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        change(r1 - 1, c1 - 1, r2 - 1, c2 - 1);
        average(r1 - 1, c1 - 1, r2 - 1, c2 - 1);
        clear(r1 - 1, c1 - 1, r2 - 1, c2 - 1);
    }
    for (int i = 0; i < n; i++)
    { 
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    // Please write your code here.

    return 0;
}
