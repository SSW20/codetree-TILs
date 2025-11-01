#include <iostream>

using namespace std;

int n;
int grid[100][100];

int calculate(int r, int c, char d)
{
	int x = r;
	int y = c;
	int count = 1;
	while (!(x < 0 || y < 0 || x >= n || y >= n))
	{
		if (d == 'U')
		{
			if (grid[x][y] == 1) { d = 'R'; y++; }
			else if (grid[x][y] == 2) { d = 'L'; y--; }
			else x--;
		}
		else if (d == 'L')
		{
			if (grid[x][y] == 1) { d = 'D'; x++; }
			else if (grid[x][y] == 2) { d = 'U'; x--; }
			else y--;
		}
		else if (d == 'R')
		{
			if (grid[x][y] == 1) { d = 'U'; x--; }
			else if (grid[x][y] == 2) { d = 'D'; x++; }
			else y++;
		}
		else
		{
			if (grid[x][y] == 1) { d = 'L'; y--; }
			else if (grid[x][y] == 2) { d = 'D'; y++; }
			else x++;
		}
		++count;
	}
	return count;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> grid[i][j];
	int ans = -1;

	// Please write your code here.
	for (int j = 0; j < n; j++)
	{
		int temp = calculate(0, j, 'D');
		ans = max(ans, temp);
	}
	for (int j = 0; j < n; j++)
	{
		int temp = calculate(j, n - 1, 'L');
		ans = max(ans, temp);
	}
	for (int j = 0; j < n; j++)
	{
		int temp = calculate(j, 0, 'R');
		ans = max(ans, temp);
	}
	for (int j = 0; j < n; j++)
	{
		int temp = calculate(n - 1, j, 'U');
		ans = max(ans, temp);
	}
	cout << ans;
	return 0;
}
