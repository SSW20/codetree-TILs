#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];
bool check[100];
bool checkUp(int idx, int checkIdx, char dir);
void shiftR(int idx, char dir);

void shiftL(int idx, char dir)
{
    int temp = a[idx][0];
    for (int j = 1; j < m; j++) {
        a[idx][j - 1] = a[idx][j];
    }
    a[idx][m - 1] = temp;
    check[idx] = true;
    dir = 'L';
    if (checkUp(idx, idx - 1, dir))
    {
        if (dir == 'L')
            shiftR(idx - 1, dir);
        else
            shiftL(idx - 1, dir);
    }
    if (checkUp(idx, idx + 1, dir))
    {
        if (dir == 'L')
            shiftR(idx + 1, dir);
        else
            shiftL(idx+ 1, dir);
    }
}
void shiftR(int idx, char dir)
{
    int temp = a[idx][m-1];
    for (int j = m-1; j >=1; j--) {
        a[idx][j] = a[idx][j-1];
    }
    a[idx][0] = temp;
    check[idx] = true;
    dir = 'R';
    if (checkUp(idx, idx - 1, dir))
    {
        if (dir == 'L')
            shiftR(idx - 1, dir);
        else
            shiftL(idx - 1, dir);
    }
    if (checkUp(idx, idx + 1, dir))
    {
        if (dir == 'L')
            shiftR(idx + 1, dir);
        else
            shiftL(idx + 1, dir);
    }
}
bool checkUp(int idx,int checkIdx, char dir)
{
    if (checkIdx < 0 || checkIdx >= n) return false;
    if (check[checkIdx] == true) return false;
    for (int j = 0; j < m; j++) {
        if (a[idx][j] == a[checkIdx][j]) return true;
    }
    return false;
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int r;
        char d;
        cin >> r >> d;

        int start = r - 1;
        if (d == 'L')
        {
            shiftR(start, d);
        }
        else
        {
            shiftL(start, d);
        }
        for (int i = 0; i < n; ++i)
        {
            check[i] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
           cout<< a[i][j] << ' ';
        }
        cout << '\n';
    }
    // Please write your code here.

    return 0;
}
