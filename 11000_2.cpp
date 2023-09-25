//BOJ_11000 강의실 배정 [골드 5]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int S, T;
    bool operator <(const node s) const {
        if (s.S == this -> S) return this->T < s.T;
        return this->S > s.S;
    }
};
struct pqnode {
    int v;
    bool operator <(const pqnode pq) const {
        return this->v > pq.v;
    }
};
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    priority_queue<node> pq;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int S, T; cin >> S >> T;
        pq.push({S, T});
    }
    
    int ans = 1;
    int tmp = 0;

    priority_queue<pqnode> C;
    while(!pq.empty()) {
        int S = pq.top().S;
        int T = pq.top().T;
        pq.pop();

        if (!C.empty()) {
            pqnode cs = C.top(); C.pop();
            if (cs.v > S) {
                C.push(cs);
                ans++;
            }
        }
        C.push({T});
    }

    cout << ans << '\n';
}