#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;




int main() {
    
    int n,n2;
    cin >> n;
    vector<tuple<int,string,int,int,int>> v;
    n2 = n;
    string name;
    int korean;
    int english;
    int math;
    int total = 0;
    while (n-- > 0) {
        cin >> name >> korean >> english >> math;
        total = korean + english + math;
        v.push_back(make_tuple(total, name, korean, english, math));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n2; ++i) {
        cout << get<1>(v[i]) << " " << get<2>(v[i]) << " "  <<get<3>(v[i]) << " " << get<4>(v[i]) << '\n';
    }

    return 0;
}