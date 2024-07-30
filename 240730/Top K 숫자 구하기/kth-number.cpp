#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    int idx;
    cin >> n >> idx;

    int *arr = new int[n];
    for(int i=0; i<n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    cout << arr[idx-1];
    return 0;
}