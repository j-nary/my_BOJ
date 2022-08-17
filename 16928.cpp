#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool isVis[110];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector<pair<int, int>> v;

    int N, M; cin >> N >> M;
    for (int i = 0; i < N + M; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    queue<pair<int, int>> q;
    q.push({1, 0});
    isVis[1] = true;
    while (!q.empty()) {
        auto [num, dis] = q.front();
        // cout << num << ", " << dis << endl;
        q.pop();

        if (num == 100) {
            cout << dis << '\n';
            return 0;
        }

        for (int j = 1; j <= 6; j++) {
            int flag = 0;
            for (int i = 0; i < N + M; i++) {
                if (num + j == v[i].first) {
                    if (isVis[v[i].second] == false) {
                        q.push({v[i].second, dis + 1});
                        isVis[v[i].second] = true;
                    }
                    flag = 1;
                    break;
                }
            }
            if (flag == 0 && isVis[num + j] == false) {
                q.push({num + j, dis + 1});
                isVis[num + j] = true;
            }
        }
    }

}