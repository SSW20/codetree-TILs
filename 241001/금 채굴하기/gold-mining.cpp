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

int  N, M;
bool bVisited[21][21];
int  iBoard[21][21];

int iDirY[4] = { -1, 0, 1, 0 };
int iDirX[4] = { 0, 1, 0, -1 };

int iResult = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> iBoard[i][j];
        }
    }

    queue<pair<int, int>> queDesc;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            bVisited[i][j] = true;
            int iAcc = iBoard[i][j];
            int iBlk = 1;

            for (int k = 0; k < 4; ++k)
            {
                int iNextY = i + iDirY[k];
                int iNextX = j + iDirX[k];

                if (iNextY < 0 || iNextY >= N || iNextX < 0 || iNextX >= N || bVisited[iNextY][iNextX])
                {
                    continue;
                }

                iAcc += iBoard[iNextY][iNextX];
                queDesc.push({ iNextY, iNextX });
                bVisited[iNextY][iNextX] = true;
            }

            if ((iAcc * M) >= 5)
            {
                iResult = max(iResult, iAcc);
            }

            while (queDesc.size())
            {
                int iCurY = queDesc.front().first;
                int iCurX = queDesc.front().second;
                queDesc.pop();

                for (int t = 0; t < 4; ++t)
                {
                    int iNextY = iCurY + iDirY[t];
                    int iNextX = iCurX + iDirX[t];

                    if (iNextY < 0 || iNextY >= N || iNextX < 0 || iNextX >= N || bVisited[iNextY][iNextX])
                    {
                        continue;
                    }

                    iAcc += iBoard[iNextY][iNextX];
                    bVisited[iNextY][iNextX] = true;
                }
            }

            if ((iAcc * M) >= 13)
            {
                iResult = max(iResult, iAcc);
            }

            memset(bVisited, false, sizeof(bVisited));
        }
    }

    cout << iResult << '\n';

    return 0;
}