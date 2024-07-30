#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<2*n; ++i) cin >> arr[i];

    sort(arr, arr+n);

    int n1=0,n2=0;
    for(int i=0; i<2*n-1; i+=2)
    {
        n1 += arr[i];
        n2 += arr[i+1];
    }

    if(n1 > n2) cout << n1;
    else cout << n2;

    
    return 0;
}