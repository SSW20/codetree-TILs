#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int N,x=1;
    cin >> N;
    for(int i=0;i<N;++i){
        for(int i=0;i<N;++i){
            if(x == 10) x = 1;
            cout << x++ << ' ';
        }
        cout << "\n";
    }
    return 0;
}