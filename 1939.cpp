//BOJ_1939 중량제한 [골드 3]
//Kruskal - Union Find 로 풀기
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, pair<int, int>>> v;
int parent[10004];
int find(int k) {
    while(parent[k] != k) k = parent[k];
    return k;
}
void merge(int u, int v) {
    int p = find(u);
    int q = find(v);
    parent[p] = q;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;
    int A, B, C;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        v.push_back({C, {A, B}});
    }
    int S, T; cin >> S >> T;
    sort(v.begin(), v.end(), greater<>());

    for (int i = 0; i < 10004; i++) parent[i] = i;

    for (int i = 0; i < v.size(); i++) {
        int p = v[i].second.first;
        int q = v[i].second.second;
        if (find(p) != find(q)) merge(p, q);
        if (find(S) == find(T)) {
            cout << v[i].first << '\n';
            break;
        }
    }
}