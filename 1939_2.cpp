//BOJ_1939 중량제한 [골드 3]
//BFS + Parametric Search 이용하기
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int S, T;
vector<pair<int, int>> v[10004];
bool chk[10004];
bool BFS(int w) {
    queue<int> q;
    q.push(S);
    chk[S] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == T) return true;
        for (int i = 0; i < v[cur].size(); i++) {
            int nxt = v[cur][i].first;
            int nxtW = v[cur][i].second;

            if (!chk[nxt] && w <= nxtW) {
                q.push(nxt);
                chk[nxt] = 1;
            }
        }
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;
    int A, B, C;
    int left = 0, right = 0;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        v[A].push_back({B, C});
        v[B].push_back({A, C});
        right = max(right, C);
    }
    cin >> S >> T;
    int mid = (left + right) / 2;
    while (left <= right) {
        memset(chk, false, sizeof(chk));
        if (BFS(mid)) left = mid + 1;
        else right = mid - 1;   
        mid = (left + right) / 2;
    }
    cout << mid << '\n';
}