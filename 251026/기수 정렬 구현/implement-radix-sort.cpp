#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int n;
int arr[100000];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    vector<queue<int>> vq(10);
    for (int i = 0; i < n; i++) 
    {
        vq[arr[i] % 10].push(arr[i]);
    }

    int idx = 0;
    for (int i = 0; i < 10; i++)
    {
        while (!vq[i].empty())
        {
            arr[idx] = vq[i].front();
            vq[i].pop();
            ++idx;
        }
    }

    for (int i = 2; i < 6; ++i)
    {
        for (int k = 0;k < n; k++)
        {
            int index  = arr[k] % int(pow(10, i)) / pow(10, i - 1);
            vq[index].push(arr[k]);
        }

        int idx = 0;
        for (int k = 0; k < 10; k++)
        {
            while (!vq[k].empty())
            {
                arr[idx] = vq[k].front();
                vq[k].pop();
                ++idx;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}
