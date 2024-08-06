#include <iostream>
#include <string>
using namespace std;

class Product{
    public:
        string name;
        int code;
        Product(string n, int c){
            this->name = n;
            this->code = c;
        }
};

int main() {
    // 여기에 코드를 작성해주세요.
    string s;
    int c;
    cin >> s >> c;
    Product product1("codetree", 50); 
    Product product2(s,c); 

    cout << "product " << product1.code << " is " << product1.name << '\n';
    cout << "product " << product2.code << " is " << product2.name << '\n';

    return 0;
}