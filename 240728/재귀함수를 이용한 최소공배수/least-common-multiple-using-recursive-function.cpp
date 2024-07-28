#include <iostream>
using namespace std;

int uclid(int a,int b){
    if(a% b == 0) return b;
    return uclid(b, a%b);
}

int uclid2(int a,int b){
    return a * b / uclid(a,b); 
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int a = 1,b=1, x;
    while(n-->0){
        cin >> x;
        b = x;
        a = uclid2(a,b);
    }
    cout << a;

    return 0;
}