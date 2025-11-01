#include <iostream>
#include <cmath>
#include <deque>
#include <tuple>
using namespace std;

int n, m, k;
int grid[101][101];
bool flag = true;
deque<tuple<int, int, char>> dq;
int move(char dir, int count)
{
	for(int i=1; i<=count; ++i)
	{
		int x = get<0>(dq.front());
		int y = get<1>(dq.front());
		if (dir == 'U')
		{
			if (x - 1 <= 0) { flag = false; return i; }
			dq.push_front({ --x, y, dir });
		}
		else if (dir == 'D')
		{
			if (x + 1 > n) { flag = false; return i; }
			dq.push_front({ ++x, y, dir });
		}
		else if (dir == 'L')
		{
			if (y - 1 <= 0) { flag = false; return i; }
			dq.push_front({ x, --y, dir });
		}
		else
		{
			if (y + 1 > n) { flag = false; return i; }
			dq.push_front({ x, ++y, dir });
		}

		if (grid[x][y] > 0) { flag = false; return i; }
		else if (grid[x][y] == -1) { grid[x][y] = 0; }
		else
		{	
			int bx = get<0>(dq.back());
			int by = get<1>(dq.back());
			grid[bx][by] = 0;
			dq.pop_back();
		}
		grid[x][y] = 1;
	}
	return count;
}
int main()
{
	cin >> n >> m >> k;

	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		grid[x][y] = -1;
	}
	dq.push_front({ 1,1,'N'});
	char dir;
	int count;
	int total = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> dir  >> count;
		int ans = move(dir, count);
		if (!flag)
		{
			total += ans;
			break;
		}
		total += count;
	}

	cout << total;
}