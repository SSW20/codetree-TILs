#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
int arr1[100000];
int arr2[100000];
int n, m, k;
int main() {
    cin >> n >> m >> k;
    priority_queue<tuple<int,int,int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    int x;
   

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    
    for (int i = 0; i < n; i++) {
        pq.push({ arr1[i] + arr2[0], i,0 });
    }

    for (int i = 1; i < k; ++i)
    {
        int idx1, idx2;
        tie(ignore, idx1, idx2) = pq.top();
        pq.pop();

        idx2++;
        if (idx2 < m)
        {
            pq.push({ arr1[idx1] + arr2[idx2], idx1, idx2 });
        }
    }

    cout << get<0>(pq.top());


    return 0;
}
