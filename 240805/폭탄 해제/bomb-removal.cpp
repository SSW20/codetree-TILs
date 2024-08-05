#include <iostream>
#include <string>
using namespace std;

class Bomb{
    public:
        string code;
        char color;
        int second;
        Bomb(string s, char c, int sec){
            code = s;
            color = c;
            second = sec;
        }

        void print(){
            cout << "code : " << code << '\n'; 
            cout << "color : " << color << '\n'; 
            cout << "second : " << second << '\n'; 
        }
};


int main() {
    // 여기에 코드를 작성해주세요.
    string s;
    char c;
    int sec;

    cin >> s >> c >> sec;
    Bomb *b = new Bomb(s,c,sec);
    b->print();



    return 0;
}