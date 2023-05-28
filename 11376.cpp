//BOJ_11376 열혈강호 2 [플래티넘 4]
//Bipartite Matching으로 풀기
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> v[2003];
bool chk[2003];
int A[2003], B[2003];

bool dfs(int idx) {
    chk[idx] = true;

    for (int i = 0; i < v[idx].size(); i++) {
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

    int N, M; cin >> N >> M;
    N *= 2;
    for (int i = 1; i <= N; i += 2) {
        int cnt; cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int input; cin >> input;
            v[i++].push_back(input);
            v[i--].push_back(input);
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] == 0) {
            memset(chk, false, sizeof(chk));
            if (dfs(i)) ans++;
        }
    }

    cout << ans << '\n';
}