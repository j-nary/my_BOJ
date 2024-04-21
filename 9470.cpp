//BOJ_9470 Strahler 순서 [골드 3]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int W[1003];
int indegree[1003];
void test_case() {
    memset(W, 0, sizeof(W));
    memset(indegree, 0, sizeof(indegree));
    vector<int> adj[1003];
    vector<int> adjW[1003];

    int K, M, P;
    cin >> K >> M >> P;

    for (int i = 0; i < P; i++) {
        int A, B;
        cin >> A >> B;
        indegree[B]++;
        adj[A].push_back(B);
    }

    queue<int> q;
    for (int i = 1; i <= M; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            W[i] = 1;
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        int weight = 0;
        if (adjW[cur].size() == 1) {
            W[cur] = W[adjW[cur][0]];
        } else if (adjW[cur].size() > 1){
            int first = W[adjW[cur][0]];
            int second = W[adjW[cur][1]];
            weight = (first == second) ? first + 1 : max(first, second);
            for (int i = 2; i < adjW[cur].size(); i++) {
                weight = (weight == W[adjW[cur][i]]) ? weight + 1 : max(weight, W[adjW[cur][i]]);
            }
            W[cur] = weight;
        }

        for (int nxt: adj[cur]) {
            adjW[nxt].push_back(cur);
            if (--indegree[nxt] == 0) q.push(nxt);
        }
    }

    cout << K << " " << W[M] << '\n';

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}