#include <iostream>

using namespace std;

long long int N, T;
long long int start[100000];
long long int speed[100000];

int main() {
    cin >> N >> T;

    for (int i = 0; i < N; i++) {
        cin >> start[i] >> speed[i];
    }
    // last 갱신 어케함?

    // 속도가 뒤가 더 빠름 << 다른 그룹 

    // 속도가 같음 << 다른 그룹

    // 속도가 느려 --> 뒤 - 앞 출발점 - T(앞속도 - 뒤속도) <= 0 만나니까 같은 그룹
                                // 아니면 다른 그룹
    long long int ans = 1;
    long long int lastStart = 0;
    long long LastDistance = speed[N - 1] * T + start[N - 1];
    for (int i = N - 2 ; i > -1; i--) {
        long long int CurDistance = speed[i] * T + start[i];

        if (CurDistance < LastDistance)
        {
            LastDistance = CurDistance;
            ++ans;
        }
    }
    cout << ans;

    return 0;
}
