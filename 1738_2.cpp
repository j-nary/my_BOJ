//BOJ_1738 골목길 [골드 2]
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define INF 1e15
using namespace std;

int n, m;
vector<pair<int, int>> gil[102];  // gil[u] = {v, w}
vector<pair<int, int>> rvs[102];  // reverse gill
bool chk[102];        //bfs를 위한 chk
bool chk1[102];       //true면 1번부터 있는 경로
bool chk2[102];       //true면 n번부터 있는 경로
long long PV[102];    //prev 이전 노드 저장
long long BF[102];    //Bellman-Ford 가중치 갱신 값 저장

void bfs() {
    //1번부터 진행되는 경로
    queue<int> q;
    q.push(1);
    chk1[1] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        chk[cur] = 1;

        for (int i = 0; i < gil[cur].size(); i++) {
            int nxt = gil[cur][i].first;
            if (chk[nxt]) continue;
            chk1[nxt] = true;
            q.push(nxt);
        }
    }

    //n번부터 진행되는 경로
    q.push(n);
    memset(chk, 0, sizeof(chk));
    chk2[n] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        chk[cur] = 1;
    
        for (int i = 0; i < rvs[cur].size(); i++) {
            int nxt = rvs[cur][i].first;
            if (chk[nxt]) continue;
            chk2[nxt] = true;
            q.push(nxt);
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        gil[u].push_back({v, -w});
        rvs[v].push_back({u, -w});
    }
    //경로가 아닌 노드 삭제
    bfs();
    //Bellman-Ford
    for (int i = 2; i <= n; i++) {
        BF[i] = INF;
    }

    for (int k = 0; k < n; k++) {
        int flag = 0;   // 갱신되는 거리가 있는지 체크
        for (int i = 1; i <= n; i++) {
            if (BF[i] == INF) continue;
            for (int j = 0; j < gil[i].size(); j++) {
                int nxt = gil[i][j].first;
                if (!chk1[nxt] || !chk2[nxt]) continue; 
                int wgt = gil[i][j].second;
                if (BF[nxt] > BF[i] + wgt) {
                    if (k == n -1) {
                        cout << -1 << '\n';
                        return 0;
                    }
                    flag = 1;
                    BF[nxt] = BF[i] + wgt;
                    PV[nxt] = i;
                }
            }
        }
        if (!flag) break;
    }

    vector<int> ans;
    int cur = n;
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
