#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
public:
    string name;
    int height;
    int weight;

    Person(string name, int h, int w) {
        this->name = name;
        height = h;
        weight = w;
    }
};

int main() {
    
    int n;
    cin >> n;
    vector<Person> v;

    string name;
    int height;
    int weight;
    while (n-- > 0) {
        cin >> name >> height >> weight;
        v.push_back(Person(name, height, weight));
    }

    sort(v.begin(), v.end(), [](const Person& a, const Person& b) {
        return a.height < b.height;
        });

    for (Person p : v) {
        cout << p.name << " " << p.height << " " << p.weight << '\n';
    }

    return 0;
}