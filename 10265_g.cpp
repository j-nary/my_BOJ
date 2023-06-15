#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;

int N, K, a, num, SN, GN;
stack<int> st;
vector<vector<int>> adj, nadj;
int sn[1001], cnt[1001], dfsn[1001], fin[1001], outd[1001];
int cntt[1001], head[1001], dp[1001][1001];

int dfs(int cur) {
    dfsn[cur] = ++num;
    st.push(cur);

    int ret = dfsn[cur];
    for (auto next : adj[cur]) {
        if (dfsn[next] == 0) ret = min(ret, dfs(next));
        else if (fin[next] == 0) ret = min(ret, dfsn[next]);
    }

    if (ret == dfsn[cur]) {
        SN++;
        while(1) {
            int val = st.top(); st.pop();
            sn[val] = SN;
            cnt[SN] ++;
            fin[val] = 1;
            if (val == cur) break;
        }
        cntt[GN] += cnt[SN];
        head[GN] = cnt[SN];
    }
    return ret;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    adj.resize(N+1);
    for (int i =1; i <= N; i++) {
        cin >> a;
        adj[a].push_back(i);
        outd[a]++;
    }

    for (int i =1; i <= N; i++) {
        if (outd[i] >= 2 && dfsn[i] == 0){
            GN++;
            dfs(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (outd[i] >= 1 && dfsn[i] == 0) {
            GN++;
            dfs(i);
        }
    }

    for (int j = 1; j <= GN; j++) {
        for (int w = head[j]; w <= cntt[j] && w <= K; w++) {
            for (int i = 1; i <= K: i++){
                if (i < w) {
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }
                else {
                    dp[i][j] = max(dp[i][j], max(dp[i][j-1], dp[i-w][j-1] + w));
                }
            }
        }
    }

    cout << dp[K][GN];
}