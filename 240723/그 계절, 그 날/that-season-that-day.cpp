#include <iostream>
using namespace std;

int lastDate(int y,int m){
    if(y % 4 == 0 && m == 2) {
      if(y % 100 == 0 && y % 400 != 0) return 28;
      return 29;   
    }
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
    else return 30;
}

bool isValidDate(int y,int m, int d){
    return (lastDate(y,m) >= d);
}

void printSeason(int m){
    if(m == 12 || m == 1 || m == 2) cout << "Winter";
    if(m == 11 || m == 9 || m == 10) cout << "Fall";
    if(m == 8  || m == 7 || m == 6) cout << "Summer";
    if(m == 5  || m == 4 || m == 3) cout << "Spring";
}


int main() {
    // 여기에 코드를 작성해주세요.
    int y,m,d;
    cin >> y >> m >> d;
    if(isValidDate(y,m,d)){
        printSeason(m);
    }
    else cout << -1;
    return 0;
}