//BOJ_9466 텀 프로젝트 [골드 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> S;
bool visited[100005], finished[100005];
int N, cnt;
void DFS(int cur) {
    visited[cur] = true;
    int nxt = S[cur];
    if (visited[nxt]) {
        if (!finished[nxt]) {
            for (int tmp = nxt; tmp != cur; tmp = S[tmp]) cnt++;
            cnt++;
        }
    }
    else DFS(nxt);
    finished[cur] = true;
}
void test_case() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int ip; cin >> ip;
        S.push_back(ip - 1);
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) DFS(i);
    }
    cout << N - cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
        S.clear();
        cnt = 0;
        memset(visited, false, sizeof(visited));
        memset(finished, false, sizeof(finished));
    }
}