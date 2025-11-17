#include <iostream>

using namespace std;

int n;
int num[20];
int T = 0;
int ansMin = 10000;
void Calc(int cnt, int idx, int total)
{
    if (cnt == n)
    {
        if (ansMin > abs(T - total - total))
        {
            ansMin = abs(T - total - total);
        }
        return;
    }

    for (int i = idx; i < 2 * n; ++i)
    {
        Calc(cnt + 1, i + 1, total + num[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        T += num[i];
    }
    Calc(0, 0, 0);
    // Please write your code here.
    cout << ansMin;
    return 0;
}
