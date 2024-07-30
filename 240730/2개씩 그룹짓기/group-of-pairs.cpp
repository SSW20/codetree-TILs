#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int *arr = new int[2*n];
    for(int i=0; i<2*n; ++i) cin >> arr[i];

    sort(arr, arr+2*n);

    int left = 0;
    int right = 2*n-1;
    int max = 0; 
    while(left < right){
        if(arr[left] + arr[right] > max ) max = arr[left] + arr[right]; 
        left++;
        right--;
    }
    cout << max;
    

    
    return 0;
}