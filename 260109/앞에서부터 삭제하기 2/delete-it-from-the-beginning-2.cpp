#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int arr[100000];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(arr[N - 1]);
    float ans = 0;
    float total = 0;
    for (int i = N-2; i > 0; --i)
    {
        int prev = pq.top();
        pq.push(arr[i]);
        int cur = pq.top();

        if (prev == cur)
        {
            total += arr[i];
        }
        else
        {
            total = total + prev;
        }

        ans = max(ans, total / (N - i - 1));
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
    return 0;
}
