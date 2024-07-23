#include <iostream>
using namespace std;

bool isValid(int a){
    for(int i=2; i<a; ++i){
        if(a % i == 0 ) return false;
    }
    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    
    int a,b;
    cin >> a >> b;
    
    int total = 0;
    for(int i=a; i<=b; ++i){
        if(isValid(i)) total +=i; 
    }

    cout << total;
    return 0;
}