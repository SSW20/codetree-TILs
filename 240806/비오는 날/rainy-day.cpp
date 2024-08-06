#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    string date, day, weather;
    string ans = "9999-99-99";

    int n;
    cin >> n;

    while(n-->0){
        cin >> date >> day >> weather;
        if(weather != "Rain") continue;

        bool flag = false;
        for(int i=0; i<10; ++i){
            if(ans[i] > date[i]) {flag = true; break;}
            else if(ans [i] < date[i]) break;
        }
        if(flag) {
            ans = date + ' ' + day + ' ' + weather;
        }
    }

    cout << ans;
    return 0;
}