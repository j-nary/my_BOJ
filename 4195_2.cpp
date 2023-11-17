//BOJ_4195 친구 네트워크 [골드 2]
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>

using namespace std;

int parent[200005];
int friends[200005];
int find(int N) {
    if (!parent[N]) return N;
    return parent[N] = find(parent[N]);
}
void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    parent[b] = a;
    friends[a] += friends[b];
    cout << friends[a] << '\n';
}
void test_case() {
    memset(parent, 0, sizeof(parent));
    // memset(friends, 1, sizeof(friends));
    fill(friends, friends + 200005, 1);

    unordered_map<string, int> m;
    int cnt = 0;
    int F; cin >> F;
    for (int i = 0; i < F; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (!m.count(s1)) m[s1] = ++cnt; // m에 s1이 없으면 새 인덱스 할당
        if (!m.count(s2)) m[s2] = ++cnt; // m에 s2가 없으면 새 인덱스 할당
        merge(m[s1], m[s2]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}