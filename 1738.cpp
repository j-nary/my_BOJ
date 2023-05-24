//BOJ_1738 골목길 [골드 2]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> gil[102];  // gil[u] = {v, w}
long long PV[102];    //prev 이전 노드 저장
int BF[102];    //Bellman-Ford 가중치 갱신 값 저장
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        gil[u].push_back({v, -w});
    }

    //Bellman-Ford
    for (int i = 0; i < gil[1].size(); i++) {
        int nxt = gil[1][i].first;
        int wgt = gil[1][i].second;
        BF[nxt] = wgt;
        PV[nxt] = 1;
    }

    for (int k = 0; k < n-1; k++) {
        int flag = 0;   // 갱신되는 거리가 있는지 체크
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < gil[i].size(); j++) {
                int nxt = gil[i][j].first;
                int wgt = gil[i][j].second;
                if (BF[nxt] > (long long)BF[i] + wgt) {
                    flag = 1;
                    BF[nxt] = (long long)BF[i] + wgt;
                    PV[nxt] = i;
                }
            }
        }
        if (!flag) break;
    }

    int flag = 0;
    int cur = n, prv;
    while(1) {
        prv = PV[cur];
        int idx = 0;
        for (int i = 0; i < gil[prv].size(); i++) {
            if (gil[prv][i].first == cur) {
                idx = i;
            }
        }
        if (BF[cur] > BF[prv] + (long long)gil[prv][idx].second) {
            cout << "-1\n";
            return 0;
        }
        cur = prv;
        if (cur == 1) break;
    }

    vector<int> ans;
    cur = n;
    while(1) {
        ans.push_back(cur);
        if (cur == 1) break;
        cur = PV[cur];
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}