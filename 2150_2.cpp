//BOJ_2150 Strongly Connected Component [플래티넘 5]
//문제해결 기말고사 대비 연습
#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

vector<int> adj[10004];     //간선 정보 저장
int dfsn[10004], cnt;    //dfs 탐색 순서 저장
bool finished[10004];   //SCC 분리 완료 여부
stack<int> st;      //dfs돌면서 stack에 저장
vector<vector<int>> SCC;    //최종 SCC 저장
int sn[10004];      //SCC 분리 번호 저장
int SN;             //SCC 개수 저장

int DFS(int cur) {
    dfsn[cur] = ++cnt;
    st.push(cur);

    int res = dfsn[cur];
    for (int i = 0; i < adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (!dfsn[nxt])     //아직 방문하지 않은 자식이라면
            res = min(res, DFS(nxt));
        else if (!finished[nxt])    //방문했지만 SCC 분리가 안 된 자식이라면
            res = min(res, dfsn[nxt]);
    }

    if (res == dfsn[cur]) {
        vector<int> curSCC;
        while(1) {
            int t = st.top(); st.pop();
            finished[t] = true;
            sn[t] = SN;
            curSCC.push_back(t);
            if (t == cur) break;
        }

        sort(curSCC.begin(), curSCC.end());
        SN++;
        SCC.push_back(curSCC);
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int V, E; cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int A, B; cin >> A >> B;
        adj[A].push_back(B);
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