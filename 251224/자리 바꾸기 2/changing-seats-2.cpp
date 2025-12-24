#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int N, K;
int a[100000], b[100000];

int seat[100001];
unordered_set<int> uset[100001];

int main() {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        seat[i] = i;
        uset[i].insert(i);
    }

    int num = 3;
    while (num-- > 0)
    {
        for (int i = 0; i < K; i++) {
            cin >> a[i] >> b[i];

            uset[seat[a[i]]].insert(b[i]);
            uset[seat[b[i]]].insert(a[i]);

            int temp = seat[a[i]];
            seat[a[i]] = seat[b[i]];
            seat[b[i]] = temp;
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        cout << uset[i].size() << '\n';
    }





    return 0;
}
