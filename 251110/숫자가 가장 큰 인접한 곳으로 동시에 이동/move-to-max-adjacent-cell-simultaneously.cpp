#include <iostream>
using namespace std;

int grid[21][21];
int ans[21][21];
int ansTemp[21][21];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1};
int N, M, T, r, c;

int main()
{
	cin >> N >> M >> T;

	for (int i = 1; i <= N; ++i)
		for (int k = 1; k <= N; ++k)
			cin >> grid[i][k];

	while (M-- > 0)
	{
		cin >> r >> c;
		ans[r][c] = 1;
	}


	while (T-- > 0)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int k = 1; k <= N; ++k)
			{
				if (ans[i][k] > 0)
				{
					
					int ansX, ansY;
					int max = -1;
					for (int d = 0; d < 4; ++d)
					{
						int x = i + dx[d];
						int y = k + dy[d];
						if (x < 1 || y < 1 || x > N || y > N) continue;
						if (max < grid[x][y])
						{
							ansX = x;
							ansY = y;
							max = grid[x][y];
						}
					}
					ansTemp[ansX][ansY]++;
				}
			}
		}

		for (int i = 1; i <= N; ++i)
		{
			for (int k = 1; k <= N; ++k)
			{
				if (ansTemp[i][k] > 1) ansTemp[i][k] = 0;
			}
		}

		for (int i = 1; i <= N; ++i)
		{
			for (int k = 1; k <= N; ++k)
			{
				ans[i][k] = ansTemp[i][k];
			}
		}

		for (int i = 1; i <= N; ++i)
		{
			for (int k = 1; k <= N; ++k)
			{
				ansTemp[i][k] =0;
			}
		}
	}



	int count = 0;
	for (int i = 1; i <= N; ++i)
		for (int k = 1; k <= N; ++k)
		{
			if (ans[i][k] == 1) ++count;
		}
	cout << count;
}
