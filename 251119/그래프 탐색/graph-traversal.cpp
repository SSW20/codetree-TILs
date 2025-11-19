#include <iostream>

using namespace std;

int n, m;
int grid[1001][1001];
int visited[1001];
int city_count = 0;
void Travel(int city)
{
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i] != 1 && grid[city][i])
        {
            ++city_count;
            visited[i] = 1;
            Travel(i);
        }
    }
}

int main() {
    cin >> n >> m;
    int from, to;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        grid[from][to] = 1;
        grid[to][from] = 1;
    }

    visited[1] = 1;
    Travel(1);

    cout << city_count;

    // Please write your code here.

    return 0;
}
