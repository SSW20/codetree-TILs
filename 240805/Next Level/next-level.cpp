#include <iostream>
#include <string>
using namespace std;

class User{
    private:
        string name;
        int level;
    public:
        User(string name = "codetree", int level = 10){
            this->name = name;
            this->level = level;
        }

        void printString(){
            cout << "user " << this->name << " lv " << this->level << "\n"; 
        }

};


int main() {
    // 여기에 코드를 작성해주세요.
    string name;
    int level;
    cin >> name >> level;

    User user1;
    User user2(name, level);

    user1.printString();
    user2.printString();

    return 0;
}