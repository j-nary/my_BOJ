//BOJ_12851 숨바꼭질 2 [골드 4]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K; cin >> N >> K;

    q.push({N, 0});
    int ans = 0, cnt = 0;
    while(!q.empty()) {
        auto [cur, depth] = q.front();
        q.pop();
        
        if (cnt && depth > ans) break;
        if (cur == K) {
            if (!cnt) {
                ans = depth;
                cnt++;
            } else if (ans == depth) {
                cnt++;
            }
        }

        if (cur - 1 >= 0) {
            q.push({cur - 1, depth + 1});
        }
        if (cur < K && cur + 1 <= 100000) {
            q.push({cur + 1, depth + 1});
        }
        if (cur < K && cur * 2 <= 100000) {
            q.push({cur * 2, depth + 1});
        }
    }

    cout << ans << '\n' << cnt << '\n';
}