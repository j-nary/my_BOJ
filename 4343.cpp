//BOJ_4343 Arctic Network [골드 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct tree{
    int s, e;
    double w;
    bool operator<(const tree &t) const {
        return this->w < t.w;
    }
};
int parent[502];
int find(int N) {
    if (parent[N] == -1) return N;
    return parent[N] = find(parent[N]);
}
void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[b] = a;
}
void test_case() {
    int S, P; cin >> S >> P;
    vector<pair<int, int>> input;
    vector<tree> T;
    memset(parent, -1, sizeof(parent));
    for (int i = 0; i < P; i++) {
        int x, y; cin >> x >> y;
        input.push_back({x, y});
    }
    for (int i = 0; i < P; i++) {
        for (int j = i + 1; j < P; j++) {
            double dist = pow(input[i].first - input[j].first, 2) + pow(input[i].second - input[j].second, 2);
            dist = sqrt(dist);
            T.push_back({i, j, dist});
        }
    }
    sort(T.begin(), T.end());

    vector<double> ans;
    for (auto& t: T) {
        if (find(t.s) == find(t.e)) continue;
        merge(t.s, t.e);
        ans.push_back(t.w);
    }
    printf("%.2f\n", ans[ans.size() - S]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}