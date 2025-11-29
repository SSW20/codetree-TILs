#include <iostream>
#include <stack>
using namespace std;

int n;
int grid[500][500];
int visited[500][500];
long long int ans[500][500];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            ans[i][j] = 1;
        }
    }

    // Please write your code here.

    stack<pair<int, int>> st;
    long long int ansMax = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j]) continue;
            st.push({ i,j });
            visited[i][j] = 1;
            while (!st.empty())
            {
                int curX = st.top().first;
                int curY = st.top().second;
                st.pop();
                for (int d = 0; d < 4; ++d)
                {
                    int x = curX + dx[d];
                    int y = curY + dy[d];
                    if (x < 0 || y < 0 || x >= n || y >= n) continue;
                    if (grid[x][y] <= grid[curX][curY] || ans[x][y] > ans[curX][curY] + 1) continue;
                    st.push({ x,y });
                    ans[x][y] = ans[curX][curY] + 1;
                    ansMax = max(ans[x][y], ansMax);
                    visited[x][y] = 1;
                }
            }
        }
    }

    cout << ansMax;


    return 0;
}