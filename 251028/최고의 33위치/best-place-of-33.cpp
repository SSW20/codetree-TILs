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
            int count = 0;

            if (i + 2 >= N || j + 2 >= N) continue;
            for (int k = i; k < i + 3 && k < N; ++k)
            {
                for (int p = j; p < j + 3 && p < N; ++p)
                {
                    if (grid[k][p] == 1) ++count;
                }
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
