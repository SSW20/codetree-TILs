#include <iostream>
using namespace std;

int arr[20][20];
int dx[8] = { -1, -1, 0, 1, 1 , 1, 0 , -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1,-1 };

int N, M;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int k = 0; k < N; ++k)
			cin >> arr[i][k];

	while (M-- > 0)
	{
		for (int l = 1; l <= N*N; l++)
		{
			bool flag = false;
			for (int i = 0; i < N; ++i)
			{
				if (flag) break;
				for (int k = 0; k < N; ++k)
				{
					if (flag) break;
					if (arr[i][k] == l)
					{
						int tempX, tempY;
						int max = -1;
						for (int d = 0; d < 8; ++d)
						{
							int x = i + dx[d];
							int y = k + dy[d];

							if (x < 0 || y < 0 || x >= N || y >= N) continue;
							if (max < arr[x][y])
							{
								max = arr[x][y];
								tempX = x;
								tempY = y;
							}
						}

						int temp = arr[i][k];
						arr[i][k] = arr[tempX][tempY];
						arr[tempX][tempY] = temp;

						flag = true;
					}
				}
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int k = 0; k < N; ++k)
			cout << arr[i][k] << ' ';

		cout << '\n';
	}

}