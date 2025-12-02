#include <iostream>

using namespace std;

int n;
int s[1000];

int dpInc[1000];
int dpDec[1000];
int num[10001];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        dpInc[i] = 1;
        dpDec[i] = 1;
        num[s[i]]++;
    }


    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (s[i] > s[j])
            {
                dpInc[i] = max(dpInc[i], dpInc[j] + 1);
            }
        }
    }

    for (int i = n-2; i > -1; --i)
    {
        for (int j = n-1; j > i; --j)
        {
            if (s[i] > s[j])
            {
                dpDec[i] = max(dpDec[i], dpDec[j] + 1);
            }
        }
    }

    int ansMax = -1;
    for (int i = 0; i < n; ++i)
    {
        ansMax = max(ansMax, dpInc[i] + dpDec[i] - 1);
    }
    cout << ansMax;
    return 0;
}
