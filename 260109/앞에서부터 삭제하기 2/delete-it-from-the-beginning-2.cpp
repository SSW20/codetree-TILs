#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int arr[100000];
int total[100000];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (i == 0) total[0] = arr[0];
        else total[i] = total[i - 1] + arr[i];
    }
    float ans = -1;
    for (int i = 1; i <= N - 2; ++i)
    {
        int totalVal = total[N - 1] - total[i - 1];
        int x = 9999999;
        for (int k = i; k < N; ++k)
        {
            x = min(x, arr[k]);
        }

        totalVal -= x;

        ans = max(ans,totalVal / float(N - i - 1));
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
    return 0;
}
