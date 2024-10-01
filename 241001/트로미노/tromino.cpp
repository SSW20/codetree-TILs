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
int iBoard[204][204];
int iResult = 0;

pair<int, int> pairRot[4] = { {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> iBoard[i][j];
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            int iTempA, iTempB;

            for (int k = 0; k < 4; ++k)
            {
                iTempA = (i + pairRot[k].first);
                iTempB = (j + pairRot[k].second);
                
                if (iTempA <= 0 || iTempA > N || iTempB <= 0 || iTempB > M)
                    continue;

                iResult = max(iResult, iBoard[i][j] + iTempA + iTempB);
            }
        }
    }
    
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 3; j <= M; ++j)
        {
            iResult = max(iResult, iBoard[i][j] + iBoard[i][j - 1] + iBoard[i][j - 2]);

            if (i >= 3)
            {
                iResult = max(iResult, iBoard[i][j] + iBoard[i - 1][j] + iBoard[i - 2][j]);
            }
        }
    }

    cout << iResult << '\n';

    return 0;
}