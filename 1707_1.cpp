#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int bpg[20004];
bool check[20004];
int flag, vtx, edg;
queue<pair<int, int>> q;
vector<pair<int, int>> v;

void bfs() {
    while(!q.empty()) {
    auto [dt1, dt2] = q.front();
    q.pop();

    if (edg == 1) flag = 0;
    if (bpg[dt1] == bpg[dt2]) {
        flag = 1;
        break;
    }  
    for (int i = 0; i < edg; i++) {
        if (check[i] == true) continue;

        if (dt1 == v[i].first && dt2 == v[i].second) {
            check[i] = true;
            continue;
        }
        if (v[i].first == dt1) {
            bpg[v[i].second] = bpg[dt1] * (-1);
            q.push({v[i].first, v[i].second});
            check[i] = true;
            flag = 0;

        }
        if (v[i].second == dt1) {
            bpg[v[i].first] = bpg[dt1] * (-1);
            q.push({v[i].first, v[i].second});
            check[i] = true;
            flag = 0;
        }
        if (v[i].first == dt2) {
            bpg[v[i].second] = bpg[dt2] * (-1);
            q.push({v[i].first, v[i].second});
            check[i] = true;
            flag = 0;
        }
        if (v[i].second == dt2) {
            bpg[v[i].first] = bpg[dt2] * (-1);
            q.push({v[i].first, v[i].second});
            check[i] = true;
            flag = 0;
        }

    }
}
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        memset(bpg, 0, sizeof(bpg));
        memset(check, false, sizeof(check));
        v.clear();

        flag = 1;
        cin >> vtx >> edg;

        for (int i = 0; i < edg; i++) {
            int dt1, dt2;
            cin >> dt1 >> dt2;
            if (dt1 >= dt2)
                v.push_back({dt2, dt1});
            else
                v.push_back({dt1, dt2});        
        }
        sort(v.begin(), v.end());

        bpg[v[0].first] = 1;   //red
        bpg[v[0].second] = -1;   //blue
        q.push({v[0].first, v[0].second});
        check[0] = true;
        bfs();

        for (int i = 0; i < edg; i++) {
            if (check[i] == false) {
                check[i] = true;
                q.push({v[i].first, v[i].second});
                bpg[v[i].first] = 1;
                bpg[v[i].second] = -1;
                bfs();
            }
        }
        if (flag == 1)  cout << "NO" << endl;
        else            cout << "YES" << endl;
    }
}
