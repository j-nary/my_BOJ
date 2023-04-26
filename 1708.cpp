//BOJ_1708 블록 껍질 [플래티넘 5]

#include <iostream>
#include <algorithm>
#include <vector>

#define px first
#define py second
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

vector<P> v;
vector<P> st;

int CCW(const P &p1, const P &p2, const P &p3) {
    ll res = (p1.px * p2.py + p2.px * p3.py + p3.px * p1.py) - (p2.px * p1.py + p3.px * p2.py + p1.px * p3.py);

    if (res > 0) return 1;   // 반시계
    else if (res < 0) return -1;   // 시계
    else return 0;
}

ll Dist(P a, P b) {
    ll dx = b.px - a.px;
    ll dy = b.py - a.py;
    return dx * dx + dy * dy;
}
bool cmp1 (P a, P b) {
    //첫 시작점 잡는 정렬
    if (a.py != b.py) return a.py < b.py;
    else return a.px < b.px;
}
bool cmp2 (P a, P b) {
    //반시계 정렬
    int c = CCW(v[0], a, b);
    if (c) return c > 0;    //각도 작은 순서로
    else return Dist(v[0], a) < Dist(v[0], b);  //일직선
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), cmp1);
    sort(v.begin() + 1, v.end(), cmp2);

    st.push_back(v[0]);
    st.push_back(v[1]);
    P p1, p2;
    for (int i = 2; i < N; i++) {
        while (st.size() >= 2) {
            p2 = st.back();
            st.pop_back();
            p1 = st.back();
            if (CCW(p1, p2, v[i]) == 1) {
                st.push_back(p2);
                break;
            }
        }
        st.push_back(v[i]);
    }

    cout << st.size() << '\n';
}