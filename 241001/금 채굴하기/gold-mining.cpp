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

void LoopK(queue<pair<int, int>> _queDesc, int _iAcc, int _iK)
{
    queue<pair<int, int>> queTemp;

    while (_queDesc.size())
    {
        int iCurY = _queDesc.front().first;
        int iCurX = _queDesc.front().second;
        _queDesc.pop();

        for (int k = 0; k < 4; ++k)
        {
            int iNextY = iCurY + iDirY[k];
            int iNextX = iCurX + iDirX[k];

            if (iNextY < 0 || iNextY >= N || iNextX < 0 || iNextX >= N || bVisited[iNextY][iNextX])
            {
                continue;
            }

            _iAcc += iBoard[iNextY][iNextX];
            queTemp.push({ iNextY, iNextX });
            bVisited[iNextY][iNextX] = true;
        }
    }

    if ((_iAcc * M) >= ((_iK * _iK) + (_iK + 1) * (_iK + 1)))
    {
        iResult = max(iResult, _iAcc);

        if (queTemp.size())
        {
            LoopK(queTemp, _iAcc, _iK + 1);
        }
    }

}

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
            queDesc.push({ i, j });

            if (iAcc * M)
            {
                iResult = max(iResult, 1);
            }

            LoopK(queDesc, iAcc, 1);

            queDesc.pop();

            memset(bVisited, false, sizeof(bVisited));
        }
    }

    cout << iResult << '\n';

    return 0;
}