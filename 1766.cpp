//BOJ_1766 문제집 [골드 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

vector<int> adj[32003];
int indegree[32003];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) pq.push(i);
    }

    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        cout << cur << " ";

        for (int nxt: adj[cur]) {
            if (--indegree[nxt] == 0) pq.push(nxt);
        }
    }
    cout << '\n';
}