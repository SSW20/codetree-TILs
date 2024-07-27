#include <iostream>
using namespace std;

int *arr;
int ans = 0;
int max(int idx){
    if(idx == 0) return ans;
    if(arr[idx] > ans) ans = arr[idx];
    return max(idx-1);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    arr = new int[n];
    for(int i=0;i<n;++i) cin >> arr[i];

    cout << max(n-1);
    return 0;


}