//BOJ_13470 Programming Tutors [플래티넘 3]
//문제해결 기말고사 대비 연습
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<pair<int, int>> st;  //student
vector<pair<int, int>> tt;  //tutor
int dist[102][102];
vector<int> adj[102];
int A[102], B[102];
bool chk[102];

bool DFS(int idx) {
    chk[idx] = true;
    for (int i = 0; i < adj[idx].size(); i++) {
        int mat = adj[idx][i];
        if (B[mat]==-1 || !chk[B[mat]] && DFS(B[mat])) {
            A[idx] = mat;
            B[mat] = idx;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        st.push_back({x, y});
    }
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        tt.push_back({x, y});
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = abs(st[i].first - tt[j].first) + abs(st[i].second - tt[j].second);
        }
    }


    int left = 0, right = 1e9;
    int ans = 1e9;
    while(left <= right) {
        for (int i = 0; i <= N; i++) {
            adj[i].clear();
            A[i] = B[i] = -1;
        }
        int mid = (left + right) / 2;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][j] <= mid) adj[i].push_back(j);
            }
        }
        //이분매칭
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] == -1) {
                memset(chk, false, sizeof(chk));
                if (DFS(i)) cnt++;
            }
        }
        
        //이분탐색
        if (cnt >= N) {
            ans = min(ans, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << '\n';
}