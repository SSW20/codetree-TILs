#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

class Student {
public:
    int h;
    double w;
    string name;
    Student(string name , int h, double w) {
        this->name = name;
        this->h = h;
        this->w = w;
    }
};

bool comp(const Student& a, const Student& b) {
    return a.h > b.h;
}

bool comp2(const Student& a, const Student& b) {
    return a.name < b.name;
}


int main() {
    vector<Student> v;

    double w;
    int h;
    string name;
    for (int i = 0; i < 5; ++i) {
        cin >> name >> h >> w;
        v.push_back(Student(name, h, w));
   }


    sort(v.begin(), v.end(), comp2);

    cout << "name\n";
    cout << fixed;
    cout.precision(1);
    for (int i = 0; i < 5; ++i) {
        cout  << v[i].name << ' ' << v[i].h << ' ' << v[i].w  << '\n';
    }

    sort(v.begin(), v.end(), comp);

    cout << "\nheight\n";
    for (int i = 0; i < 5; ++i) {
        cout << v[i].name << ' ' << v[i].h << ' ' << v[i].w << '\n';
    }

    return 0;
}