//BOJ_1774 우주신과의 교감 [골드 3]
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

struct tree {
    int s, e; double w;
    bool operator<(const tree& a) const {
        return this -> w < a.w;
    }
};

vector<tree> T;
int parent[1003];

int find(int N) {
    if (!parent[N]) return N;
    return parent[N] = find(parent[N]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    
    vector<pair<int, int>> shin;
    shin.push_back({-1, -1});
    for (int i = 0; i < N; i++) {
        int X, Y; cin >> X >> Y;
        shin.push_back({X, Y});
    }

    for (int i = 0; i < M; i++) {
        int sIdx, eIdx;
        cin >> sIdx >> eIdx;
        merge(sIdx, eIdx);
    }

    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            double dist = (double)pow(shin[i].first - shin[j].first, 2) + (double)pow(shin[i].second- shin[j].second, 2);
            dist = sqrt(dist);
            T.push_back({i, j, dist});
        }
    }

    sort(T.begin(), T.end());

    double ans = 0;
    for (int i = 0; i < T.size(); i++) {
        if (find(T[i].s) == find(T[i].e)) continue;
        merge(T[i].s, T[i].e);
        ans += T[i].w;
    }

    cout << fixed << setprecision(2) << round(ans * 100) / 100.0 << '\n';
}

// . 3 . 4
// .
// 1 . 2