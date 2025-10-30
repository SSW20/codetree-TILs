#include <iostream>

using namespace std;

int grid[4][4];
int temp[4][4];
char dir;

void gravity(char dir)
{
    if (dir == 'U')
    {
        for (int i = 0; i < 4; ++i)
        {
            int idx = 0;
            for (int k = 0; k < 4; ++k)
            {
                if (grid[k][i] != 0)  temp[idx++][i] = grid[k][i];
            }
        }

    }
    else if(dir == 'D')
    {
        for (int i = 0; i < 4; ++i)
        {
            int idx = 3;
            for (int k = 3; k > -1; --k)
            {
                if (grid[k][i] != 0)  temp[idx--][i] = grid[k][i];
            }
        }
    }
    else if(dir == 'L')
    {
        for (int i = 0; i < 4; ++i)
        {
            int idx = 0;
            for (int k = 0; k < 4; ++k)
            {
                if (grid[i][k] != 0)  temp[i][idx++] = grid[i][k];
            }
        }
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            int idx = 3;
            for (int k = 3; k > -1; --k)
            {
                if (grid[i][k] != 0)  temp[i][idx--] = grid[i][k];
            }
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        for (int k = 0; k < 4; ++k)
        {
            grid[i][k] = temp[i][k];
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int k = 0; k < 4; ++k)
        {
            temp[i][k] = 0;
        }
    }
}
void add(char dir)
{
    if (dir == 'U')
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int k = 0; k < 3; ++k)
            {
                if (grid[k][i] == 0) continue;
                if (grid[k][i] == grid[k + 1][i])
                {
                    grid[k][i] *= 2;
                    grid[k + 1][i] = 0;
                }
            }
        }

    }
    else if (dir == 'D')
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int k = 3; k > 0; --k)
            {
                if (grid[k][i] == 0) continue;
                if (grid[k][i] == grid[k - 1][i])
                {
                    grid[k][i] *= 2;
                    grid[k - 1][i] = 0;
                }
            }
        }
    }
    else if (dir == 'L')
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int k = 0; k < 3; ++k)
            {
                if (grid[i][k] == 0) continue;
                if (grid[i][k] == grid[i][k+1])
                {
                    grid[i][k] *= 2;
                    grid[i][k+1] = 0;
                };
            }
        }
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int k = 3; k > 0; --k)
            {

                if (grid[i][k] == 0) continue;
                if (grid[i][k] == grid[i][k - 1])
                {
                    grid[i][k] *= 2;
                    grid[i][k - 1] = 0;
                };
            }
        }
    }
}
int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> dir;
    gravity(dir);
    add(dir);
    gravity(dir);
    // Please write your code here.
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
