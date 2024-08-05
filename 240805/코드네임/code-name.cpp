#include <iostream>
#include <vector>
using namespace std;

class Student{
    public:
        char grade;
        int score;
        Student(char grade, int score){
            this->grade = grade;
            this->score = score;
        }
};

int main() {
    // 여기에 코드를 작성해주세요.
    char c;
    int s;
    vector<Student*> v;
    for(int i=0; i<5; ++i){
        cin >> c >> s;
        v.push_back(new Student(c,s));
    }
    int idx;
    int min = 999;
    for(int i=0; i<5; ++i){
        if(min > v[i]->score) {min = v[i]->score; idx = i;}
    }
    cout << v[idx]->grade << " " << v[idx]->score;

    return 0;
}