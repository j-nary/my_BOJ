//BOJ_2887 행성 터널 [플래티넘 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<pair<int, int>> input[3];
struct tree{
    int s, e, w;
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
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    memset(parent, -1, sizeof(parent));
    for (int i = 0; i < N; i++) {
        int x, y, z; cin >> x >> y >> z;
        input[0].push_back({x, i});
        input[1].push_back({y, i});
        input[2].push_back({z, i});
    }

    sort(input[0].begin(), input[0].end());
    sort(input[1].begin(), input[1].end());
    sort(input[2].begin(), input[2].end());

    for (int i = 0; i < N - 1; i++) {
        T.push_back({input[0][i].second, input[0][i + 1].second, abs(input[0][i].first - input[0][i + 1].first)});
        T.push_back({input[1][i].second, input[1][i + 1].second, abs(input[1][i].first - input[1][i + 1].first)});
        T.push_back({input[2][i].second, input[2][i + 1].second, abs(input[2][i].first - input[2][i + 1].first)});
    }
    
    sort(T.begin(), T.end(), [](const tree &a, const tree &b){
        return a.w < b.w;
    });

    int ans = 0, cnt = 0;
    for (int i = 0; i < T.size() && cnt < N - 1; i++) {
        int s = T[i].s, e = T[i].e;
        if (find(s) == find(e)) continue;
        merge(s, e);
        ans += T[i].w;
        cnt++;
    }
    cout << ans << '\n';
}