#include <iostream>
using namespace std;

void abs(int *arr, int length){
    for(int i=0;i<length; ++i){
        if(arr[i] < 0) cout << -arr[i] << ' ';
        else cout << arr[i] << ' ';
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int N;
    cin >> N;
    int *arr = new int[N];
    for(int i=0;i<N;++i){
        cin >> arr[i];
    }
    abs(arr,N);
    delete[] arr;
    return 0;
}