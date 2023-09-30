//BOJ_28813 축제 부스 기획하기 2
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int x, y, idx;
    double dist() const {
        return max(abs(x), abs(y));
    }
    bool operator<(const node& other) const {
        return dist() < other.dist();
    }
};
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<node> D;
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int x, y;  cin >> x >> y;
        D.push_back({x, y, i});
    }

    vector<int> E;
    sort(D.begin(), D.end());
    for(int i = 0; i < N; i++) {
        if (D[i].dist() < i + 1) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << D[i].idx << ' ';
    }
    cout << '\n';

}