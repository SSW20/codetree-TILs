#include <iostream>
#include <queue>
using namespace std;

int N, K;

int main() {
    cin >> N >> K;

    // Please write your code here.
    queue<int> q;

    for (int i = 1; i <= N; ++i)
    {
        q.push(i);
    }

    while (!q.empty())
    {
        for (int i = 0; i < K-1; ++i)
        {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}
