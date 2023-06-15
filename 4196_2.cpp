//BOJ_4196 도미노 [플래티넘 4]
//문제해결 기말고사 대비 연습
#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

vector<int> adj[100005];
int dfsn[100005], sn[100005];
int cnt, SN;
stack<int> st;
bool finished[100005];
// vector<vector<int>> SCC;

int DFS(int cur) {
    dfsn[cur] = ++cnt;
    st.push(cur);

    int res = dfsn[cur];
    for (int i = 0; i < adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (dfsn[nxt] == 0)
            res = min(res, DFS(nxt));
        else if (!finished[nxt]) {
            res = min(res, dfsn[nxt]);
        }
    }

    if (res == dfsn[cur]) {
        vector<int> curSCC;
        while(1) {
            int t = st.top(); st.pop();
            // curSCC.push_back(t);
            finished[t] = true;
            sn[t] = SN;
            if (t == cur) break;
        }

        // sort(curSCC.begin(), curSCC.end());
        // SCC.push_back(curSCC);
        SN++;
    }

    return res;
}
void test_case() {
    int N, M; cin >> N >> M;

    //초기화
    cnt = SN = 0;
    for (int i = 0; i <= N; i++) {
        adj[i].clear();
        dfsn[i] = 0;
        finished[i] = false;
        sn[i] = 0;
    }

    //입력 받기
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }

    for (int i =1; i <= N; i++) {
        if (dfsn[i] == 0) DFS(i);
    }

    for (int i = 0; i <= SN; i++) {
        finished[i] = false;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int nxt = adj[i][j];
            if (sn[nxt] != sn[i]) {
                finished[sn[nxt]] = true;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < SN; i++) {
        if (!finished[i]) ans++;
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