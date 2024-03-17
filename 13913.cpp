//BOJ_13913 숨바꼭질 4 [골드 4]
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
        cout << K << '\n';
        return 0;
    } else if (N > K) {
        cout << N - K << '\n';
        for (int i = N; i >= K; i--) {
            cout << i << " ";
        }
        cout << '\n';
        return 0;
    }
    queue<pair<int, vector<int>>> q;
    vector<int> v;
    v.push_back(N);
    q.push({N, v});
    while(!q.empty()) {
        int cur = q.front().first;
        v = q.front().second;
        q.pop();

        if (cur + 1 <= 100000 && !chk[cur + 1]) {
            if (cur + 1 == K) {
                cout << v.size() << '\n';
                for (int i = 0; i < v.size(); i++) {
                    cout << v[i] << ' ';
                }
                cout << cur + 1 << '\n';
                break;
            }
            chk[cur + 1] = true;
            v.push_back(cur + 1);
            q.push({cur + 1, v});
            v.pop_back();
        }

        if (cur - 1 >= 0 && !chk[cur - 1]) {
            if (cur - 1 == K) {
                cout << v.size() << '\n';
                for (int i = 0; i < v.size(); i++) {
                    cout << v[i] << ' ';
                }
                cout << cur - 1 << '\n';
                break;
            }
            chk[cur - 1] = true;
            v.push_back(cur - 1);
            q.push({cur - 1, v});
            v.pop_back();
        }

        if (cur * 2 <= 100000 &&  !chk[cur * 2]) {
            if (cur * 2 == K) {
                cout << v.size() << '\n';
                for (int i = 0; i < v.size(); i++) {
                    cout << v[i] << ' ';
                }
                cout << cur * 2 << '\n';
                break;
            }
            chk[cur * 2] = true;
            v.push_back(cur * 2);
            q.push({cur * 2, v});
            v.pop_back();
        }
    }
}