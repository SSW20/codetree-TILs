#include <iostream>
#include <set>
using namespace std;

int n, k;
int arr[100000];

int main() {
    set<int> s;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    auto it = s.end();
    it--;
    for (int i = 0; i < k; ++i)
    {
        cout << *it << ' ';
        --it;
    }




    // Please write your code here.

    return 0;
}
