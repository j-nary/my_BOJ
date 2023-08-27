//BOJ_4195 친구 네트워크 [골드 2]
#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int parent[100005];
int nodeCnt[100005];
map<string, int> m;
int cnt;
int find(int a) {
    if (parent[a] < 0) return a;
    return parent[a] = find(parent[a]);
}
int merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
}
void test_case() {
    m.clear(); cnt = 0;
    fill(parent, parent + F, -1);

    int F; cin >> F;
    string a, b;
    for (int i = 0; i < F; i++) {
        cin >> a >> b;
        if (m.find(a) == m.end()) m.insert({a, cnt++});
        if (m.find(b) == m.end()) m.insert({b, cnt++});

        int aa = m.find(a)->second;
        int bb = m.find(b)->second;

        merge(aa, bb);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}