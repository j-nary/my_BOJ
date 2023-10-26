//BOJ_16397 탈출 [골드 4]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

bool chk[100005];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, T, G; cin >> N >> T >> G;
    queue<pair<int, int>> q;
    q.push({N, 0});
    chk[N] = true;
    while(!q.empty()) {
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();
        // cout << d << " : " << cur << '\n';
        if (cur > 99999 || d > T) continue;
        if (cur == G) {
            cout << d << '\n';
            return 0;
        }

        //A버튼
        if (!chk[cur + 1]) {
            q.push({cur + 1, d + 1});
            // cout << d+1 << ".A : " << cur + 1 << '\n';
            chk[cur + 1] = true;
        }
        //B버튼
        int tmp = cur * 2;
        if (tmp > 99999) continue;
        int ten = 100000;
        while(1) {
            if (!tmp) break;
            if (tmp / ten) {
                tmp -= ten;
                break;
            } else {
                ten /= 10;
            }
        }
        if (!chk[tmp]) {
            q.push({tmp, d + 1});
            // cout << d+1 << ".B : " << tmp << '\n';
            chk[tmp] = true;
        }
    }

    cout << "ANG\n";
}