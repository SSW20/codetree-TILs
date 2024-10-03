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

int iUpperArr[204];
int iLowerArr[204];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> T;

    for (int i = 0; i < N; ++i)
    {
        cin >> iUpperArr[i];
    }
    for (int i = N - 1; i >= 0; --i)
    {
        cin >> iLowerArr[i];
    }

    while (T--)
    {
        int iLTemp = iLowerArr[0];
        int iUTemp = iUpperArr[N - 1];

        for (int i = 0; i < N - 1; ++i)
        {
            iLowerArr[i] = iLowerArr[i + 1];
        }
        for (int i = N - 1; i > 0; --i)
        {
            iUpperArr[i] = iUpperArr[i - 1];
        }

        iLowerArr[N - 1] = iUTemp;
        iUpperArr[0] = iLTemp;
    }

    for (int i = 0; i < N; ++i)
    {
        cout << iUpperArr[i] << ' ';
    }
    cout << '\n';
    for (int i = N - 1; i >= 0; --i)
    {
        cout << iLowerArr[i] << ' ';
    }

    return 0;
}