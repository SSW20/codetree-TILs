#include <iostream>
using namespace std;



int main() {
    // 여기에 코드를 작성해주세요.
    int n,a1,a2,m;
    cin >> n >> m;

    int *arr = new int[n+2];

    arr[0] = 0;
    for(int i=1;i<=n;++i) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    while(m-->0){
        cin >> a1 >> a2;
        cout << arr[a2] - arr[a1-1] << '\n';
    }


    return 0;

}