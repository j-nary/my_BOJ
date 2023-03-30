//BOJ_1240 노드사이의 거리 [골드 5]
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool check[1003];
vector<pair<int, int>> tree[1003];
int bfs(int x, int y) {
    memset(check, false, sizeof(check));
    queue<pair<int, int>> q;    //node, dist
    for (int i = 0; i < tree[x].size(); i++) {
        q.push({tree[x][i].first, tree[x][i].second});
    }

    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (node == y) return dist;
        for (int i = 0; i < tree[node].size(); i++) {
            if (check[tree[node][i].first] == 1) continue;
            check[tree[node][i].first] = 1;
            q.push({tree[node][i].first, dist + tree[node][i].second});
        }
    }

    return 0;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N - 1; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        tree[x].push_back({y, d});
        tree[y].push_back({x, d});
    }

    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        cout << bfs(x, y) << '\n';
    }
    
}