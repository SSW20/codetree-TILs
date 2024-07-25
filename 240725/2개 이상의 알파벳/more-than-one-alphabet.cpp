#include <iostream>
#include <string>
using namespace std;

bool isValid(int *count, string s){
    int cnt = 0;
    for(char c : s){
        if(count[c - 'a'] == 0) {
            if(cnt > 1) return true;
            else ++cnt;
            ++count[c-'a'];
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    string s;
    int arr[26] = {0,};
    cin >> s;
    if(isValid(arr, s)) cout << "Yes";
    else cout << "No";
    return 0;
}