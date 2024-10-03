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

int  N, T;

int iNumArr[604];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> T;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> iNumArr[(i * N) + j];
        }
    }

    int iTemp = 0;
    while (T--)
    {
        iTemp = iNumArr[(N * 3) - 1];

        for (int i = (N * 3) - 1; i > 0; --i)
        {
            iNumArr[i] = iNumArr[i - 1];
        }

        iNumArr[0] = iTemp;
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << iNumArr[j + (i * N)] << ' ';
        }

        cout << '\n';
    }

    return 0;
}