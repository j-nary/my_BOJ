//BOJ_13549 숨바꼭질 3 [골드 5]

#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

bool chk[100005];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    if (N == K) {
        cout << "0" << '\n';
        return 0;
    } else if (N > K) {
        cout << N - K << '\n';
        return 0;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, N});
    chk[N] = true;

    while(!pq.empty()) {
        int cur = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        int tmp = cur;
        for (int i = 0; ; i++) {
            tmp *= 2;
            if (tmp == 0 || tmp > 100004 || tmp > K * 2) break;
            if (chk[tmp]) continue;
            chk[tmp] = true;
            if (tmp == K) {
                cout << d << '\n';
                return 0;
            }
            pq.push({d, tmp});
        }

        if (cur + 1 <= 100000 && !chk[cur + 1]) {
            if (cur + 1 == K) {
                cout << d + 1 << '\n';
                break;
            }
            chk[cur + 1] = true;
            pq.push({d + 1, cur + 1});
        }

        if (cur - 1 >= 0 && !chk[cur - 1]) {
            if (cur - 1 == K) {
                cout << d + 1 << '\n';
                break;
            }
            chk[cur - 1] = true;
            pq.push({d + 1, cur - 1});
        }

    }
}