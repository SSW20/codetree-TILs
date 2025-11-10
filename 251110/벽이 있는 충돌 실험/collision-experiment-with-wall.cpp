#include <iostream>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[51][51];
int arrTemp[51][51];
int arrOrigin[51][51];

int T, N, M, x, y;
char d;

void clear();
bool check();
void move()
{
	for (int i = 1; i <= N; ++i)
		for (int k = 1; k <= N; ++k)
		{
			if (arr[i][k] == 'D')
			{
				if (i + 1 > N) arrTemp[i][k] = 'U';
				else
				{
					if (arrTemp[i + 1][k]== 0) arrTemp[i + 1][k] = 'D';
					else arrTemp[i + 1][k] = 0;
				}
			}
			else if (arr[i][k] == 'R')
			{
				if (k + 1 > N) arrTemp[i][k] = 'L';
				else
				{
					if (arrTemp[i][k + 1] == 0) arrTemp[i][k + 1] = 'R';
					else arrTemp[i][k + 1] = 0;
				}
			}
			else if (arr[i][k] == 'U')
			{
				if (i - 1 < 1) arrTemp[i][k] = 'D';
				else
				{
					if (arrTemp[i - 1][k] == 0) arrTemp[i - 1][k] = 'U';
					else arrTemp[i - 1][k] = 0;
				}
			}
			else if (arr[i][k] == 'L')
			{
				if (k - 1 < 1) arrTemp[i][k] = 'R';
				else 
				{
					if (arrTemp[i][k - 1] == 0) arrTemp[i][k - 1] = 'L';
					else arrTemp[i][k - 1] = 0;
				}
			}
			else
				continue;
		}
	clear();
}
void clear()
{

	for (int i = 1; i <= N; ++i)
		for (int k = 1; k <= N; ++k)
			arr[i][k] = arrTemp[i][k];

	for (int i = 1; i <= N; ++i)
		for (int k = 1; k <= N; ++k)
			arrTemp[i][k] = 0;
}
bool check()
{
	int count = 0;
 	for (int i = 1; i <= N; ++i)
		for (int k = 1; k <= N; ++k)
			if (arr[i][k] != 0) ++count;
	if (count <= 1) return true;

	for (int i = 1; i <= N; ++i)
		for (int k = 1; k <= N; ++k)
			if (arr[i][k] != arrOrigin[i][k]) return false;
	return true;
}
int main()
{
	cin >> T;
	
	while (T-- > 0)
	{
		cin >> N >> M;
		while (M-- > 0)
		{
			cin >> x >> y >> d;
			arr[x][y] = d;
			arrOrigin[x][y] = d;
		}
		move();
		while (!check())
		{
			move();
		}

		int count = 0;
		for (int i = 1; i <= N; ++i)
			for (int k = 1; k <= N; ++k)
				if (arr[i][k] != 0) ++count;
		cout << count << '\n';

		for (int i = 1; i <= N; ++i)
			for (int k = 1; k <= N; ++k)
			{
				arr[i][k] = arrOrigin[i][k] = 0;
			}
	}

	
}
