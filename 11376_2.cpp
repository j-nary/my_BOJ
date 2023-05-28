//BOJ_11376 열혈강호 2 [플래티넘 4]
//Bipartite Matching으로 풀기
//dfs를 두 번 돌리면 된대
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> v[1003];
bool chk[1003];
int A[1003], B[1003];

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
    for (int i = 1; i <= N; i++) {
        int cnt; cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int input; cin >> input;
            v[i].push_back(input);
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
            for (int j = 0; j < 2; j++) {
                memset(chk, false, sizeof(chk));
                if (dfs(i)) ans++;
            }
    }

    cout << ans << '\n';
}