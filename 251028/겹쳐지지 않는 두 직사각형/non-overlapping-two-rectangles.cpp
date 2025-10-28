#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

// N, M이 최대 5이므로 5x5로 정의
#define MAX_NUM 5 

using namespace std;

int N, M;
int grid[MAX_NUM][MAX_NUM];

// R1의 경계를 저장하는 전역 변수 (R1의 모든 좌표를 포함하는 값)
int R1_top, R1_left, R1_bottom, R1_right;

// 첫 번째 직사각형의 합을 계산하고 경계를 저장합니다.
// 유효하지 않은 경우(경계 이탈) -1을 반환합니다.
long long rec1(int i, int j, int k, int p) { // 반환 타입을 long long으로 변경
    // 1. R1이 격자 범위를 벗어나는지 확인
    if (i + k > N || j + p > M) {
        return LLONG_MIN / 2; // 유효하지 않음을 나타내는 매우 작은 값 반환
    }
    
    // 2. R1 경계 저장
    R1_top = i;
    R1_left = j;
    R1_bottom = i + k - 1; // 끝점 포함
    R1_right = j + p - 1;  // 끝점 포함
    
    // 3. R1 합산 (CRITICAL FIX: 루프 변수 r, c를 매번 초기화)
    long long ans = 0; // ans를 long long으로 변경
    for (int r = i; r < i + k; ++r) {
        for (int c = j; c < j + p; ++c) {
            ans += grid[r][c];
        }
    }
    
    return ans;
}

// 두 번째 직사각형의 합을 계산하고, R1과 겹치는지 확인합니다.
// 겹치거나 경계 이탈 시 LLONG_MIN/2을 반환합니다.
long long rec2(int i, int j, int k, int p) { // 반환 타입을 long long으로 변경
    // 1. R2가 격자를 벗어나는지 확인
    if (i + k > N || j + p > M) {
        return LLONG_MIN / 2;
    }
    
    // R2의 경계
    int R2_top = i;
    int R2_left = j;
    int R2_bottom = i + k - 1;
    int R2_right = j + p - 1;

    // 2. R1과 R2가 겹치는지 판정
    // R1의 경계는 전역 변수 (R1_top, R1_left 등)에 있습니다.
    
    // 두 사각형이 겹치지 않을 조건 4가지 (하나라도 참이면 겹치지 않음)
    bool not_overlapped = (R2_right < R1_left) ||   // R2가 R1의 완전히 왼쪽
                          (R2_left > R1_right) ||   // R2가 R1의 완전히 오른쪽
                          (R2_bottom < R1_top) ||   // R2가 R1의 완전히 위쪽
                          (R2_top > R1_bottom);     // R2가 R1의 완전히 아래쪽
    
    if (!not_overlapped) {
        return LLONG_MIN / 2; // 겹침 (유효하지 않음)
    }

    // 3. 겹치지 않으면 합산 (CRITICAL FIX: 루프 변수 r, c를 매번 초기화)
    long long ans = 0; // ans를 long long으로 변경
    for (int r = i; r < i + k; ++r) {
        for (int c = j; c < j + p; ++c) {
            ans += grid[r][c];
        }
    }
    
    return ans;
}

int main() {
    // 빠른 입출력 설정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    
    // 입력된 N, M 크기에 맞춰 grid 배열에 값을 채웁니다.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    // 합이 커질 수 있으므로 long long 사용
    long long max_sum = LLONG_MIN;
    
    // R1 탐색: 시작점 (i, j), 크기 (k, p) -> O(N^4)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 1; k <= N; k++) {
                for (int p = 1; p <= M; p++) {
                    
                    long long R1_sum = rec1(i, j, k, p); // R1_sum을 long long으로 변경
                    // 유효하지 않은 값은 스킵
                    if (R1_sum == LLONG_MIN / 2) continue; 

                    // R2 탐색: 시작점 (z, w), 크기 (x, y) -> O(N^4)
                    for (int z = 0; z < N; z++) {
                        for (int w = 0; w < M; w++) {
                            for (int x = 1; x <= N; x++) {
                                for (int y = 1; y <= M; y++) {
                                    
                                    long long R2_sum = rec2(z, w, x, y); // R2_sum을 long long으로 변경
                                    
                                    // R2가 유효하고 R1과 겹치지 않는다면
                                    if (R2_sum != LLONG_MIN / 2) { 
                                        max_sum = max(max_sum, R1_sum + R2_sum);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << max_sum;
    
    return 0;
}
