#include <iostream>
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;

int n, m, r, c;
int grid[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int main() {
	cin >> n >> m >> r >> c;
	queue<pair<int, int>>  q;
	queue<pair<int, int>>  tempQ;

	grid[r][c] = 1;
	int ans = 1;
	int count = 1;
	q.push(make_pair(r, c));
	while (m-- > 0)
	{
		while (!q.empty())
		{
			int i = q.front().first;
			int k = q.front().second;
			q.pop();
			tempQ.push(make_pair(i, k));

			for (int d = 0; d < 4; ++d)
			{
				int x = i + dx[d] * pow(2, count - 1);
				int y = k + dy[d] * pow(2, count - 1);
				if (x <= 0 || y <= 0 || x > n || y > n) continue;
				if (grid[x][y] > 0) continue;
				grid[x][y] = 1;
				tempQ.push(make_pair(x, y));
				++ans;
			}
		}

		while (!tempQ.empty())
		{
			q.push(tempQ.front()); tempQ.pop();
		}
		++count;
	}
	cout << ans;



	return 0;
}
