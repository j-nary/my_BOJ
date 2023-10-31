//BOJ_18352 특정 거리의 도시 찾기 [실버 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

vector<int> adj[300005];
bool chk[300005];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M, K, X; cin >> N >> M >> K >> X;
    for (int i = 0; i < M; i++) {
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
    }

    queue<pair<int, int>> q;
    q.push({X, 0});
    chk[X] = true;
    vector<int> ans;
    while(!q.empty()) {
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();

        if (d == K) ans.push_back(cur);
        else if (d > K) continue;

        for (int i = 0; i < adj[cur].size(); i++) {
            int tmp = adj[cur][i];
            if (!chk[tmp]) {
                q.push({tmp, d + 1});
                chk[tmp] = true;
            }
        }
    }

    if (!ans.size()) {
        cout << -1 << '\n';
        return 0;
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}