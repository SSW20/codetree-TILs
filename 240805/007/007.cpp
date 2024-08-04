#include <iostream>
#include <string>
using namespace std;

struct Spy{
    string code;
    char place;
    int time; 
};

int main() {
    // 여기에 코드를 작성해주세요.
    string code;
    char place;
    int time;

    cin >> code >> place >> time;
    Spy spy = {code,place, time};

    cout << "secret code : " << spy.code << '\n';
    cout << "meeting point : " << spy.place << '\n';
    cout << "time : " << spy.time << '\n';
    return 0;
}