//BOJ_11403 경로 찾기 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N;
bool adj[102][102];
bool ans[102][102];
bool visited[102];
void DFS(int cur) {
    for (int i = 1; i <= N; i++) {
        if (!adj[cur][i]) continue;
        if (visited[i]) continue;
        visited[i] = true;
        DFS(i);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> adj[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        DFS(i);
        for (int j = 1; j <= N; j++) {
            if (visited[j]) ans[i][j] = 1;
        }
        memset(visited, false, sizeof(visited));
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << (int)ans[i][j] << " ";
        }
        cout << '\n';
    }
}