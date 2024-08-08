#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

class Student {
public:
    int idx,h,w;
    Student(int idx, int h, int w) {
        this->idx = idx;
        this->h = h;
        this->w = w;
    }
};

bool comp(const Student& a, const Student& b) {
    if (a.h == b.h) {
        if (a.w == b.w) return a.idx < b.idx;
        else return a.w > b.w;
    }
    else return a.h > b.h;
}


int main() {
    
    int n;
    cin >> n;
    vector<Student> v;

    int w;
    int h;
    for (int i = 0; i < n; ++i) {
        cin >> h >> w;
        v.push_back(Student(i + 1, h, w));
   }


    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < n; ++i) {
        cout  << v[i].h << ' ' << v[i].w << ' ' << v[i].idx << '\n';
    }

    return 0;
}