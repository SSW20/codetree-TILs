#include <iostream>

using namespace std;

int n, m;
int A[20];
int ansMax = -1;
void Calc(int cnt, int idx, int total)
{
    if (cnt == m)
    {
        ansMax = max(total, ansMax);
        return;
    }

    for (int i = idx; i < n; ++i)
    {
        int temp = total ^ A[i];
        Calc(cnt + 1, i + 1, temp);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    Calc(0, 0, 0);
    cout << ansMax;
    // Please write your code here.

    return 0;
}