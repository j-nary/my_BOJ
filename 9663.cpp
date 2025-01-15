//BOJ_9663 N-Queen [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, ans;
int loc[20];

void backtracking(int depth) {
    if (depth == N) { ans++; return; }

    for (int i = 0; i < N; i++) {
        loc[depth] = i;
        bool flag = true;
        for (int j = 0; j < depth; j++) {
            if (loc[depth] == loc[j] || abs(loc[depth] - loc[j]) == depth - j) {
                flag = false;
                break;
            }
        }
        if (flag) backtracking(depth + 1);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    backtracking(0);
    cout << ans << '\n';
}
