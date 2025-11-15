#include <iostream>
#include <climits>
using namespace std;

int n;
int jump[10];
int ansMin = 200;
void Select(int cnt, int curIdx)
{
    if (cnt == n)
    {
        return;
    }
    if (curIdx == n-1)
    {
        ansMin = min(ansMin, cnt);
        return;
    }

    for (int i = 0; i <= jump[curIdx]; ++i)
    {
        Select(cnt + 1, curIdx + i);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> jump[i];
    }
    Select(0, 0);
    if (ansMin == 200) cout << -1;
    else cout << ansMin;    
    // Please write your code here.

    return 0;
}
