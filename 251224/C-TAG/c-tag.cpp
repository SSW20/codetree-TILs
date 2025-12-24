#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int n, m;
string A[500];
string B[500];

unordered_set<string> uset;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> A[i];

	for (int i = 0; i < n; i++) cin >> B[i];

	int ans = 0;
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++)
			for (int k = j + 1; k < m; k++)
			{
				for (int t = 0; t < n; ++t)
				{
					string temp = "";
					temp += A[t][i]; 
					temp += A[t][j];
					temp += A[t][k];
					uset.insert(temp);
				}

				bool bCan = true;

				for (int t = 0; t < n; ++t)
				{
					string temp = "";
					temp += B[t][i];
					temp += B[t][j];
					temp += B[t][k];
					
					if (uset.find(temp) != uset.end())
					{
						bCan = false;
						break;
					}
				}

				if (bCan) ++ans;
				uset.clear();
			}

	cout << ans;
	return 0;
}
