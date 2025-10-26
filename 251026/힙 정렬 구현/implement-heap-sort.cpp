#include <iostream>

using namespace std;

int n;
int arr[100001]; // 1-based indexing을 위해 100001로 선언

/**
 * 힙 속성을 복구하는 함수 (Max Heap 기준)
 * @param index 현재 힙으로 만들려는 서브트리의 루트 노드 인덱스
 * @param size  현재 힙의 *전체 크기* (이 값을 벗어나는 인덱스는 힙의 일부가 아님)
 */
void heapify(int index, int size)
{
    // 1. 현재 노드(부모), 왼쪽 자식, 오른쪽 자식 인덱스 계산 (1-based)
    int parent = index;
    int left = index * 2;
    int right = index * 2 + 1;

    // 2. '가장 큰 값'을 가진 노드의 인덱스를 찾는다 (일단 부모를 가장 크다고 가정)
    int largest = parent;

    // 3. 왼쪽 자식과 비교
    // (왼쪽 자식이 힙 크기 안에 있고) && (왼쪽 자식이 현재 'largest'보다 크면)
    if (left <= size && arr[left] > arr[largest]) {
        largest = left;
    }

    // 4. 오른쪽 자식과 비교
    // (오른쪽 자식이 힙 크기 안에 있고) && (오른쪽 자식이 현재 'largest'보다 크면)
    if (right <= size && arr[right] > arr[largest]) {
        largest = right;
    }

    // 5. 'largest'가 부모(index)가 아니라면 (즉, 자식 중 더 큰 값이 있다면)
    if (largest != index) {
        // 5-1. 부모와 가장 큰 자식의 값을 교환(swap)합니다.
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;

        // 5-2. 값이 아래로 내려간 자식 노드(largest)에 대해
        //      하위 트리도 힙 속성을 만족하도록 재귀 호출합니다.
        heapify(largest, size);
    }
    
    // (만약 largest == index 라면, 부모가 이미 가장 큰 것이므로
    //  힙 속성을 만족. 재귀를 종료합니다.)
}


int main() {
    cin >> n;

    // [입력] 1번 인덱스부터 n번 인덱스까지 값을 받음
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // [1단계: 힙 구성 (Build Max Heap)]
    // 마지막 잎이 아닌 노드(n/2)부터 루트(1)까지 heapify 수행
    for (int i = n / 2; i > 0; i--)
    {
        heapify(i, n);
    }

    // [2단계: 힙 정렬]
    // 힙의 크기를 1씩 줄여가며 정렬 수행
    for (int i = n; i > 1; i--)
    {
        // 2-1. 현재 힙의 루트(최댓값)와 힙의 마지막 원소를 교환
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;

        // 2-2. 루트(1)가 망가졌으므로, 힙 크기를 1 줄여서(i-1)
        //      루트(1)에 대해 heapify 수행
        heapify(1, i - 1);
    }

    // [출력]
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
    
    return 0;
}