#include <iostream>
using namespace std;



int main() {
    // 여기에 코드를 작성해주세요.
    int m1,d1,m2,d2;
    int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> m1 >> d1 >> m2 >> d2;

    int total = 0;

    
    for(int i=m1; i<m2; ++i){ total += num_of_days[i];}
    if(m1 == m2) total += d2 - d1;
    else total += d2 - d1;
    cout << total + 1;
    return 0;
}