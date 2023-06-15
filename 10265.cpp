//SCC + Knapsack
//BOJ_10265 MT [플래티넘 4]
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<int> together[1003];
int outDegree[1003];
int dfsn[1003], sn[1003];
bool finished[1003];
stack<int> st;
int cnt[1003], SN, GN;
int cntt[1003], head[1003], dp[1003][1003];
int num;

int dfs(int cur) {
    dfsn[cur] = ++num;
    st.push(cur);

    int res = dfsn[cur];
    for (int i = 0; i < together[cur].size(); i++) {
        int nxt = together[cur][i];
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
            cnt[SN]++;
            finished[t] = true;
            if (t == cur) break;
        }
        cntt[GN] += cnt[SN];
        head[GN] = cnt[SN];
        SN++;
        // sort(curSCC.begin(), curSCC.end());
        // SCC.push_back(curSCC);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, k; cin >> n >> k;
    int input;
    for (int i = 1; i <= n; i++) {
        cin >> input;
        together[input].push_back(i);
        outDegree[input]++;
    }

    for (int i = 1; i <= n; i++) {
        if (outDegree[i] >= 2 && dfsn[i] == 0) {
            GN++;
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (outDegree[i] >= 1 && dfsn[i] == 0) {
            GN++;
            dfs(i);
        }
    }

    for (int j = 1; j <= SN; j++) {
        for (int w = head[j]; w <= cntt[j] && w <= k; w++) {
            for (int i = 1; i <= k; i++) {
                if (i < w)
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
                else
                    dp[i][j] = max(dp[i][j], max(dp[i][j-1], dp[i-w][j-1] + w));
            }
        }
    }

    cout << dp[k][GN] << '\n';
}