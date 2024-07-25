#include <iostream>
using namespace std;

void printAsterisk(int n){
    if(n == 0) return;
    printAsterisk(n-1);

    for(int i=0;i<n;++i) cout << '*';
    cout << '\n';
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    printAsterisk(n);
    return 0;
}