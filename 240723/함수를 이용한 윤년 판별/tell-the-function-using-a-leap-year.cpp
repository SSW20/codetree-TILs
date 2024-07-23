#include <iostream>
using namespace std;

bool isValid(int year)
{
    if(year % 4 == 0){
        if(year % 100 == 0 && year % 400 != 0) return false;
        else return true;
    }
    return false;
}
int main() {
    // 여기에 코드를 작성해주세요.
    int year;
    cin >> year;
   
    if(isValid(year)) cout << "true";
    else cout << "false";
    return 0;
}