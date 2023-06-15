//BOJ_2150 Strongly Connected Component [플래티넘 5]
#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

vector<int> adj[10004];
int dfsn[10004];
int cnt, SN;
bool finished[10004];   //SCC 분리 완료 -> true
stack<int> st;
vector<vector<int>> SCC;    //SCC 저장

int DFS(int cur) {
    dfsn[cur] = ++cnt;
    st.push(cur);

    //자식들의 결과나 dfsn 중 가장 작은 번호를 res에 저장
    int res = dfsn[cur];
    for (int i = 0; i < adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (dfsn[nxt] == 0)   // 방문하지 않는 경우
            res = min(res, DFS(nxt));
        else if (!finished[nxt])    // 방문O, SCC가 아닌 경우
            res = min(res, dfsn[nxt]);
    }

    // 자신의 자손들이 도달 가능한 제일 높은 정점이 자신일 경우 SCC 추출
    if (res == dfsn[cur]) {
        vector<int> curSCC;
        // stack에서 자신이 나올 때까지 pop
        while(1) {
            int t = st.top();
            st.pop();

            curSCC.push_back(t);
            finished[t] = true;
            if (t == cur) break;
        }

        sort(curSCC.begin(), curSCC.end());
        SCC.push_back(curSCC);
        SN++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int V, E; cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= V; i++) {
        if (dfsn[i] == 0) DFS(i);
    }
    sort(SCC.begin(), SCC.end());

    cout << SN << '\n';
    for (int i = 0; i < SCC.size(); i++) {
        for (int j = 0; j < SCC[i].size(); j++) {
            cout << SCC[i][j] << " ";
        }
        cout << "-1\n";
    }
}