#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Person{
    public:
        string name;
        string addr;
        string city;
        Person(string n,string a, string c){
            this->name  = n;
            this->addr = a;
            this->city = c;
        }
};

int main() {
    // 여기에 코드를 작성해주세요.
    string name;
    string addr;
    string city;

    vector<Person*> v;
    int n;
    cin>> n;
    for(int i=0;i<n;++i){
        cin >> name >> addr >> city;
        v.push_back(new Person(name,addr,city));
    }

    sort(v.begin(),v.end());
    cout << "name " << v[n-1]->name << '\n';
    cout << "addr " << v[n-1]->addr << '\n';
    cout << "city " << v[n-1]->city << '\n';
    

    return 0;
}