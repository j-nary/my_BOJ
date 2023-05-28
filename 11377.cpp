//BOJ_11377 열혈강호 3 [플래티넘 3]
//Bipartite Matching으로 풀기
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> v[2003];
bool chk[2003];
int A[2003], B[2003];

//A그룹에서 B그룹으로 가는 증가경로 찾기
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

    int N, M, K; cin >> N >> M >> K;
    int cnt;
    for (int i = 1; i <= N; i++) {
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int input; cin >> input;
            v[i].push_back(input);
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        memset(chk, false, sizeof(chk));
        if (dfs(i)) ans++;
    }

    //이분매칭 한 번 더
    cnt = 0;
    for (int i = 1; i <= N; i++) {
        memset(chk, false, sizeof(chk));
        if (dfs(i)) {
            ans++;
            cnt++;
        }
        if (cnt == K) break;
    }
    cout << ans << '\n';
}