#include <iostream>

using namespace std;

int N, M, K;
int grid[100][100];
int temp[100][100];

void clear()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grid[i][j] = temp[i][j];
            temp[i][j] = 0;
        }
    }
}
void rotate()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp[i][j] = grid[N - 1 - j][i];
        }
    }
    clear();
}

void gravity()
{
    for (int i = 0; i < N; i++) 
    {
        int idx = N - 1;
        for (int j = N-1; j > -1; j--) 
        {
            if (grid[j][i] != 0) temp[idx--][i] = grid[j][i];
        }
    }
    clear();
}

void bomb()
{
    int flag = true;
    do
    {
        flag = false;
        for (int j = 0; j < N; ++j)
        {
            for (int i = 0; i < N;)
            {
                if (grid[i][j] == 0) { ++i; continue; }
                int endIdx = i + 1;
                while (endIdx < N && grid[endIdx][j] == grid[i][j])
                {
                    ++endIdx;
                }
                int count = endIdx - i;
                if (count >= M)
                {
                    for (int k = 0; k < count; ++k)
                    {
                        grid[i + k][j] = 0;
                    }
                    flag = true;
                }
                i = endIdx;
            }
        }
        gravity();
    } while (flag);
}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    while (K-- > 0)
    {
        bomb();
        gravity();
        // cout << '\n';
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < N; j++)
        //     {
        //         cout << grid[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        rotate();
        gravity();
        bomb();
    }
    int ans = 0;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (grid[i][j]) ++ans;
        }
    }
    cout << ans;
    return 0;
}
