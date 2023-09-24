//BOJ_1774 우주신과의 교감 [골드 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int parent[1003];
int find(int N) {
    if (parent[N] == -1) return N;
    return parent[N] = find(parent[N]);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    memset(parent, -1, sizeof(parent));
    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        
    }
}