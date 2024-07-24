#include <iostream>
using namespace std;

void divideByTwo(int *arr, int count){
    for(int i=0; i<count; ++i){
        if(arr[i] % 2 == 0) cout << arr[i] / 2 << " ";
        else cout << arr[i] << " ";
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
    divideByTwo(arr, N);
    return 0;
}