//BOJ_1325 효율적인 해킹 [실버 1]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

vector<int> v[10004];
int ans[10004];
bool chk[10004];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        v[b].push_back(a);
    }

    for (int i = 1; i <= 5; i++) {
        memset(chk, false, sizeof(chk));
        queue<int> q;
        q.push(i);
        chk[i] = true;
        int cnt = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            cnt++;

            for (int i = 0; i < v[cur].size(); i++) {
                if (!chk[v[cur][i]]) {
                    chk[v[cur][i]] = true;
                    q.push(v[cur][i]);
                }
            }
        }
        ans[i] = cnt;
    }

    int Max = *max_element(ans, ans + sizeof(ans)/sizeof(ans[0]));
    for (int i = 1; i < N; i++) {
        if (ans[i] == Max) cout << i << " ";
    }
    cout << '\n';
}