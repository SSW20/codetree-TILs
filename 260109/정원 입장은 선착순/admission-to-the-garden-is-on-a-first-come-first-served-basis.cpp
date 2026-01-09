#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

int N,a,t;
tuple<int,int,int> at[100001];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a >> t;
        at[i] = { a,i,t };
    }

    sort(at, at + N + 1);

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater< tuple<int, int, int>>> pq;
    int Time = 0;
    int idx = 1;
    int maxTime = 0;
    while (idx <= N || !pq.empty())
    {
        // 집어 넣기 

        if (pq.empty())
        {
            int x, y, z;
            tie(x, y, z) = at[idx];
            if (Time < x) Time = x;
            pq.push({ y,x,z });
            idx++;
        }
        for (int i = idx; i <= N; i++) 
        {
             int x, y, z;
             tie(x, y, z) = at[i];

             if (x <= Time)
             {
                 pq.push({y,x,z});
                 idx++;
             }
             else break;
        }

        // 집어 넣은 거 가지고 돌리기
        int x, y, z;
        tie(x, y, z) = pq.top();
        maxTime = max(maxTime, Time - y);
        Time += z;
        pq.pop();
    }
    
    cout << maxTime;

    return 0;
}
