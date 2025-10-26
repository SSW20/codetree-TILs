#include <iostream>

#define MAX_N 100

using namespace std;

int n;
int arr[MAX_N];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
     for (int i = 1; i < n; i++) {
        int key = arr[i]; 
       for (int k = i; k >0; k--)
       {
            if(arr[k-1] > key)
            {
                int temp = arr[k];
                arr[k] = arr[k - 1];
                arr[k - 1] = temp;
            }
        
       }
    }


    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}
