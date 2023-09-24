//BOJ_28813 축제 부스 기획하기 2
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int x, y, idx;
    double dist() const {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
    bool operator<(const node& other) const {
        return dist() > other.dist();
    }
};
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    priority_queue<node> D;
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int x, y;  cin >> x >> y;
        D.push({x, y, i});
    }

    vector<int> E;
    while(!D.empty()) {
        //드론 제거
        node curr = D.top();
        E.push_back(curr.idx);
        D.pop();

        //드론 이동
        priority_queue<node> nD;
        while(!D.empty()) {
            node d = D.top(); D.pop();
            if (d.x == 0) {
                if (d.y > 0) d.y--;
                else d.y++;
            } else if (d.y == 0) {
                if (d.x > 0) d.x--;
                else d.x++;
            } else {
                if (d.x > 0) d.x--;
                else d.x++;
                if (d.y > 0) d.y--;
                else d.y++;
            }
            if (!d.x && !d.y) {
                cout << -1 << '\n';
                return 0;
            }
            nD.push(d);
        }
        D = nD;
    }
    for (int i = 0; i < E.size(); i++) {
        cout << E[i] << ' ';
    }
    cout << '\n';
}