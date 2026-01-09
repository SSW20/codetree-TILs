#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int M, T;
int main() {
    cin >> T;
    int x;

    while (T-- > 0)
    {
        cin >> M;
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        int idx = 1;
        while (idx <= M)
        {
            cin >> x;
            if (left.size() >= right.size()) right.push(x);
            else left.push(x);

            if (!left.empty() && !right.empty() && left.top() > right.top())
            {
                int tempL = left.top();
                int tempR = right.top();
                left.pop();
                right.pop();

                left.push(tempR);
                right.push(tempL);
            }

            if (idx % 2 != 0)
            {
                cout << right.top() << ' ';
            }
            idx++;
        }
        cout << '\n';
    }
    return 0;
}
