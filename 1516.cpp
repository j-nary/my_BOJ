//BOJ_1516 게임 개발 [골드 3]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

vector<int> adj[503];
int Time[503];
int indegree[503];
int ans[503];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        cin >> Time[i];
        int ip;
        while(1) {
            cin >> ip;
            if (ip == -1) break;
            adj[ip].push_back(i);
            indegree[i]++;
        }
        if (indegree[i] == 0) {
            q.push(i);
            ans[i] = Time[i];
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int nxt: adj[cur]) {
            ans[nxt] = max(ans[nxt], ans[cur] + Time[nxt]);
            if (--indegree[nxt] == 0) q.push(nxt);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << '\n';
    }
}