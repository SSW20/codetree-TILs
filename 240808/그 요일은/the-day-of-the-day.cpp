#include <iostream>
#include <string>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int num_of_days[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string day[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat","Sun" };
    int days = 0;
    int m1, d1, m2, d2;
    string s;
    cin >> m1 >> d1 >> m2 >> d2 >> s;

    int prev = 0, next = 0;
    for (int i = 0; i < m1; ++i) { prev += num_of_days[i]; }
    for (int i = 0; i < m2; ++i) { next += num_of_days[i]; }
    prev += d1;
    next += d2;

    days = -prev + next;
    int idx;
    for (int i = 0; i < 7; ++i) { if (day[i] == s) { idx = i; break; } }

    int count = 0;

    count += days / 7;
    if (days % 7 >= idx) ++count;

    cout << count;
    return 0;
}