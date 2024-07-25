#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int m,n;
    cin >> n >> m;
    int *arr = new int[n+1];

    for(int i=1;i<=n;++i){
        cin >> arr[i];
    }
    
    int total = 0;

    while(m>0){
        total += arr[m];
        if(m % 2 == 0 ) m = m / 2;
        else m -= 1;
    }

    cout << total;
    return 0;
}