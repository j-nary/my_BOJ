//BOJ_2887 행성 터널 [플래티넘 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct point{
    int x, y, z;
};
vector<point> input;
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
        input.push_back({x, y, z});
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int weight = min({abs(input[i].x - input[j].x), abs(input[i].y - input[j].y), abs(input[i].z - input[j].z)});
            T.push_back({i, j, weight});
        }
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