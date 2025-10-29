#include <iostream>
#include <stack>
using namespace std;

int n, m;
int numbers[100];

int main() {
    cin >> n >> m;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int startIdx = 0;
    int count = 0;
    int flag = numbers[startIdx];
    int endIdx = 0;
    while (endIdx < n)
    {
        if (numbers[endIdx] == 0)
        {
            ++endIdx;
            continue;
        }
        if (flag == numbers[endIdx])
        {
            ++count;
            ++endIdx;
        }
        else
        {
            if (count >= m)
            {
                for (int i = startIdx; i < endIdx; ++i)
                {
                    numbers[i] = 0;
                }
                startIdx = 0;
                flag = numbers[startIdx];
                endIdx = 0;
                count = 0;
            }
            else
            {
                startIdx = endIdx;
                flag = numbers[startIdx];
                ++endIdx;
            }
        }
    }

    if (count >= m)
    {
        for (int i = startIdx; i < endIdx; ++i)
        {
            numbers[i] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] > 0)
        {
            ++ans;
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] > 0)
        {
            cout << numbers[i] << '\n';
        }
    }
    // Please write your code here.

    return 0;
}
