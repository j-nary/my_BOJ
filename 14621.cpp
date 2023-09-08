//BOJ_14621 나만 안되는 연애 [골드 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int Univ[1003]; //여자 1 남자 0
struct tree{
    int w, s, e;
};
vector<tree> T;
int parent[1003];
int find(int N) {
    if (parent[N] == 0) return N;
    return parent[N] = find(parent[N]);
}
void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[b] = a;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        char input; cin >> input;
        if (input == 'W') Univ[i] = 1;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (Univ[a] == Univ[b]) continue;
        T.push_back({c, a, b});
    }
    sort(T.begin(), T.end(), [](const tree &a, const tree &b) {
        return a.w < b.w;
    });
    int ans = 0, cnt = 0;
    for (int i = 0; i < T.size() && cnt < N - 1; i++) {
        int s = T[i].s;
        int e = T[i].e;
        if (find(s) == find(e)) continue;
        merge(s, e);
        cnt++;
        ans += T[i].w;
    }
    if (cnt < N - 1) cout << -1 << '\n';
    else cout << ans << '\n';
}