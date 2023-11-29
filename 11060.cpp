//BOJ_11060 점프 점프 [실버 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int jump[1003];
bool chk[1003];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> jump[i];
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    chk[0] = true;
    while(!q.empty()) {
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();

        if (cur == N - 1) {
            cout << d << '\n';
            return 0;
        }

        for (int i = 1; i <= jump[cur]; i++) {
            int tmp = cur - i;
            if (tmp > 0 && !chk[tmp]) {
                q.push({tmp, d + 1});
                chk[tmp] = true;
            }
            tmp = cur + i;
            if (tmp < N && !chk[tmp]) {
                q.push({tmp, d + 1});
                chk[tmp] = true;
            }
        }
    }

    cout << -1 << '\n';
}