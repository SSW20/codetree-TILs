#include <iostream>

using namespace std;

int n, m;
int numbers[100];
int temp[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // Please write your code here.
    int length = n;
    
    bool flag = true;
    do
    {
        flag = false;
        int startIdx = 0;
        for (int endIdx = 0; endIdx < length;)
        {
            if (numbers[endIdx] == 0) {
                continue;
                ++endIdx;
            }
            while (endIdx < length && numbers[endIdx] == numbers[startIdx])
            {
                ++endIdx;
            }

            int count = endIdx - startIdx;
            if (count >= m)
            {
                for (; startIdx < endIdx; ++startIdx)
                {
                    numbers[startIdx] = 0;
                }
                flag = true;
            }
            else
            {
                startIdx = endIdx;
                count = 0;
            }
        }
        if (flag)
        {
            int idx = 0;
            for (int i = 0; i < length; ++i)
            {
                if (numbers[i] != 0) temp[idx++] = numbers[i];
            }

            for (int i = 0; i < length; ++i)
            {
                numbers[i] = temp[i];
            }
            for (int i = 0; i < length; ++i)
            {
               temp[i] = 0;
            }
            length = idx;
        }

    } while (flag);

    cout << length << '\n';
    for (int i = 0; i < length; i++) {
        cout << numbers[i] << '\n';
    }
    return 0;
}
