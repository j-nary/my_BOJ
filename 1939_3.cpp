//BOJ_1939 중량제한 [골드 3]
//Priority_queue + Dijkstra 이용하기
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> v[10004];
int N, M, S, T; 
priority_queue<pair<int, int>> pq; //{weight, j}
int length[10004];
bool chk[10004];

int dijkstra() {
    pq.push({1e9, S});
    
    while(!pq.empty()) {
        int cur = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        chk[cur] = 1;

        if (cur == T) return length[T];

        for (int i = 0; i < v[cur].size(); i++) {
            int nxt = v[cur][i].second;
            int nxtW = v[cur][i].first;
            if (chk[nxt]) continue;
            if (length[nxt] < min(w, nxtW)) {
                length[nxt] = min(w, nxtW);
                pq.push({length[nxt], nxt});
            }
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> M;
    int A, B, C;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        v[A].push_back({C ,B});
        v[B].push_back({C ,A});
    }
    cin >> S >> T;
    cout << dijkstra() << '\n';
}