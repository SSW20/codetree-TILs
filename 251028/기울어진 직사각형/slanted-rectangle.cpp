#include <iostream>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.

    int max = -1;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
        {
            if (i + 1 >= N || j + 1 >= N  || j - 1 < 0) continue;
            int count = grid[i][j] + grid[i+ 1][j+1] + grid[i + 1][j - 1] + grid[i + 2][j];
            int x = 2;
            bool flag = true;
            while(true)
            {
                if (i + x + 1 >= N || j - x < 0)
                {
                    flag = false;
                    break;
                }
                else
                {
                    count += grid[i + x][j - x] + grid[i + 1 + x][j + 1 - x];
                }
                ++x;
            }
            if (count > max)
            {
                max = count;
            }
        }
    }

    cout << max;
    return 0;
}
