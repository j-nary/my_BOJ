//BOJ_1327 소트 게임 [골드 4]
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int N, K;

int BFS(string S) {
    queue<pair<string, int>> q;
    q.push({S, 0});

    unordered_map<string, bool> visited;
    string D = S;
    sort(D.begin(), D.end());

    while(!q.empty()) {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == D) return cnt;

        if (!visited.count(cur)) {
            visited[cur] = true;

            for (int i = 0; i <= N - K; i++) {
                string tmp = cur.substr(i, K);
                reverse(tmp.begin(), tmp.end());
                q.push({cur.substr(0, i) + tmp + cur.substr(i + K, cur.size()), cnt + 1});
            }
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    string S;
    for (int i = 0; i < N; i++) {
        char ip; cin >> ip;
        S += ip;
    }

    cout << BFS(S) << '\n';
}