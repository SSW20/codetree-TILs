#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int num_of_days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string day[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat","Sun" };
    int days = 0;
    int m1, d1, m2, d2;
    cin >> m1 >> d1 >> m2 >> d2;

    int prev = 0, next = 0;
    for (int i = 0; i < m1; ++i) { prev += num_of_days[i]; }
    for (int i = 0; i < m2; ++i) { next += num_of_days[i]; }
    prev += d1;
    next += d2;

    days = -prev + next;
    while (days < 0) {
        days += 7;
    }

    cout << day[days % 7];
    return 0;
}