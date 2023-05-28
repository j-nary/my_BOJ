//BOJ_2188 축사 배정 [플래티넘 4]
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> so[202];
bool chk[202];
int A[202], B[202];     //매칭된 상대 그룹 정점 번호

bool dfs(int idx) {
    chk[idx] = true;

    for (int k = 0; k < so[idx].size(); k++) {
        int mat = so[idx][k];
        //반대편 매칭 X or 매칭 되어있지만 원래 매칭되어있던 정점을 다른 정점과 매칭 가능
        if (!B[mat] || !chk[B[mat]] && dfs(B[mat])) {
            A[idx] = mat;
            B[mat] = idx;
            return true;
        }
    }

    //매칭 실패
    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int cnt; cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int input; cin >> input;
            so[i].push_back(input);
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