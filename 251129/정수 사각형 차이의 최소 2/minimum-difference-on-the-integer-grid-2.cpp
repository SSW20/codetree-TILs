#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
int grid[100][100];
pair<int, int> p[100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    // first 가 최소 , second 가 최대
    p[0][0].first = grid[0][0];
    p[0][0].second = grid[0][0];

    for (int i = 1; i < n; ++i)
    {
        if (grid[0][i] > p[0][i - 1].second)
        {
            p[0][i].first = p[0][i - 1].first;
            p[0][i].second = grid[0][i];
        }
        else if (grid[0][i] < p[0][i - 1].first)
        {
            p[0][i].second = p[0][i - 1].second;
            p[0][i].first = grid[0][i];
        }
        else
        {
            p[0][i].first = p[0][i - 1].first;
            p[0][i].second = p[0][i - 1].second;
        }

        if (grid[i][0] > p[i-1][0].second)
        {
            p[i][0].first = p[i-1][0].first;
            p[i][0].second = grid[i][0];
        }
        else if (grid[i][0] < p[i-1][0].first)
        {
            p[i][0].second = p[i-1][0].second;
            p[i][0].first = grid[i][0];
        }
        else
        {
            p[i][0].first = p[i - 1][0].first;
            p[i][0].second = p[i - 1][0].second;

        }
    }

    for (int i = 1; i < n; ++i)
    {
        for (int k = 1; k < n; ++k)
        {
            if (grid[i][k] >= max(p[i - 1][k].second, p[i][k - 1].second))
            {
                p[i][k].second = grid[i][k];
                p[i][k].first = max(p[i - 1][k].first, p[i][k - 1].first);
            }
            else if (grid[i][k] <= min(p[i - 1][k].first, p[i][k - 1].first))
            {
                p[i][k].first = grid[i][k];
                p[i][k].second = min(p[i - 1][k].second, p[i][k - 1].second);
            }
            else if (grid[i][k] >= max(p[i - 1][k].first, p[i][k - 1].first) && grid[i][k] <= min(p[i - 1][k].second, p[i][k - 1].second))
            {
                if (abs(p[i - 1][k].first - p[i - 1][k].second) < abs(p[i][k - 1].first - p[i][k - 1].second))
                {
                    p[i][k].first = p[i - 1][k].first;
                    p[i][k].second = p[i - 1][k].second;
                }
                else
                {
                    p[i][k].first = p[i][k - 1].first;
                    p[i][k].second = p[i][k - 1].second;
                }
            }
            else
            {
                if (grid[i][k] > p[i - 1][k].first && grid[i][k] < p[i - 1][k].second)
                {
                    if (p[i][k - 1].first > grid[i][k])
                    {
                        if (abs(p[i - 1][k].first - p[i - 1][k].second) < abs(grid[i][k] - p[i][k - 1].second))
                        {
                            p[i][k].first = p[i - 1][k].first;
                            p[i][k].second = p[i - 1][k].second;
                        }
                        else
                        {
                            p[i][k].first = grid[i][k];
                            p[i][k].second = p[i][k - 1].second;
                        }
                    }
                    else
                    {
                        if (abs(p[i - 1][k].first - p[i - 1][k].second) < abs(grid[i][k] - p[i][k - 1].first))
                        {
                            p[i][k].first = p[i - 1][k].first;
                            p[i][k].second = p[i - 1][k].second;
                        }
                        else
                        {
                            p[i][k].first = p[i][k - 1].first;
                            p[i][k].second = grid[i][k];
                        }
                    }
                    
                }
                else
                {
                    if (p[i - 1][k].first > grid[i][k])
                    {
                        if (abs(p[i][k - 1].first - p[i][k - 1].second) < abs(grid[i][k] - p[i - 1][k].second))
                        {
                            p[i][k].first = p[i][k - 1].first;
                            p[i][k].second = p[i][k - 1].second;
                        }
                        else
                        {
                            p[i][k].first = grid[i][k];
                            p[i][k].second = p[i - 1][k].second;
                        }
                    }
                    else
                    {
                        if (abs(p[i][k - 1].first - p[i][k - 1].second) < abs(grid[i][k] - p[i - 1][k].first))
                        {
                            p[i][k].first = p[i][k - 1].first;
                            p[i][k].second = p[i][k - 1].second;
                        }
                        else
                        {
                            p[i][k].first = p[i - 1][k].first;
                            p[i][k].second = grid[i][k];
                        }
                    }
                }
            }
        }
    }
    cout << abs(p[n - 1][n - 1].first - p[n - 1][n - 1].second);
    return 0;
}