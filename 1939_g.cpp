#include <iostream>
#include <algorithm>
#include <queue>

#define endl '\n'
#define INF 1e9

using namespace std;

vector< vector< pair<int, int> > > edges;
vector<int> chk;

int dijkstra(int start, int end) {
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(INF, start));
    vector<int> dist(edges.size(), 0);
    dist[start] = INF;

    while (!pq.empty()) {
        int curV = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if (chk[curV]) { continue; }
        chk[curV] = 1;
        if (curV == end) { return dist[end]; }
        for (auto &i : edges[curV]) {
            int neiV = i.second;
            int neiCost = i.first;
            if (!chk[neiV] && dist[neiV] < min(weight, neiCost)) {
                dist[neiV] = min(weight, neiCost);
                pq.push(make_pair(dist[neiV], neiV));
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, ts, te;;
    
    cin >> N >> M;
    edges.resize(N + 1);
    chk.resize(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(c, b));
        edges[b].push_back(make_pair(c, a));
    }

    cin >> ts >> te;


    cout << dijkstra(ts, te) << endl;
    return 0;
}
