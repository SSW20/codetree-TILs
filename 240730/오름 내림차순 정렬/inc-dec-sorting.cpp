#include <iostream>
using namespace std;

void ascending(int *arr, int length){
    for(int i=0; i<length-1; ++i){
        for(int k=0; k<length-i-1; ++k){
            if(arr[k] > arr[k+1]){
                int temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
            }
        }
    }
    for(int i=0; i<length; ++i) cout << arr[i] << ' ';
}

void descending(int *arr, int length){
    for(int i=0; i<length-1; ++i){
        for(int k=0; k<length-i-1; ++k){
           if(arr[k] < arr[k+1]){
                int temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
            }
        }
    }
    for(int i=0; i<length; ++i) cout << arr[i] << ' ';
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;++i) cin >> arr[i];
    ascending(arr,n);
    cout << '\n';
    descending(arr,n);
    cout << '\n'; 
    return 0;
}