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

int N, M;

int iBoard[104][104];
int iAcc[104][104];

int iResult = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> iBoard[i][j];
            iAcc[i][j] = 1;
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (iBoard[i][j] == iBoard[i][j - 1])
            {
                iAcc[i][j] = iAcc[i][j - 1] + 1;
                iAcc[i][j - 1] = 1;
            }
            else
            {
                iAcc[i][j] = 1;
            }

            if (iAcc[i][j] >= M)
            {
                iAcc[i][j] = 1;
                iResult++;
                break;
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (iBoard[j][i] == iBoard[j - 1][i])
            {
                iAcc[j][i] = iAcc[j - 1][i] + 1;
                iAcc[j - 1][i] = 1;
            }
            else
            {
                iAcc[j][i] = 1;
            }

            if (iAcc[j][i] >= M)
            {
                iAcc[j][i] = 1;
                iResult++;
                break;
            }
        }
    }

    cout << iResult << '\n';

    return 0;
}