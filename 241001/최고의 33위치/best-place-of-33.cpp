#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <tuple>
#include <regex>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>

using namespace std;

int N;

int iBoard[21][21];
int iAcc[21][21];

int iResult = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> iBoard[i][j];
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 3; j <= N; ++j)
        {
            iAcc[i][j] = iBoard[i][j - 1] + iBoard[i][j - 2] + iBoard[i][j];
        }
    }

    for (int i = 3; i <= N; ++i)
    {
        for (int j = 3; j <= N; ++j)
        {
            iResult = max(iResult, iAcc[i][j] + iAcc[i - 1][j] + iAcc[i - 2][j]);
        }
    }

    cout << iResult << '\n';

    return 0;
}