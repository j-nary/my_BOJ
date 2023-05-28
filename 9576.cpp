//BOJ_9576 책 나눠주기 [골드 2]
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[1003];
bool chk[1003];
int A[1003], B[1003];   //A는 학생, B는 책

bool dfs(int idx) {
    chk[idx] = true;

    for (int k = 0; k < v[idx].size(); k++) {
        int mat = v[idx][k];
        if (!B[mat] || !chk[B[mat]] && dfs(B[mat])) {
            A[idx] = mat;
            B[mat] = idx;
            return true;
        }
    }
    
    return false;
}
void test_case() {
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int a, b; cin >> a >> b;
        for (int k = a; k <= b; k++) {
            v[i].push_back(k);
        }
    }

    int ans = 0;
    for (int i = 1; i <= M; i++) {
        if (A[i] == 0) {
            memset(chk, false, sizeof(chk));
            if (dfs(i)) ans++;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int TC; cin >> TC;
    while(TC--) {
        for (int i = 0; i < 1003; i++) {
            v[i].clear();
            A[i] = 0;
            B[i] = 0;
        }
        test_case();
    }
}