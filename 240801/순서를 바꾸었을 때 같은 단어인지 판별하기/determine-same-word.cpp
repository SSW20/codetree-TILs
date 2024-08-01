#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[26];
    int arr2[26];
    fill(arr, arr+26, 0);
    fill(arr2, arr2+26, 0);
    string s,s2;
    cin >> s >> s2;

    for(char c : s) {arr[c-'a']++;}
    for(char c : s2) {arr2[c-'a']++;}

    for(int i=0;i<26; ++i) {
        if(arr[i] != arr2[i]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";



    return 0;
}