//BOJ_2254 감옥 건설 [플래티넘 4]
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
#define ll long long

struct P {
    ll x, y, dx, dy;
    P(ll x = 0, ll y = 0)
        : x(x), y(y), dx(1), dy(0) {}
    bool operator==(P& p) {
        return x == p.x && y == p.y;
    }
};

vector<P> v;
vector<int> st;
int N;
P PS;

int CCW(const P &p1, const P &p2, const P &p3) {
    ll res = (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);

    if (res > 0) return 1;   // 반시계
    else if (res < 0) return -1;   // 시계
    else return 0;
}

bool cmp (P a, P b) {
    //반시계 정렬
    if (a.dy * b.dx != a.dx * b.dy)
        return a.dy * b.dx < a.dx * b.dy;
    if (a.y != b.y)
        return a.y < b.y;
    return a.x < b.x;
}

bool convexHull() {
    N = v.size();
    if (N < 3) return false;

    st.clear();
    st.push_back(0);
    st.push_back(1);

    P p1, p2;
    int p1Idx, p2Idx;
    for (int i = 2; i < N; i++) {
        while (st.size() >= 2) {
            p2Idx = st.back();
            p2 = v[p2Idx];
            st.pop_back();
            p1Idx = st.back();
            p1 = v[p1Idx];
            if (CCW(p1, p2, v[i]) == 1) {
                st.push_back(p2Idx);
                break;
            }
        }
        st.push_back(i);
    }

    if (st.size() < 3) return false;

    p1Idx = st.back(); st.pop_back();
    int sIdx = p1Idx;
    p2Idx = st.back(); st.pop_back();
    int dir = CCW(v[p1Idx], v[p2Idx], PS);

    set<int> w;
    w.insert(p1Idx);
    w.insert(p2Idx);

    while(!st.empty()) {
        p1Idx = p2Idx;
        p2Idx = st.back(); st.pop_back();
        if (dir != CCW(v[p1Idx], v[p2Idx], PS)) return false;
        w.insert(p2Idx);
    }
    if (dir != CCW(v[p2Idx], v[sIdx], PS)) return false;

    vector<P> nv;
    for (int i = 0; i < N; i++) {
        if (w.count(i)) continue;
        nv.push_back(v[i]);
    }
    v = nv;
    return true;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int X, Y;
    cin >> N >> X >> Y;
    PS = P(X, Y);
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        v.push_back(P(x, y));
    }

    int ans = 0;
    while(!v.empty()) {
        sort(v.begin(), v.end(), cmp);
        for (int i = 1; i < v.size(); i++) {
            v[i].dx = v[i].x - v[0].x;
            v[i].dy = v[i].y - v[0].y;
        }
        sort(v.begin() + 1, v.end(), cmp);
        if (!convexHull()) break;
        ans++;
    }

    cout << ans << '\n';
}