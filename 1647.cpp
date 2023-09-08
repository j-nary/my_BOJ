//BOJ_1647 도시 분할 계획 [골드 4]
//BOJ_1922 네트워크 연결 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct tree {
    int s, e, w;
};
vector<tree> T;
int parent[100005];
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

    int N, M; cin >> N >> M;
    int a, b, c; 
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        T.push_back({a, b, c});
    }
    sort(T.begin(), T.end(), [](const tree &a, const tree &b){
        return a.w < b.w;
    });

    int ans = 0, cnt = 0;
    for (int i = 0; i < T.size() && cnt < N - 2; i++) {
        int a = T[i].s;
        int b = T[i].e;
        if (find(a) == find(b)) continue;
        merge(a, b);
        
        ans += T[i].w;
        cnt++;
    }
    cout << ans << '\n';
}