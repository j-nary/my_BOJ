//BOJ_1039 교환 [골드 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

bool chk[11][1000006];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string N; int K;
    cin >> N >> K;
    queue<pair<string, int>> q;
    q.push({N, 0});
    int ans = -1;
    while(!q.empty()) {
        string cur = q.front().first;
        int dep = q.front().second;
        q.pop();

        if (dep == K) {
            ans = max(ans, stoi(cur));
            continue;
        }

        for (int i = 0; i < cur.size(); i++) {
            for (int j = i + 1; j < cur.size(); j++) {
                if (i == 0 && cur[j] == '0') continue;
                swap(cur[i], cur[j]);
                if (!chk[dep + 1][stoi(cur)]){
                    chk[dep + 1][stoi(cur)] = true;
                    q.push({cur, dep + 1});
                }
                swap(cur[i], cur[j]);
            }
        }
    }
    cout << ans << '\n';
}

// 436659
// 936654
// 966354