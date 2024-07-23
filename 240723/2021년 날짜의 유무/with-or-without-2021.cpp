#include <iostream>
using namespace std;


bool isValidDate(int m,int d){
    if(d > 31) return false;
    else if(m > 12) return false;
    else if(m == 2 && d < 29) return true;
    else if((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d < 32) return true;
    else if((m == 4 || m == 6 || m == 9 || m == 11) && d < 31) return true;
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int M,D;
    cin >> M >> D;
    if(isValidDate(M,D)) cout << "Yes";
    else cout << "No";
    
    return 0;
}