//BOJ_20040 사이클 게임 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int parent[500005];
int find(int N) {
    if (parent[N] < 0) return N;
    return parent[N] = find(parent[N]);
}
void merge(int a, int b) {
    a = find(a);
    b = find(b);
    // if (a == b) return;
    parent[b] = a;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    fill(parent, parent + N, -1);
    for (int i = 1; i <= M; i++) {
        int a, b; cin >> a >> b;
        if (find(a) == find(b)) {
            cout << i << '\n';
            return 0;
        }
        merge(a, b);
    }
    cout << 0 << '\n';
}