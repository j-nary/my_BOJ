//BOJ_6479 전력난 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct tree {
    int s, e, w;
};
vector<tree> v;
int parent[200005];
int find(int N) {
    if (parent[N] == -1) return N;
    return parent[N] = find(parent[N]);
}
void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[b] = a;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while(1) {
        int N, M; cin >> N >> M;
        if (N == 0 && M == 0) break;
        v.clear();
        memset(parent, -1, sizeof(parent));
        int total = 0;
        for (int i = 0; i < M; i++) {
            int a, b, c; cin >> a >> b >> c;
            v.push_back({a, b, c});
            total += c;
        }

        sort(v.begin(), v.end(), [](const tree &a, const tree &b) {
            return a.w < b.w;
        });

        int ans = 0, cnt = 0;
        for (int i = 0; i < v.size() && cnt < M - 1; i++) {
            int s = v[i].s;
            int e = v[i].e;
            if (find(s) == find(e)) continue;
            merge(s, e);
            cnt++;
            ans += v[i].w;
        }
        cout << total - ans << '\n';
    }
}