//BOJ_10552 DOM [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, M, P;    //어르신, 채널, 초기 채널
vector<pair<int, int>> chn;
bool visited[100005];
int hater[100005];
int cnt;
bool flag;

void DFS(int cur) {
    visited[cur] = true;
    int idx = hater[cur];
    if(idx < 0) return;
    cnt++;
    int tmp = chn[idx].first;
    if (visited[tmp]) flag = true;
    else DFS(tmp);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    memset(hater, -1, sizeof(hater));
    cin >> N >> M >> P;
    for (int i = 0; i < N; i++) {
        int l, h; cin >> l >> h;
        chn.push_back({l, h});
        if (hater[h] < 0) hater[h] = i;
    }
    DFS(P);
    if (flag) cout << -1 << '\n';
    else cout << cnt << '\n';
}