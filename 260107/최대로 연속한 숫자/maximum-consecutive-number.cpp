#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 1. 구간을 저장할 set (pair: {시작점, 끝점})
    set<pair<int, int>> ranges;
    // 2. 길이를 저장할 multiset (중복 허용, 자동 정렬)
    multiset<int> lengths;

    // 초기 상태: 0부터 n까지 통째로 하나의 구간
    ranges.insert({0, n});
    lengths.insert(n + 1); // 0~n의 개수는 n+1개

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        // --- 핵심 로직 시작 ---

        // 1. 삭제할 숫자 x가 포함된 구간 찾기
        // ranges는 시작점 기준으로 정렬되어 있음.
        // x보다 시작점이 큰 첫 번째 구간(upper_bound)의 "바로 앞 구간"이 x를 포함함.
        auto it = ranges.upper_bound({x, 2e9}); 
        it--; // 한 칸 뒤로(이전 구간으로) 이동

        // 찾은 구간 정보 가져오기
        int start = it->first;
        int end = it->second;
        int len = end - start + 1;

        // 2. 기존 구간 삭제
        ranges.erase(it); // 구간 목록에서 삭제
        lengths.erase(lengths.find(len)); // 길이 목록에서 삭제 (주의: find로 하나만 찾아서 지움)

        // 3. 쪼개기 & 4. 넣기
        // x 기준으로 왼쪽 구간 (start ~ x-1)
        if (start <= x - 1) {
            ranges.insert({start, x - 1});
            lengths.insert((x - 1) - start + 1);
        }
        // x 기준으로 오른쪽 구간 (x+1 ~ end)
        if (x + 1 <= end) {
            ranges.insert({x + 1, end});
            lengths.insert(end - (x + 1) + 1);
        }

        // --- 핵심 로직 끝 ---

        // 현재 존재하는 길이 중 가장 큰 값 출력
        // multiset은 자동 정렬되므로 맨 뒤(rbegin)가 최댓값
        if (lengths.empty()) cout << 0 << "\n";
        else cout << *lengths.rbegin() << "\n";
    }

    return 0;
}