#include <iostream>
#include <climits>
using namespace std;

int N, M;
int nums[100];
long long int dp[101][41];
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	dp[0][20] = 1;
	for (int i = 1; i <= N; ++i)
	{
		for (int k = 0; k <= 40; ++k)
		{
			if (dp[i - 1][k] > 0)
			{
				if (nums[i - 1] > 0)
				{
					if (nums[i - 1] + k <= 40) dp[i][nums[i - 1] + k] += dp[i - 1][k];
					if (k - nums[i - 1] >= 0) dp[i][k - nums[i - 1]] += dp[i - 1][k];
				}
				else
				{
					if (nums[i - 1] + k >= 0) dp[i][nums[i - 1] + k] += dp[i - 1][k];
					if (k - nums[i - 1] <= 40) dp[i][k - nums[i - 1]] += dp[i - 1][k];
				}
			}
		}
	}
	cout << dp[N][M + 20];
	return 0;
}
