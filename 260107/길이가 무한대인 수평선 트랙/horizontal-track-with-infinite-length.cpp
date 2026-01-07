#include <iostream>

using namespace std;

int N, T;
int start[100000];
int speed[100000];

int main() {
    cin >> N >> T;

    for (int i = 0; i < N; i++) {
        cin >> start[i] >> speed[i];
    }

    // 속도가 뒤가 더 빠름 << 다른 그룹 

    // 속도가 같음 << 다른 그룹

    // 속도가 느려 --> 뒤 - 앞 출발점 - T(앞속도 - 뒤속도) <= 0 만나니까 같은 그룹
                                // 아니면 다른 그룹
    long long int ans = 0;
    long long int lastStart = 0;
    long long lastSpeed = 0;
    for (int i = 0; i < N; i++) {
        if (lastSpeed <= speed[i])
        {
            lastSpeed = speed[i];
            lastStart = start[i];
            ++ans;
        }

        else
        {
            if (start[i] - lastStart - T * (lastSpeed - speed[i]) <= 0)
            {
                lastSpeed = speed[i];
                lastStart = start[i];
            }
            else
            {
                lastSpeed = speed[i];
                lastStart = start[i];
                ++ans;
            }
        }
    }
    cout << ans;

    return 0;
}
