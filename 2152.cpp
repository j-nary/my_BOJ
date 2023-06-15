//BOJ_2152 여행 계획 세우기 [플래티넘 3]
//문제해결 기말고사 대비 연습
#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <set>
#include <queue>

using namespace std;

int N, M, S, T; 
vector<int> adj[10004];

//SCC
int dfsn[10004], cnt;
bool finished[10004];
int snCnt[10004], sn[10004], SN = 1;      //snCnt[i] : i번째 SCC의 노드 개수
int snS, snT;   //S와 T의 SCC 번호
stack<int> st;

//topological sort
set<int> sst[10004];
int inDegree[10004];
int dp[10004];

int DFS(int cur) {
    dfsn[cur] = ++cnt;
    st.push(cur);

    int res = dfsn[cur];
    for (int i = 0; i < adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (!dfsn[nxt])
            res = min(res, DFS(nxt));
        else if (!finished[nxt])
            res = min(res, dfsn[nxt]);
    }

    if (res == dfsn[cur]) {
        int curCnt = 0;
        while(1) {
            int t = st.top(); st.pop();
            curCnt++;
            finished[t] = true;
            sn[t] = SN;
            if (t == S) snS = SN;
            if (t == T) snT = SN;
            if (t == cur) break;
        }
        snCnt[SN++] = curCnt;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> M >> S >> T;
    //N : 도시 개수, M : 비행로 개수, S : 시작 도시, T : 도착 도시
    //S번에서 T번으로 여행할 때 최대로 방문할 수 있는 도시의 개수
    for (int i = 0; i < M; i++) {
        int A, B; cin >> A >> B;
        adj[A].push_back(B);
    }

    for (int i = 1; i <= N; i++) {
        if (dfsn[i] == 0) DFS(i);
    }
    SN--;

    //같은 SCC에 있다면
    if (snS == snT) {
        cout << snCnt[snS] << '\n';
        return 0;
    }

    //SCC 그래프 조직
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int nxt = adj[i][j];
            if (sn[nxt] != sn[i]) {
                sst[sn[i]].insert(sn[nxt]);
            }
        }
    }

    //위상정렬
    dp[snS] = snCnt[snS];
    for (int i = snS; i >= snT; i--) {
        if (dp[i] == 0) continue;
        for (int nxt : sst[i]) {
            dp[nxt] = max(dp[nxt], dp[i] + snCnt[nxt]);
        }
    }
    cout << dp[snT] << '\n';
}