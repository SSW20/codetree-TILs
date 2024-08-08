#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
    string name;
    int korean;
    int english;
    int math;

    Student(string name, int korean, int english, int math) {
        this->name = name;
        this->korean = korean;
        this->english = english;
        this->math = math;
    }
};

bool comp(const Student& a, const Student& b) {
    if (a.english == b.english) return a.math > b.math;
    else if (a.korean == b.korean) return a.english > b.english;
    else return a.korean > b.korean;
}

int main() {
    
    int n;
    cin >> n;
    vector<Student> v;

    string name;
    int korean;
    int english;
    int math;
    while (n-- > 0) {
        cin >> name >> korean >> english >> math;
        v.push_back(Student(name, korean, english, math));
    }

    sort(v.begin(), v.end(), comp);

    for (Student p : v) {
        cout << p.name << " " << p.korean << " " << p.english<< " " << p.math << '\n';
    }

    return 0;
}