#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int *arr = new int[n];
    int *arr2 = new int[n];

    for(int i=0;i<n;++i) cin >> arr[i];
    for(int i=0;i<n;++i) cin >> arr2[i];

    sort(arr,arr+n);
    sort(arr2,arr2+n);

    for(int i=0;i<n;++i){
        if(arr[i] != arr2[i]){ cout << "No"; return 0;}
    }
    cout << "Yes";

    return 0;
}