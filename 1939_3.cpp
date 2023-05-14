//BOJ_1939 중량제한 [골드 3]
//Priority_queue + Dijkstra 이용하기
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int, int>> pq; //{length, idx}
int length[10004];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;
    int A, B, C;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        v.push_back({C, {A, B}});
    }
    int S, T; cin >> S >> T;
}