#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin >> n >> m;
    if(m > n) {
        int tmp = n;
        n = m;
        m = tmp;
    }

    int m2 = m;
    int r = n % m;
    while(r != 0){
        if(m < r) break;
        int tmp = r;
        r = m % r;
        m = tmp;
    }

    cout << n * m2 / m;
    return 0;
}