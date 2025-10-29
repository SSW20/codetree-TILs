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

        int startIdx = n-1;
        int count = 0;
        int flag = -1;
        int endIdx = n-1;
        while (endIdx >= 0)
        {
            if (numbers[endIdx] == 0)
            {
                --endIdx;
                continue;
            }
            if (flag == numbers[endIdx])
            {
                ++count;
                --endIdx;
            }
            else
            {
                if (count >= m)
                {
                    for (int i = startIdx; i > endIdx; --i)
                    {
                        numbers[i] = 0;
                    }
                    startIdx = n-1;
                    flag = numbers[startIdx];
                    endIdx = n-1;
                    count = 0;
                }
                else
                {
                    startIdx = endIdx;
                    flag = numbers[startIdx];
                    --endIdx;
                    count = 1;
                }
            }
        }

        if (count >= m)
        {
            for (int i = startIdx; i > endIdx; --i)
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
