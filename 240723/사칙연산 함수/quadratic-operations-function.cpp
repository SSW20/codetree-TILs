#include <iostream>
using namespace std;

bool isValid(char o){
    if(o == '+' || o == '-'  || o == '*' || o == '/') return true;
    return false;
}

int calculate(int a, int c, char o){
    if(o == '+') return a + c;
    if(o == '-') return a - c;
    if(o == '*') return a * c;
    if(o == '/') return a / c;
}


int main() {
    // 여기에 코드를 작성해주세요.
    int a,c;
    char o;
    cin >> a >> o >> c;
    if(isValid(o)){
        cout << a << ' ' << o << ' ' << c;
        cout << " = " << calculate(a,c,o);
    }
    else {
        cout << "False";
    }
      
    return 0;
}