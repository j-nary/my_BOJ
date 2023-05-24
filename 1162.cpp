//BOJ_1162 도로포장 [골드 1]
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

# define INF 1e15
using namespace std;
typedef long long ll;

int N, M, K;
vector<pair<int, int> > doro[10004];
ll dp[10004][21];  //dp[i][j] : 1~i 노드까지 j번 포장하는 최소 비용
priority_queue<pair<ll, pair<int, int> > > pq;   //비용, 노드, 포장 횟수

void dijkstra () {
    pq.push(make_pair(0, make_pair(1, 0)));
    dp[1][0] = 0;

    while(!pq.empty()) {
        int cur = pq.top().second.first;
        int cnt = pq.top().second.second;
        ll weight = -pq.top().first;
        pq.pop();

        if (dp[cur][cnt] < weight) continue;

        for (int i = 0; i < doro[cur].size(); i++) {
            int nxt = doro[cur][i].first;
            ll nxt_w = doro[cur][i].second + weight;

            // 도로 포장하는 경우
            if (cnt + 1 <= K && weight < dp[nxt][cnt + 1]) {
                dp[nxt][cnt + 1] = weight;
                pq.push(make_pair(-weight, make_pair(nxt, cnt + 1)));
            }

            // 도로 포장하지 않는 경우
            if (nxt_w < dp[nxt][cnt]) {
                dp[nxt][cnt] = nxt_w;
                pq.push(make_pair(-nxt_w, make_pair(nxt, cnt)));
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        doro[u].push_back(make_pair(v, w));
        doro[v].push_back(make_pair(u, w));
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = INF;
        }
    }
    dijkstra();

    ll ans = INF;
    for (int i = 0; i <= K; i++)
        ans = min(ans, dp[N][i]);
    cout << ans << '\n';
}