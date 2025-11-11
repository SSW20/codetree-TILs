#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, T;
int r, c, w;
char d;
int asci[128];


// r c w 번호 d
using Tuple = tuple<int, int, int, int, int>;

// w 번호  d
queue<tuple<int, int, int>> grid[50][50];
int main()
{
	cin >> N >> M >> T;

	asci['U'] = 0;
	asci['R'] = 1;
	asci['D'] = 2;
	asci['L'] = 3;

	vector<Tuple> numbers(M);

	for (int i = 0; i < M; ++i)
	{
		cin >> r >> c >> d >> w;
		numbers[i] = { r - 1,c - 1,w,i + 1,asci[d] };
		grid[r - 1][c - 1].push({ w,i + 1,asci[d] });
	}

	while (T-- > 0)
	{
		for (int i = 0; i < numbers.size(); ++i)
		{
			int x, y, w, d, num;
			tie(x, y, w, num, d) = numbers[i];
			int dx[4] = { -1,0,1,0 };
			int dy[4] = { 0,1,0,-1 };
			grid[x][y].pop();

			if (x + dx[d] < 0 || x + dx[d] >= N || y + dy[d] < 0 || y + dy[d] >= N) { d = (d + 2) % 4; }
			else { x += dx[d]; y += dy[d]; }
			grid[x][y].push({ w,num,d });
		}

		numbers.clear();
		for (int i = 0; i < N; ++i)
		{
			for (int k = 0; k < N; ++k)
			{
				if (grid[i][k].size() > 0)
				{
					int w, d, num;
					tie(w, num, d) = grid[i][k].front();

					if (grid[i][k].size() == 1) numbers.push_back({ i,k,w,num,d });
					else
					{
						// w 번호 d
						grid[i][k].pop();
						while (!grid[i][k].empty())
						{
							int curW, curD, curNum;
							tie(curW, curNum, curD) = grid[i][k].front();

							if (curNum > num)
							{
								num = curNum;
								d = curD;
							}
							w += curW;
							grid[i][k].pop();
						}
						numbers.push_back({ i,k,w,num,d });
						grid[i][k].push({ w,num,d });
					}
				}
			}
		}
	}
		int count = numbers.size();
		int maxWeight = -1;

		for (int i = 0; i < numbers.size(); ++i)
		{
			int x, y, w, d, num;
			tie(x, y, w, num, d) = numbers[i];
			if (maxWeight < w) maxWeight = w;
		}

		cout << count << ' ' << maxWeight;
	}