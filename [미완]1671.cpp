//BOJ_1671 상어의 저녁식사 [플래티넘 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct shark {
    int sz, spd, iq;    //크기, 속도, 지능
    bool operator<=(const shark &s) const {
        return sz <= s.sz && spd <= s.spd && iq <= s.iq;
    }
};
shark s[51];
vector<int> v[51];
bool chk[51];
int A[51], B[51];

bool dfs(int idx) {
    chk[idx] = true;

    int len = v[idx].size();
    for (int i = 0; i < len; i++) {
        int mat = v[idx][i];
        if (!B[mat] || !chk[B[mat]] && dfs(B[mat])) {
            A[idx] = mat;
            B[mat] = idx;
            return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int a, b, c; cin >> a >> b >> c;
        s[i] = {a, b, c};
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (s[i] < s[j]) {
                v[i].push_back(j);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            memset(chk, false, sizeof(chk));
            if (dfs(i)) ans++;
        }
    }
    cout << N - ans << '\n';
}