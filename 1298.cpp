//BOJ_1298 노트북의 주인을 찾아서 [플래티넘 4]
//문제해결 기말고사 대비 연습
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> adj[102];
bool chk[102];
int A[102], B[102];

bool DFS(int idx) {
    chk[idx] = true;
    for (int i = 0; i < adj[idx].size(); i++) {
        int mat = adj[idx][i];
        if (!B[mat] || !chk[B[mat]] && DFS(B[mat])) {
            A[idx] = mat;
            B[mat] = idx;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] == 0) {
            memset(chk, false, sizeof(chk));
            if(DFS(i)) ans++;
        }
    }

    cout << ans << '\n';
}