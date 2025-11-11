#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

vector<tuple<int, int, int>> grid[50][50]; 
vector<tuple<int, int, int>> gridNext[50][50];
int n, m, t, k;

tuple<int, int, int> NextPos(int r, int c, int v, int dir)
{
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	while (v-- > 0)
	{
		int x = r + dx[dir];
		int y = c + dy[dir];

		if (x < 0 || y < 0 || x >= n || y >= n)
		{
			dir = (dir + 2) % 4;
			x = r + dx[dir]; 
			y = c + dy[dir];
		}

		r = x;
		c = y;
	}

	return { r,c,dir };
}

void MoveAll()
{
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			for (int i = 0; i < (int)grid[x][y].size(); i++) {
				int v, num, move_dir;
				tie(v, num, move_dir) = grid[x][y][i];

				int next_x, next_y, next_dir;
				// v값이 음수이므로, -를 붙여 넘겨줍니다.
				tie(next_x, next_y, next_dir) = NextPos(x, y, -v, move_dir);
				gridNext[next_x][next_y].push_back(
					make_tuple(v, num, next_dir)
				);
			}
}

void Select()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (gridNext[i][j].size() >= k)
			{
				sort(gridNext[i][j].begin(), gridNext[i][j].end());
				while (gridNext[i][j].size() > k)
					gridNext[i][j].pop_back();
			}
		}
}

void Simulate() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			gridNext[i][j].clear();

	// Step2. 구슬들을 전부 움직입니다.
	MoveAll();

	// Step3. 각 칸마다 구슬이 최대 k개만 있도록 조정합니다.
	Select();

	// Step4. next_grid 값을 grid로 옮겨줍니다.
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			grid[i][j] = gridNext[i][j];
}

int main()
{
	cin >> n >> m >> t >> k;

	int dir_mapper[128];
	dir_mapper['U'] = 0;
	dir_mapper['R'] = 1;
	dir_mapper['D'] = 2;
	dir_mapper['L'] = 3;

	for (int i = 0; i < m; i++) {
		int r, c, v; char d;
		cin >> r >> c >> d >> v;

		// 살아남는 구슬의 우선순위가 더 빠른 속도, 더 큰 번호 이므로
		// 정렬시 속도가 먼저 내림차순, 그 다음에는 번호가 내림차순으로 오도록
		// (-속도, -번호, 방향) 순서를 유지합니다.
		grid[r - 1][c - 1].push_back(
			make_tuple(-v, -(i + 1), dir_mapper[d])
		);
	}

	while (t--)
		Simulate();
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans += (int)grid[i][j].size();

	cout << ans;

	return 0;

}