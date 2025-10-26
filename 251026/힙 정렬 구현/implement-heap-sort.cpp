#include <iostream>

using namespace std;

int n;
int arr[100001];
void heapify(int index, int size)
{
    int left = index * 2;
    int right = index * 2 + 1;
    int result = index;

    if (left > size && right > size) return;
    if (left <= size && right > size && arr[index] < arr[left])
    {
        if (arr[index] < arr[left])
        {
            result = left;
            int temp = arr[index];
            arr[index] = arr[left];
            arr[left] = temp;
        }
    }
    if (right <= size && left > size && arr[index] < arr[right])
    {
        if (arr[index] < arr[right])
        {
            result = right;
            int temp = arr[index];
            arr[index] = arr[right];
            arr[right] = temp;
        }
    }
    else
    {
        if (arr[index] < arr[left] && left <= size)
        {
            if (arr[left] < arr[right])
            {
                result = right;
                int temp = arr[index];
                arr[index] = arr[right];
                arr[right] = temp;
            }
            else
            {
                result = left;
                int temp = arr[index];
                arr[index] = arr[left];
                arr[left] = temp;
            }
        }
        else if(arr[index] < arr[right] && right <= size)
        {
            if (arr[right] < arr[left])
            {
                result = left;
                int temp = arr[index];
                arr[index] = arr[left];
                arr[left] = temp;
            }
            else
            {
                result = right;
                int temp = arr[index];
                arr[index] = arr[right];
                arr[right] = temp;
            }
        }
        else
        {
            return;
        }
    }

    if (result == index) return;
    else {
        heapify(result, size);
        return;
    }

}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = n / 2; i > 0; i--)
    {
        heapify(i, n);
    }

    for (int i = n; i > 1; i--)
    {
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;

        heapify(1, i - 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
   

    // Please write your code here.


    return 0;
}
