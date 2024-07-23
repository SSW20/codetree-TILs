#include <iostream>
using namespace std;

bool isValid(int *a, int *b, int n1, int n2){
    bool flag = false;
    for(int i=0; i<n1; ++i){
        if(a[i] == b[0]){
            flag = true;
            for(int k=0; k<n2; ++k){
                if(a[i+k] != b[k]){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) return flag;
    }
    return flag;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n1,n2;
    cin >> n1 >> n2;
    int *arr = new int[n1];
    int *arr2 = new int[n2];

    for(int i=0;i<n1; ++i){cin >> arr[i];}
    for(int i=0;i<n2; ++i){cin >> arr2[i];}
    if(isValid(arr,arr2,n1,n2)) cout << "Yes";
    else cout << "No";

    return 0;
}