//BOJ_4196 도미노 [플래티넘 4]
#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

vector<int> adj[100005];
int dfsn[100005];
bool finished[100005];
stack<int> st;
int sn[100005];
int cnt, SN;
// vector<vector<int>> SCC;
int inDegree[100005];

int dfs(int cur) {
    dfsn[cur] = ++cnt;
    st.push(cur);

    int res = dfsn[cur];
    for (int i = 0; i < adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (dfsn[nxt] == 0)
            res = min(res, dfs(nxt));
        else if (!finished[nxt])
            res = min(res, dfsn[nxt]);
    }

    if (res == dfsn[cur]) {
        // vector<int> curSCC;
        while(1) {
            int t = st.top(); st.pop();
            // curSCC.push_back(t);
            sn[t] = SN;
            finished[t] = true;
            if (t == cur) break;
        }
        SN++;
        // sort(curSCC.begin(), curSCC.end());
        // SCC.push_back(curSCC);
    }

    return res;
}
void test_case() {
    int N, M; cin >> N >> M;

    // 초기화
    memset(dfsn, 0, sizeof(dfsn));
    memset(finished, false, sizeof(finished));
    memset(sn, 0, sizeof(sn));
    memset(inDegree, 0, sizeof(inDegree));
    cnt = 0; SN = 0;
    for (int i = 0; i <= N; i++) {
        adj[i].clear();
    }

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {
        if (dfsn[i] == 0) dfs(i);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int nxt = adj[i][j];
            if (sn[i] != sn[nxt]) inDegree[sn[nxt]]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < SN; i++) {
        if (!inDegree[i]) ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}