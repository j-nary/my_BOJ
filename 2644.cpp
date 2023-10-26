//BOJ_2644 촌수계산 [실버 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int N;
bool adj[102][102];
bool chk[102];
int BFS(int cur, int dst, int dep) {
    chk[cur] = true;
    queue<pair<int, int>> q;
    q.push({cur, dep});
    while(!q.empty()) {
        cur = q.front().first;
        dep = q.front().second;
        q.pop();
        if (cur == dst) return dep;
        chk[cur] = true;

        for (int i = 1; i <= N; i++) {
            if (!adj[cur][i]) continue;
            if (chk[i]) continue;
            q.push({i, dep + 1});
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    int S, E; cin >> S >> E;
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        adj[x][y] = true;
        adj[y][x] = true;
    }

    cout << BFS(S, E, 0) << '\n';
}