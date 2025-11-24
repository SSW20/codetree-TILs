#include <iostream>
#include <queue>

using namespace std;

int N;

int main() {
    cin >> N;

    // Please write your code here.
    queue<pair<int,int>> q;
    q.push({ N,0 });
    int ans = 0;
    while (!q.empty())
    {
        int val = q.front().first;
        int count = q.front().second;
        q.pop();

        int temp;

        temp = val + 1;
        if (temp == 1)
        {
            ans = count + 1;
            break;
        }
        else 
        {
            q.push({ temp, count + 1 });;
        }

        temp = val - 1;
        if (temp == 1)
        {
            ans = count + 1;
            break;
        }
        else
        {
            q.push({ temp, count + 1 });
        }

        if (val % 2 == 0)
        {
            temp = val / 2;
            if (temp == 1)
            {
                ans = count + 1;
                break;
            }
            else
            {
                q.push({ temp, count + 1 });
            }
        }

        if (val % 3 == 0)
        {
            temp = val / 3;
            if (temp == 1)
            {
                ans = count + 1;
                break;
            }
            else
            {
                q.push({ temp, count + 1 });
            }
        }
    }

    cout << ans;
    return 0;
}
