//BOJ_4386 별자리 만들기 [골드 3]
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

struct tree {
    int s, e;
    double w;
};
vector<tree> T;

int parent[100005];
int find(int N) {
    if (parent[N] == -1) return N;
    return parent[N] = find(parent[N]);
}
void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[b] = a;
}
vector<pair<double, double>> input;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    memset(parent, -1, sizeof(parent));
    for (int i = 0; i < N; i++) {
        double x, y; cin >> x >> y;
        input.push_back({x, y});
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double dist = pow(input[i].first - input[j].first, 2) + pow(input[i].second - input[j].second, 2);
            T.push_back({i, j, sqrt(dist)});
        }
    }
    sort(T.begin(), T.end(), [](const tree &a, const tree &b){
        return a.w < b.w;
    });

    double ans = 0, cnt = 0;
    for (int i = 0; i < T.size() && cnt < N - 1; i++) {
        int a = T[i].s;
        int b = T[i].e;
        if (find(a) == find(b)) continue;
        merge(a, b);
        
        ans += T[i].w;
        cnt++;
    }
    printf("%.2f\n", ans);

}
