//BOJ_1197 최소 스패닝 트리 [골드 4]
//크루스칼 알고리즘
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct tree {
    int s, e, w;
};
vector<tree> T;
int parent[10004];

int find(int N) {
    if (!parent[N]) return N;
    return parent[N] = find(parent[N]);
}
void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int V, E; cin >> V >> E;
    int A, B, C;
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        T.push_back({A, B, C});
    }

    sort(T.begin(), T.end(), [](const tree &A, const tree &B){
        return A.w < B.w;
    });

    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < T.size() && cnt <= V - 1; i++) {
        int a = T[i].s;
        int b = T[i].e;
        if (find(a) == find(b)) continue;
        merge(a, b);
        ans += T[i].w;
        cnt++;
    }

    cout << ans << '\n';
}