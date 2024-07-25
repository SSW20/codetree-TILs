#include <iostream>
using namespace std;

void helloWorld(int n){
    if(n == 0) return;
    cout << "HelloWorld\n";
    return helloWorld(n-1);
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    helloWorld(n);
    return 0;
}