#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>   
#include <algorithm>
#include <vector>
using namespace std;

int n, k, u, d;
int grid[8][8];
int visited[8][8];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ansMax = -1;
vector <pair<int, int>>selected;

int BFS()
{
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;
	for (auto p : selected)
	{
		q.push(p);
		visited[p.first][p.second] = 1;
	}

	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int d2 = 0; d2 < 4; ++d2)
		{
			int x = cur_x + dx[d2];
			int y = cur_y + dy[d2];
			if (x < 0 || y < 0 || x >= n || y >= n) continue;
			if (visited[x][y] == 1) continue;

			int value = abs(grid[x][y] - grid[cur_x][cur_y]);
			if (value >= u && value <= d)
			{
				q.push(make_pair(x, y));
				visited[x][y] = 1;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) count++;
		}
	}
	return count;
}

void Select(int cnt, int idx)
{
	if (cnt == k)
	{
		ansMax = max(ansMax, BFS());
		return;
	}

	int x = idx / n;
	int y = idx % n;
	if (x >= n || y >= n) return;

	selected.push_back(make_pair(x, y));
	Select(cnt + 1, idx + 1);
	selected.pop_back();
	Select(cnt, idx + 1);
}

int main() {
	cin >> n >> k >> u >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	Select(0, 0);
	// Please write your code here.
	cout << ansMax;
	return 0;
}
